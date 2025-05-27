/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:46:44 by codespace         #+#    #+#             */
/*   Updated: 2025/05/27 15:23:54 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	run_child1(int fd1, int *pipe_fd, char **args, char **envp)
{
	char	*cmd_path;

	dup2(fd1, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(fd1);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	cmd_path = get_cmd_path(args[0], envp);
	if (!cmd_path)
	{
		print_cmd_error(args[0]);
		free_path(args);
		exit(127);
	}
	execve(cmd_path, args, envp);
	perror("execve failed");
	free(cmd_path);
	free_path(args);
	exit(1);
}

void	run_child2(int fd2, int *pipe_fd, char **args, char **envp)
{
	char	*cmd_path;

	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(fd2, STDOUT_FILENO);
	close(fd2);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	cmd_path = get_cmd_path(args[0], envp);
	if (!cmd_path)
	{
		print_cmd_error(args[0]);
		free_path(args);
		exit(127);
	}
	execve(cmd_path, args, envp);
	perror("execve failed");
	free(cmd_path);
	free_path(args);
	exit(1);
}
