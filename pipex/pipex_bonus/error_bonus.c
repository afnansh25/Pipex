/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:33:08 by codespace         #+#    #+#             */
/*   Updated: 2025/06/19 13:17:58 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	error_exit(char *msg)
{
	perror(msg);
	exit(1);
}

void	free_arr(char **split)
{
    int	i;

    if (!split)
        return;
    i = 0;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}

void	free_all(t_pipex *px)
{
    //int	i;

    // if (px->pipes)
    // {
    //     i = 0;
    //     while (i < px->cmd_count - 1) 
    //     {
    //         free(px->pipes[i]);
    //         i++;
    //     }
    //     free(px->pipes);
    // }
    if (px->pids)
        free(px->pids);
    px->pids = NULL;
}

void	wait_for_children(t_pipex *px)
{
    int	i;
    int	status;

    i = 0;
    while(i < px->cmd_count)
    {
        if (waitpid(px->pids[i], &status, 0) == -1)
            error_exit("waitpid: wait failed");
        if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
            write(2, "A command failed\n", 17);
        i++;
    }
}
