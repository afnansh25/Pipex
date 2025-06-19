/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:47:16 by codespace         #+#    #+#             */
/*   Updated: 2025/06/19 14:10:37 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	check_here_doc(t_pipex *px)
{
	if (px->argc < 6)
	{
		write(2, "Usage: ./pipex here_doc LIMITER cmd1 ... cmdN outfile\n", 54);
		exit(EXIT_FAILURE);
	}
	px->here_doc = 1;
	// handle_here_doc(px, px->argv[2]);
}

void	init_pipex_struct(t_pipex *px, int ac, char **av, char **envp)
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
	px->cmd_start = 3;
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		check_here_doc(px);
		px->cmd_count = ac - 4;
	}
}
