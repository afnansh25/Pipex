/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:15:05 by codespace         #+#    #+#             */
/*   Updated: 2025/06/18 13:16:36 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char    *ft_strchr(const char *s, int c)
{
    size_t  i;
    unsigned const char *str;
    unsigned char   letter;

    i = 0;
    str = (unsigned const char *)s;
    letter = (unsigned char)c;
    while (str[i])
    {
        if (str[i] == letter)
            return (char *)(s + i);
        i++;
    }
    if (letter == '\0')
        return (char *)(s + i);
    return (NULL);
}

size_t  ft_strlcpy(char *dst, const char *src, size_t size)
{
    size_t srclen;
    size_t i;
    
    i = 0;
    srclen = ft_strlen(src);
    if (size == 0)
        return (srclen);
    while (i < (size -1) && src[i])
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (srclen);
}

char    *ft_strdup(const char *s)
{
    size_t  len;
    char    *dup;

    len = ft_strlen(s);
    dup = (char *)malloc(sizeof(char) * len + 1);
    if (!dup)
        return (NULL);
    ft_strlcpy(dup, s, len + 1);
    return (dup);
}

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
