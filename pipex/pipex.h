/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 17:57:21 by ashaheen          #+#    #+#             */
/*   Updated: 2025/05/27 15:28:17 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>

typedef struct s_pipex
{
	int		fd1;
	int		fd2;
	int		pipe_fd[2];
	pid_t	pid1;
	pid_t	pid2;
	char	**args1;
	char	**args2;
}	t_pipex;

//split
char	**ft_split(char const *s, char c);

//str_utils
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
char    *ft_strjoin(char const *s1, char const *s2);
void	ft_putstr_fd(char *s, int fd);

//pipex
void	pipex(char *file1, char *file2, char *cmd1, char *cmd2, char **envp);
void	init_pipex(t_pipex *px, char *file1, char *file2, char *cmd1, char *cmd2);
void	init_fds(t_pipex *px);
void	execute_pipeline(t_pipex *px, char **envp);
void	cleanup_pipex(t_pipex *px);

//execute
void	run_child1(int fd1, int *pipe_fd, char **args, char **envp);
void	run_child2(int fd2, int *pipe_fd, char **args, char **envp);

//validate
void	validate_inputs(int ac, char **av);
void	check_cmd(char **cmd, char *label);

//error
void	print_cmd_error(char *cmd);
void	error_exit(char *msg);

//clean
void	free_path(char **path);
void	close_fds(int fd1, int fd2, int *pipe_fd);

//pars
char	**parse_cmd(char *cmd);

//path
char    *get_cmd_path(char *cmd, char **envp);


#endif