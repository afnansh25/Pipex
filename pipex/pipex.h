/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 17:57:21 by ashaheen          #+#    #+#             */
/*   Updated: 2025/06/22 08:04:15 by codespace        ###   ########.fr       */
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
	char	*file1;
	char	*file2;
	char	*cmd1;
	char	*cmd2;
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

//str_utils2
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strdup(const char *s);

//pipex
void	pipex(t_pipex *px, char **envp);
void	init_pipex(t_pipex *px, char **av);
void	execute_pipeline(t_pipex *px, char **envp);

//execute
void	run_child1(t_pipex *px, char **envp);
void	run_child2(t_pipex *px, char **envp);

//validate
void	validate_inputs(int ac, char **av);
char	**parse_cmd(t_pipex *px, char *cmd);
void	check_cmd(char **cmd, char *label);

//clean
void	free_path(char **path);
void	cleanup_and_exit(t_pipex *px, char *err_msg, int errcode);

//path
char    *find_path_varible(char **envp);
char    *build_cmd_path(char **paths, char *cmd);
char    *get_cmd_path(char *cmd, char **envp);

#endif