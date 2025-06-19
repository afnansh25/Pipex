/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:38:15 by codespace         #+#    #+#             */
/*   Updated: 2025/06/19 13:35:28 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int main(int ac, char **av, char **envp)
{
    t_pipex pipex;

    if (ac < 5)
        error_exit("Usage: ./pipex_bonus here_doc LIMITER cmd1 cmd2 ... outfile");
    init_pipex_struct(&pipex, ac, av, envp);
    if (pipex.here_doc)
        handle_here_doc(&pipex, av[2]);
    create_pipes(&pipex);
    fork_commands(&pipex);
    //close_pipes(&pipex);
    //wait_for_children(&pipex);
    free_all(&pipex);
    return (0);
}
