/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:32:36 by codespace         #+#    #+#             */
/*   Updated: 2025/06/18 13:16:03 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	**parse_cmd(const char *cmd)
{
    char    **cmd_array;
    
	if (!*cmd)
        return (NULL);
    cmd_array = ft_split(cmd, ' ');
	return (cmd_array);
}

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

char	*get_cmd_path(char *cmd, char **envp)
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
    free_arr(paths);
    return (full_path);
}
