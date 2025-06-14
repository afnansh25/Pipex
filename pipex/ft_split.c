/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashaheen <ashaheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 18:30:13 by ashaheen          #+#    #+#             */
/*   Updated: 2025/05/24 18:30:16 by ashaheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	count_words(char const *s, char c)
{
	size_t	in_word;
	size_t	count;
	size_t	i;

	in_word = 0;
	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && !in_word)
		{
			count++;
			in_word = 1;
		}
		else if (s[i] == c)
			in_word = 0;
		i++;
	}
	return (count);
}

void	*free_split(char **split, size_t k)
{
	size_t	i;

	if (!split)
		return (NULL);
	i = 0;
	while (i < k)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

char	**strsplit(char **split, char *s, char c)
{
	size_t	i;
	size_t	k;
	size_t	start;

	start = 0;
	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[start] == c && s[start])
			start++;
		i = start;
		while (s[i] != c && s[i])
			i++;
		if (i > start)
		{
			split[k] = ft_substr(s, start, i - start);
			if (!split[k])
				return (free_split(split, k));
			k++;
		}
		start = i;
	}
	split[k] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (s == NULL)
		return (NULL);
	split = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!split)
		return (NULL);
	split = strsplit(split, (char *)s, c);
	if (!split)
	{
		free(split);
		return (NULL);
	}
	return (split);
}
