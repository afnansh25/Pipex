/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:32:56 by codespace         #+#    #+#             */
/*   Updated: 2025/06/20 15:00:34 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	create_pipes(t_pipex *px)
{
    int	i;

    px->pipes = malloc(sizeof(int *) * (px->cmd_count - 1));
    if (!px->pipes)
        error_exit("pipe: malloc error");
    i = 0;
    while(i < px->cmd_count - 1)
    {
        px->pipes[i] = malloc(sizeof(int) * 2);
        if (!px->pipes[i])
            error_exit("pipe: malloc error");
        if (pipe(px->pipes[i]) == -1)
            error_exit("pipe: pipe error");
        i++;
    }
    px->pids = malloc(sizeof(pid_t) * px->cmd_count);
    if (!px->pids)  
        error_exit("pipe: malloc error");
}

void close_pipes(t_pipex *px)
{
    int i = 0;
    while (i < px->cmd_count - 1)
    {
        close(px->pipes[i][0]);
        close(px->pipes[i][1]);
        free(px->pipes[i]);
        i++;
    }
    free(px->pipes);
    px->pipes = NULL;
}

void	close_all(t_pipex *px)
{
    int	i;

    if (px->infile != -1)
        close(px->infile);
    if (px->outfile != -1)
        close(px->outfile);
    i = 0;
    if (px->pipes) 
    {
        while (i < px->cmd_count - 1) 
        {
            close(px->pipes[i][0]);
            close(px->pipes[i][1]);
            free(px->pipes[i]);
            i++;
        }
    }
    free(px->pipes);
    px->pipes = NULL;
}
