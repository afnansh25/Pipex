/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 18:00:24 by ashaheen          #+#    #+#             */
/*   Updated: 2025/06/15 16:16:35 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_pipex px;

	validate_inputs(ac, av);
	init_pipex(&px, av);
	pipex(&px, envp);
	return (0);
}

// int	main(int ac, char **av, char **envp)
// {
// 	char	*file1;
// 	char	*cmd1;
// 	char	*cmd2;
// 	char	*file2;

// 	if (ac != 5)
// 		return (1);
// 	file1 = av[1];
// 	cmd1 = av[2];
// 	cmd2 = av[3];
// 	file2 = av[4];
// 	pipex(file1, file2, cmd1, cmd2, envp);
// 	return (0);
// }

// int	main(int ac, char **av, char **envp)
// {
// 	char	*file1;
// 	char	*cmd1;
// 	char	*cmd2;
// 	char	*file2;
	
// 	if (ac != 5)
// 		return (0);
// 	file1 = av[1];
// 	cmd1 = av[2];
// 	cmd2 = av[3];
// 	file2 = av[4];
// 	printf("%s, %s, %s, %s\n", file1, cmd1, cmd2, file2);
// 	char **c1 = parse_cmd(cmd1);
// 	int i= 0;
// 	while (c1[i])
// 	{
// 		printf("%s\n", c1[i]);
// 		i++;
// 	}
// 	char **c2 = parse_cmd(cmd2);
// 	i= 0;
// 	while (c2[i])
// 	{
// 		printf("%s\n", c2[i]);
// 		i++;
// 	}
// 	int fd1 = open (file1, O_RDONLY);
// 	if (fd1 < 0)
// 		{
// 			perror("can't open file1");
// 			exit(1);
// 		}
// 	int fd2 = open (file2, O_CREAT | O_WRONLY | O_TRUNC, 0644);
// 	if (fd2 < 0)
// 		{
// 			perror("can't open file2");
// 			exit(1);
// 		}
// 	printf ("%d, %d\n", fd1, fd2);

// 	int pipe_fd[2];
// 	pipe (pipe_fd);
// 	int pid = fork(); // the procces is split into parent and child 
// 					// next steps will run in the two parent and child
// 	if (pid == 0)// in the child
// 	{
// 		dup2(fd1, STDIN_FILENO); //redirect input from file 1
// 		dup2(pipe_fd[1], STDOUT_FILENO); //redirect output go to pipe
// 		close(fd1);
// 		close(fd2);
// 		close(pipe_fd[0]); // no need to read
// 		char	*cmd_path = get_cmd_path(c1[0], envp);
// 		execve(cmd_path, c1, envp);
// 		perror("execve failed");
// 		free(cmd_path);
// 		free_path(c1);
// 		exit(1);
// 	}
// 	else // in the parent
// 	{
// 		close(pipe_fd[1]); // no need to write
// 		int pid2 = fork();
// 		if (pid2 == 0) // in the second child
// 		{
// 			dup2(pipe_fd[0], STDIN_FILENO);
// 			dup2(fd2, STDOUT_FILENO);
// 			close(fd1);
// 			close(fd2);
// 			close(pipe_fd[0]);
// 			close(pipe_fd[1]);
// 			char	*cmd2_path = get_cmd_path(c2[0], envp);
// 			execve(cmd2_path, c2, envp);
// 			perror("execve failed");
// 			free(cmd2_path);
// 			free_path(c2);
// 			exit(1);
// 		}
// 		else // in the parent
// 		{
// 			close(pipe_fd[0]);
// 		}
// 		close(pipe_fd[0]);
// 		close(pipe_fd[1]);
// 		waitpid(pid, NULL, 0);
// 		waitpid(pid2, NULL, 0);
// 	}
// 	return (0);
// }