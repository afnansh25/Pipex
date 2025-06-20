/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:48:19 by codespace         #+#    #+#             */
/*   Updated: 2025/06/20 19:26:00 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_pipex_struct(t_pipex *px)
{
	px->fd1 = -1;
	px->fd2 = -1;
	px->pipe_fd[0] = -1;
	px->pipe_fd[1] = -1;
	px->args1 = NULL;
	px->args2 = NULL;
}

void	init_pipex(t_pipex *px, char **av)
{
	init_pipex_struct(px);
	px->file1 = av[1];
	px->cmd1 = av[2];
	px->cmd2 = av[3];
	px->file2 = av[4];
	px->args1 = parse_cmd(px, px->cmd1);
	px->args2 = parse_cmd(px, px->cmd2);
	check_cmd(px->args1, "cmd1");
	check_cmd(px->args2, "cmd2");
	px->fd1 = open(px->file1, O_RDONLY);
	if (px->fd1 < 0)
	{
		free_path(px->args1);
		free_path(px->args2);
		error_exit("Error opening infile");
	}
	px->fd2 = open(px->file2, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (px->fd2 < 0)
	{
		free_path(px->args1);
		free_path(px->args2);
		error_exit("Error opening infile");
	}
}

void	execute_pipeline(t_pipex *px, char **envp)
{
	px->pid1 = fork();
	if (px->pid1 == 0)
		run_child1(px, envp);
	px->pid2 = fork();
	if (px->pid2 == 0)
		run_child2(px, envp);
}

void	cleanup_pipex(t_pipex *px)
{
	close(px->fd1);
	close(px->fd2);
	close(px->pipe_fd[0]);
	close(px->pipe_fd[1]);
	waitpid(px->pid1, NULL, 0);
	waitpid(px->pid2, NULL, 0);
	free_path(px->args1);
	free_path(px->args2);
}

void	pipex(t_pipex *px, char **envp)
{
	if (pipe(px->pipe_fd) == -1)
		error_exit("pipe failed");
	execute_pipeline(px, envp);
	cleanup_pipex(px);
}
