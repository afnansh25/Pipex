/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:27:06 by codespace         #+#    #+#             */
/*   Updated: 2025/06/21 08:36:18 by codespace        ###   ########.fr       */
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

void	cleanup_and_exit(t_pipex *px, char *msg, int status)
{
	if (px->fd1 != -1)
		close(px->fd1);
	if (px->fd2 != -1)
		close(px->fd2);
	if (px->pipe_fd[0] != -1)
		close(px->pipe_fd[0]);
	if (px->pipe_fd[1] != -1)
		close(px->pipe_fd[1]);
	if (px->args1)
		free_path(px->args1);
	if (px->args2)
		free_path(px->args2);
	if (msg)
	{
		write(2, msg, ft_strlen(msg));
		write(2, "\n", 1);
	}
	exit(status);
}

