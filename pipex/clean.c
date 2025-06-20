/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:27:06 by codespace         #+#    #+#             */
/*   Updated: 2025/06/20 19:23:41 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_path(char **path)
{
	int	i;

	i = 0;
	if (!path)
		return;
	while (path[i])
	{
		free(path[i]);
		i++;
	}
	free(path);
}

void	close_fds(int fd1, int fd2, int *pipe_fd)
{
	close(fd1);
	close(fd2);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
}

void	cleanup_and_exit(t_pipex *px, char *err_msg, int errcode)
{
	if (px->fd1 > 0)
		close(px->fd1);
	if (px->fd2 > 0)
		close(px->fd2);
	if (px->pipe_fd[0] >= 0)
		close(px->pipe_fd[0]);
	if (px->pipe_fd[1] >= 0)
		close(px->pipe_fd[1]);
	free_path(px->args1);
	free_path(px->args2);
	if (err_msg)
		ft_putstr_fd(err_msg, 2);
	exit(errcode);
}
