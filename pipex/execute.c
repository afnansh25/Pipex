/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:46:44 by codespace         #+#    #+#             */
/*   Updated: 2025/06/22 08:32:20 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	run_child1(t_pipex *px, char **envp)
{
	char	*cmd_path;

	if (dup2(px->fd1, STDIN_FILENO) == -1 || dup2(px->pipe_fd[1], STDOUT_FILENO) == -1)
		cleanup_and_exit(px, "dup2 failed in child1", 1);
	close(px->fd1);
	close(px->pipe_fd[0]);
	close(px->pipe_fd[1]);
	cmd_path = get_cmd_path(px->args1[0], envp);
	if (!cmd_path)
		cleanup_and_exit(px, "command 1 not found", 127);
	execve(cmd_path, px->args1, envp);
	perror("execve failed");
	free(cmd_path);
	cleanup_and_exit(px, NULL, 1);
}

void	run_child2(t_pipex *px, char **envp)
{
	char	*cmd_path;

	if (dup2(px->pipe_fd[0], STDIN_FILENO) == -1 || dup2(px->fd2, STDOUT_FILENO) == -1)
		cleanup_and_exit(px, "dup2 failed in child2", 1);
	close(px->fd2);
	close(px->pipe_fd[0]);
	close(px->pipe_fd[1]);
	cmd_path = get_cmd_path(px->args2[0], envp);
	if (!cmd_path)
		cleanup_and_exit(px, "command 2 not found", 127);
	execve(cmd_path, px->args2, envp);
	perror("execve failed");
	free(cmd_path);
	cleanup_and_exit(px, NULL, 1);
}