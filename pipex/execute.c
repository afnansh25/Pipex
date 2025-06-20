/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:46:44 by codespace         #+#    #+#             */
/*   Updated: 2025/06/20 19:26:19 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	run_child1(t_pipex *px, char **envp)
{
	char	*cmd_path;

	dup2(px->fd1, STDIN_FILENO);
	dup2(px->pipe_fd[1], STDOUT_FILENO);
	close(px->fd1);
	close(px->pipe_fd[0]);
	close(px->pipe_fd[1]);
	cmd_path = get_cmd_path(px->args1[0], envp);
	if (!cmd_path)
	{
		print_cmd_error(px->args1[0]);
		cleanup_and_exit(px, NULL, 127);
	}
	execve(cmd_path, px->args1, envp);
	perror("execve failed");
	free(cmd_path);
	free_path(px->args1);
	exit(1);
}

void	run_child2(t_pipex *px, char **envp)
{
	char	*cmd_path;

	dup2(px->pipe_fd[0], STDIN_FILENO);
	dup2(px->fd2, STDOUT_FILENO);
	close(px->fd2);
	close(px->pipe_fd[0]);
	close(px->pipe_fd[1]);
	cmd_path = get_cmd_path(px->args2[0], envp);
	if (!cmd_path)
	{
		print_cmd_error(px->args2[0]);
		cleanup_and_exit(px, NULL, 127);
	}
	execve(cmd_path, px->args2, envp);
	perror("execve failed");
	free(cmd_path);
	free_path(px->args2);
	exit(1);
}