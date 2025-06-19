/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:32:32 by codespace         #+#    #+#             */
/*   Updated: 2025/06/19 13:41:04 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	fork_commands(t_pipex *px)
{
	int	i;
	pid_t	pid;

	i = 0;
	while (i < px->cmd_count)
	{
		pid = fork();
		if (pid < 0)
			error_exit("fork: fork failed");
		if (pid == 0)
			run_child(px, i);
		px->pids[i] = pid;
		i++;
	}
	close_all(px);
	wait_for_children(px);
}

void	setup_io(t_pipex *px, int i)
{
	if (i == 0)
	{
		if (px->infile != -1)
			dup2(px->infile, STDIN_FILENO);
		if (px->pipes[i][WRITE_END] != -1)
			dup2(px->pipes[i][WRITE_END], STDOUT_FILENO);
	}
	else if (i == px->cmd_count - 1)
	{
		if (px->pipes[i - 1][READ_END] != -1)
			dup2(px->pipes[i - 1][READ_END], STDIN_FILENO);
		if (px->outfile != -1)
			dup2(px->outfile, STDOUT_FILENO);
	}
	else
	{
		dup2(px->pipes[i - 1][READ_END], STDIN_FILENO);
		dup2(px->pipes[i][WRITE_END], STDOUT_FILENO);
	}
}

static void	execute_cmd(t_pipex *px, int i)
{
	char	**cmd_args;
	char	*cmd_path;

	cmd_args = parse_cmd(px->argv[i + px->cmd_start]);
	cmd_path = get_cmd_path(cmd_args[0], px->envp);
	if (!cmd_path)
	{
		free_arr(cmd_args);
		error_exit("fork: command not found");
	}
	execve(cmd_path, cmd_args, px->envp);
	free(cmd_path);
	free_arr(cmd_args);
	error_exit("fork: execve failed");
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
	wait_for_children(px);
}
