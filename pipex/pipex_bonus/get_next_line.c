/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:31:14 by codespace         #+#    #+#             */
/*   Updated: 2025/06/20 13:28:32 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_read_to_buffer(int fd, char *buffer, char *leftover)
{
	char	*old_leftovers;
	int		read_bytes;

	if (!leftover)
		return (NULL);
	read_bytes = 1;
	while (!(ft_strchr(leftover, '\n') && read_bytes > 0))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free (leftover);
			return (NULL);
		}
		else if (read_bytes == 0)
			break ;
		buffer[read_bytes] = '\0';
		old_leftovers = leftover;
		leftover = ft_strjoin(leftover, buffer);
		free (old_leftovers);
		if (!leftover)
			return (NULL);
	}
	return (leftover);
}

char	*ft_extract_line(char *leftover)
{
	char	*line;
	size_t	i;

	if (!leftover || !*leftover)
		return (NULL);
	i = 0;
	while (leftover[i] != '\n' && leftover[i])
		i++;
	if (leftover[i] == '\n')
		i++;
	line = ft_substr(leftover, 0, i);
	return (line);
}

char	*ft_update_line(char *leftover)
{
	char	*new_leftover;
	size_t	i;

	i = 0;
	if (!leftover)
		return (NULL);
	while (leftover[i] != '\n' && leftover[i])
		i++;
	if (leftover[i] == '\n' && leftover[i])
		i++;
	new_leftover = ft_strdup(leftover + i);
	free (leftover);
	return (new_leftover);
}

char	*ft_free_leftover(char **leftover)
{
	free(*leftover);
	*leftover = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	if (!leftover)
		leftover = ft_strdup("");
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (ft_free_leftover(&leftover));
	leftover = ft_read_to_buffer(fd, buffer, leftover);
	free(buffer);
	if (!leftover)
		return (NULL);
	line = ft_extract_line(leftover);
	leftover = ft_update_line(leftover);
	if (!line || (leftover && !*leftover))
		ft_free_leftover(&leftover);
	return (line);
}