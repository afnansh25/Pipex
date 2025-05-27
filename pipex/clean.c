/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:27:06 by codespace         #+#    #+#             */
/*   Updated: 2025/05/27 15:27:12 by codespace        ###   ########.fr       */
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
