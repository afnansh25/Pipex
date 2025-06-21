/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 11:22:25 by codespace         #+#    #+#             */
/*   Updated: 2025/06/21 08:34:08 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char    *find_path_varible(char **envp)
{
    int i;

    i = 0;
    while (envp && envp[i])
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
    while (paths && paths[i])
    {
        tmp = ft_strjoin(paths[i], "/");
        if (!tmp)
            cleanup_and_exit(NULL, "Memory allocation failed", 1);
        full_path = ft_strjoin(tmp, cmd);
        free(tmp);
        if (!full_path)
            cleanup_and_exit(NULL, "Memory allocation failed", 1);
        if (access(full_path, X_OK) == 0)
            return(full_path);
        free(full_path);
        i++;
    }
    return (NULL);
}

char    *get_cmd_path(char *cmd, char **envp)
{
    char    **paths;
    char    *path_str;
    char    *full_path;

    if (!cmd || !cmd[0])
		return (NULL);
    if (ft_strchr(cmd, '/'))
    {
	    if (access(cmd, X_OK) == 0)
		    return (ft_strdup(cmd));
	    else
		    return (NULL);
    }
    path_str = find_path_varible(envp);
    if (!path_str)
        cleanup_and_exit(NULL, "PATH variable not found", 1);
    paths = ft_split(path_str, ':');
    if (!paths)
        cleanup_and_exit(NULL, "Memory allocation failed", 1);
    full_path = build_cmd_path(paths, cmd);
    free_path(paths);
    return (full_path);
}
