/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 11:22:25 by codespace         #+#    #+#             */
/*   Updated: 2025/05/25 11:51:21 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char    *find_path_varible(char **envp)
{
    int i;

    i = 0;
    while (envp[i])
    {
        if (ft_strncmp(envp[i], "PATH=", 5) == 0)
            return (envp[i] + 5);
        i++;
    }
    return (NULL);
}

char    *build_cmd_path(char **paths, char *cmd)
{
    int i;
    char    *tmp;
    char    *full_path;

    i = 0;
    while (paths[i])
    {
        tmp = ft_strjoin(paths[i], "/");
        full_path = ft_strjoin(tmp, cmd);
        free(tmp);
        if (access(full_path, X_OK) == 0)
            return(full_path);
        free(full_path);
        i++;
    }
    return (NULL);
}
void	free_path(char **arr)
{
	int	i;

    i = 0;
	while (arr[i])
    {
		free(arr[i]);
        i++;
    }
	free(arr);
}

char    *get_cmd_path(char *cmd, char **envp)
{
    char    **paths;
    char    *path_str;
    char    *full_path;

    path_str = find_path_varible(envp);
    if (!path_str)
        return (NULL);
    paths = ft_split(path_str, ':');
    if (!paths)
        return (NULL);
    full_path = build_cmd_path(paths, cmd);
    free_path(paths);
    return (full_path);
}
