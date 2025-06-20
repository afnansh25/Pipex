/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:00:00 by codespace         #+#    #+#             */
/*   Updated: 2025/06/20 17:50:22 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	read_heredoc_input(int write_fd, char *limiter)
{
	char *line;
	size_t len;

	len = ft_strlen(limiter);
	while (1)
	{
		write(1, "> ", 2);
		line = get_next_line(0);
		if (!line)
   			break ;	
		if (ft_strncmp(line, limiter, len) == 0 && line[len] == '\n')
		{
			free(line);
			break;
		}
		else
		{
			write (write_fd, line, ft_strlen(line));
			free (line);
		}
	}
	close(write_fd);
	exit(0);
}

void	handle_here_doc(t_pipex *px, char *limiter)
{
	int pipe_fd[2];
	int pid;
	
	pipe(pipe_fd);
	if (pipe_fd[0] < 0 || pipe_fd[1] < 0)
		error_exit("pipe");
	pid = fork();
	if (pid < 0)
 		error_exit("pipe");
	if (pid == 0)
	{
		close(pipe_fd[0]);
		read_heredoc_input(pipe_fd[1], limiter);
	}
	else
	{
		close(pipe_fd[1]);
		waitpid(pid, NULL, 0);
		px->infile = pipe_fd[0];
	}
}
