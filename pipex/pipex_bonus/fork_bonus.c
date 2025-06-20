/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:32:32 by codespace         #+#    #+#             */
/*   Updated: 2025/06/20 16:28:14 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	fork_commands(t_pipex *px)
{
	int	i;

	i = 0;
	while (i < px->cmd_count)
	{
		px->pids[i] = fork();
        if (px->pids[i] < 0)
            error_exit("fork failed");
        if (px->pids[i] == 0)
            run_child(px, i);
		i++;
	}
	i = 0;
	while (i < px->cmd_count - 1)
    {
        close(px->pipes[i][0]);
        close(px->pipes[i][1]);
		i++;
    }
	if (px->infile != -1) 
		close(px->infile);
    if (px->outfile != -1) 
		close(px->outfile);
	wait_for_children(px);
}

void setup_io(t_pipex *px, int i)
{
	if (i == 0)
	{
		if (px->infile != -1)
			dup2(px->infile, STDIN_FILENO);      // stdin ← infile (read from file or heredoc)
		dup2(px->pipes[i][1], STDOUT_FILENO);    // stdout → pipe write end
	}
	else if (i == px->cmd_count - 1)
	{
		dup2(px->pipes[i - 1][0], STDIN_FILENO); // stdin ← previous pipe's read end
		if (px->outfile != -1)
			dup2(px->outfile, STDOUT_FILENO);    // stdout → outfile
	}
	else
	{
		dup2(px->pipes[i - 1][0], STDIN_FILENO); // stdin ← previous pipe
		dup2(px->pipes[i][1], STDOUT_FILENO);    // stdout → next pipe
	}
}


void	execute_cmd(t_pipex *px, int i)
{
	char	**cmd_args;
	char	*cmd_path;

	cmd_args = parse_cmd(px->argv[i + px->cmd_start]);
	if (!cmd_args || !cmd_args[0] || cmd_args[0][0] == '\0')
	{
		free_arr(cmd_args);
		error_msg("fork: command not found");
	}
	cmd_path = get_cmd_path(cmd_args[0], px->envp);
	if (!cmd_path)
	{
		free_arr(cmd_args);
		error_msg("fork: command not found");
	}
	execve(cmd_path, cmd_args, px->envp);
	free(cmd_path);
	free_arr(cmd_args);
	error_msg("fork: execve failed");
}

void	run_child(t_pipex *px, int i)
{
	int j;

	j = 0;
	setup_io(px, i);
	while(j < px->cmd_count - 1)
	{
		close(px->pipes[j][0]);
        close(px->pipes[j][1]);
		j++;
	}
	if (px->infile != -1) 
		close(px->infile);
    if (px->outfile != -1) 
		close(px->outfile);
	execute_cmd(px, i);
}
