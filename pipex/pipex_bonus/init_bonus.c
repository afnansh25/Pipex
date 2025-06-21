/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:47:16 by codespace         #+#    #+#             */
/*   Updated: 2025/06/21 09:00:33 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	check_here_doc(t_pipex *px)
{
	if (px->argc < 6)
        error_msg("Usage: ./pipex here_doc LIMITER cmd1 ... cmdN outfile");
	px->here_doc = 1;
}
void	init_pipex(t_pipex *px, int ac, char **av, char **envp)
{
	px->argc = ac;
	px->argv = av;
	px->envp = envp;
	px->here_doc = 0;
	px->infile = -1;
	px->outfile = -1;
	px->pipes = NULL;
	px->pids = NULL;
	px->cmd_count = ac - 3;
	px->cmd_start = 2;
}

void	init_pipex_struct(t_pipex *px, int ac, char **av, char **envp)
{
	init_pipex(px, ac, av, envp);
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		check_here_doc(px);
		px->cmd_count = ac - 4;
		px->cmd_start = 3;
	}
	else
	{
		px->infile = open(av[1], O_RDONLY);
		if (px->infile < 0)
			error_exit("open infile");
		px->outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (px->outfile < 0)
		{
			close(px->infile);
			error_exit("open outfile");
		}
	}
}

