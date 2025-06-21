/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 08:33:51 by codespace         #+#    #+#             */
/*   Updated: 2025/06/21 08:34:13 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


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