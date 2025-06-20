/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:02:24 by codespace         #+#    #+#             */
/*   Updated: 2025/06/20 16:15:55 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>

# define BUFFER_SIZE 1024

typedef struct s_pipex
{
	int		argc;
	char	**argv;
	char	**envp;
	int		**pipes;
	int		here_doc;
	int		infile;
	int		outfile;
	int		cmd_count;
	int     cmd_start;
	pid_t	*pids;
}	t_pipex;

//init_bonus.c
void	init_pipex_struct(t_pipex *px, int ac, char **av, char **envp);
void	check_here_doc(t_pipex *px);

//here_doc_bonus.c
void	handle_here_doc(t_pipex *px, char *limiter);
void	read_heredoc_input(int write_fd, char *limiter);
size_t	ft_strlen(const char *s);

//pipe_bonus.c
void	create_pipes(t_pipex *px);
void	close_pipes(t_pipex *px);
void	close_all(t_pipex *px);

//fork_bonus.c
void	fork_commands(t_pipex *px);
void	run_child(t_pipex *px, int i);

//error_bonus.c
void	error_msg(char *msg);
void	error_exit(char *msg);
void	free_arr(char **split);
void	free_all(t_pipex *px);
void	wait_for_children(t_pipex *px);

//cmd_utils_bonus.c
char	**parse_cmd(const char *cmd);
char	*get_cmd_path(char *cmd, char **envp);

//get_next_line_bonus
char	*get_next_line(int fd);
char	*ft_update_line(char *leftover);
char	*ft_extract_line(char *leftover);
char	*ft_read_line(int fd, char *buf, char *leftover);

//str_utils_bonus.c
int ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);

char	**ft_split(char const *s, char c);

#endif