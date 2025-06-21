/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:20:21 by codespace         #+#    #+#             */
/*   Updated: 2025/06/21 08:15:34 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	validate_inputs(int ac, char **av)
{
	if (ac != 5)
	{
		ft_putstr_fd("Usage: ./pipex file1 cmd1 cmd2 file2\n", 2);
		exit(1);
	}
	if (!av[1] || !av[1][0])
	{
		ft_putstr_fd("Error: infile is missing or empty\n", 2);
		exit(1);
	}
	if (!av[2] || !av[2][0])
	{
		ft_putstr_fd("Error: cmd1 is missing\n", 2);
		exit(1);
	}
	if (!av[3] || !av[3][0])
	{
		ft_putstr_fd("Error: cmd2 is missing\n", 2);
		exit(1);
	}
	if (!av[4] || !av[4][0])
	{
		ft_putstr_fd("Error: outfile is missing or empty\n", 2);
		exit(1);
	}
}

int	is_only_whitespace(const char *str)
{
	int	i;

	if (!str)
		return (1);
	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' &&
			str[i] != '\v' && str[i] != '\f' && str[i] != '\r')
			return (0);
		i++;
	}
	return (1);
}

char	**parse_cmd(t_pipex *px, char *cmd)
{
    char    **cmd_array;
    
	if (!cmd || is_only_whitespace(cmd))
        cleanup_and_exit(px, "pipex: invalid command", 1);
    cmd_array = ft_split(cmd, ' ');
	if(!cmd_array)
		cleanup_and_exit(px, "Memory allocation failed", 1);
	return (cmd_array);
}

void	check_cmd(char **cmd, char *label)
{
	if (!cmd || !cmd[0])
	{
		ft_putstr_fd("pipex: invalid ", 2);
		ft_putstr_fd(label, 2);
		ft_putstr_fd("\n", 2);
		exit(1);
	}
}

