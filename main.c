/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:22:34 by skayed            #+#    #+#             */
/*   Updated: 2025/04/02 10:51:35 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_status(int pid1, int pid2)
{
	int	status;

	waitpid(pid1, NULL, 0);
	if (waitpid(pid2, &status, 0) == -1)
		return (1);
	if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		return (WEXITSTATUS(status));
	return (0);
}

static void	first_child(int *fd, char **envp, char **argv)
{
	int		fd_in;
	char	*cmd1_path;
	char	**cmd1_args;

	fd_in = open(argv[1], O_RDONLY);
	if (fd_in < 0)
		exit(1);
	dup2(fd_in, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd_in);
	close(fd[0]);
	close(fd[1]);
	cmd1_args = get_cmd(argv[2]);
	if (!cmd1_args || !cmd1_args[0])
		return (free(cmd1_args));
	cmd1_path = check_path(find_path(envp), cmd1_args[0]);
	if (!cmd1_path)
	{
		ft_free_matrix(cmd1_args);
		exit(127);
	}
	execve(cmd1_path, cmd1_args, envp);
	ft_free_matrix(cmd1_args);
	perror("execve failed");
	exit(127);
}

static void	second_child(int *fd, char **envp, char **argv)
{
	int		fd_out;
	char	*cmd2_path;
	char	**cmd2_args;

	fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd_out < 0)
		exit(1);
	dup2(fd_out, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(fd_out);
	close(fd[0]);
	close(fd[1]);
	cmd2_args = get_cmd(argv[3]);
	if (!cmd2_args || !cmd2_args[0])
		return (free(cmd2_args));
	cmd2_path = check_path(find_path(envp), cmd2_args[0]);
	if (!cmd2_path)
	{
		ft_free_matrix(cmd2_args);
		exit(127);
	}
	execve(cmd2_path, cmd2_args, envp);
	ft_free_matrix(cmd2_args);
	perror("execve failed");
	exit(127);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
		return (ft_printf("Usage: ./pipex file1 cmd1 cmd2 file2\n"), 1);
	if (pipe(fd) < 0)
		return (perror("pipe failed"), 1);
	pid1 = fork();
	if (pid1 < 0)
		return (perror("Fork 1 failed"), 1);
	if (pid1 == 0)
		first_child(fd, envp, argv);
	pid2 = fork();
	if (pid2 < 0)
		return (perror("Fork 2 failed"), 1);
	if (pid2 == 0)
		second_child(fd, envp, argv);
	close(fd[0]);
	close(fd[1]);
	return (check_status(pid1, pid2));
}
