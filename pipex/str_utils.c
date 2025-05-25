/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 18:29:56 by ashaheen          #+#    #+#             */
/*   Updated: 2025/05/25 11:25:05 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sstr;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		len = 0;
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	sstr = (char *)malloc(sizeof(char) * len + 1);
	if (!sstr)
		return (NULL);
	while (i < len)
	{
		sstr[i++] = s[start++];
	}
	sstr[i] = '\0';
	return ((char *)sstr);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *join;
    size_t  len1;
    size_t  len2;

    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);
    join = (char *)malloc(sizeof (char) * (len1 + len2 + 1));
    if (!join)
        return (NULL);
    len1 = 0;
    len2 = 0;
    while (s1[len1])
    {
        join[len1] = s1[len1];
        len1++;
    }
    while (s2[len2])
    {
        join[len1] = s2[len2];
        len1++;
        len2++;
    }
    join[len1] = '\0';
    return (join);
}
int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;
    
    i = 0;
    while (i < n)
    {
        if (s1[i] != s2[i])
            return ((unsigned char)s1[i] - (unsigned char)s2[i]);
        if (!s1[i] || !s2[i])
            break;
        i++;
    } 
    return (0);
}
