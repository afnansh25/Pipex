/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:40:10 by codespace         #+#    #+#             */
/*   Updated: 2025/06/15 16:08:28 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// char	**parse_cmd(char *cmd)
// {
//     char    **cmd_array;
    
// 	if (!*cmd)
//         return (NULL);
//     cmd_array = ft_split(cmd, ' ');
// 	return (cmd_array);
// }

// char	**parse_cmd(char *cmd)
// {
//     char	**args;
//     char	*tmp;
//     int		i;

//     if (!cmd || !*cmd)
//         return (NULL);
//     args = ft_split(cmd, ' ');
//     if (!args)
//         return (NULL);
//     i = 0;
//     while (args[i])
//     {
//         tmp = args[i];
//         args[i] = ft_substr(tmp, 0, ft_strlen(tmp));
//         free(tmp);
//         if (!args[i])
//         {
//             free_path(args);
//             return (NULL);
//         }
//         i++;
//     }
//     return (args);
// }