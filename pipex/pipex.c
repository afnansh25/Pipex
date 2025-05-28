/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:48:19 by codespace         #+#    #+#             */
/*   Updated: 2025/05/28 18:05:00 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_pipex(t_pipex *px, char **av)
{
	px->args1 = parse_cmd(px->cmd1);
	px->args2 = parse_cmd(px->cmd2);
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

void	init_fds(t_pipex *px)
{
	if (pipe(px->pipe_fd) == -1)
		error_exit("pipe failed");
}

void	execute_pipeline(t_pipex *px, char **envp)
{
	px->pid1 = fork();
	if (px->pid1 == 0)
		run_child1(px->fd1, px->pipe_fd, px->args1, envp);
	px->pid2 = fork();
	if (px->pid2 == 0)
		run_child2(px->fd2, px->pipe_fd, px->args2, envp);
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

void	pipex(t_pipex px, char **envp)
{
	init_fds(&px);
	execute_pipeline(&px, envp);
	cleanup_pipex(&px);
}
