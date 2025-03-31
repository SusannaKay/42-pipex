/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:38:06 by skayed            #+#    #+#             */
/*   Updated: 2025/03/31 16:11:50 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus/pipex_bonus.h"

static void	wait_close(int fd_in, int fd_out)
{
	wait(NULL);
	close(fd_in);
	close(fd_out);
}
static void	execute_cmd(char *argv, char **envp)
{
	char	*cmd_path;
	char	**cmd_args;

	cmd_args = get_cmd(argv);
	if (!cmd_args || !cmd_args[0])
		return (free(cmd_args));
	cmd_path = check_path(find_path(envp), cmd_args[0]);
	if (!cmd_path)
	{
		ft_free_matrix(cmd_args);
		exit(127);
	}
	execve(cmd_path, cmd_args, envp);
	ft_free_matrix(cmd_args);
	perror("execve failed");
	exit(127);
}
static int	pipe_fork(int *fd, int fd_in, char *argv, char **envp)
{
	pid_t	pid;

	if (pipe(fd) < 0)
		return (perror("pipe error"), -1);
	pid = fork();
	if (pid < 0)
		return (perror("Fork error"), -1);
	if (pid == 0)
	{
		dup2(fd_in, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd_in);
		close(fd[0]);
		close(fd[1]);
		execute_cmd(argv, envp);
	}
	close(fd[1]);
	return (fd[0]);
}

int	main(int argc, char *argv[], char *envp[])
{
	int fd[2];
	int fd_in;
	int fd_out;
	int i;

	i = 2;
	if (argc < 5)
		return (ft_printf("Error: Not enough arguments\n"), 1);
	fd_in = STDIN_FILENO;
	fd_out = STDOUT_FILENO;
	while (i < argc - 2)
	{
		fd_in = pipe_fork(fd, fd_in, argv[i], envp);
		if (fd_in < 0)
			return (1);
		i++;
	}
	dup2(fd_in, STDIN_FILENO);
	dup2(fd_in, STDOUT_FILENO);
	execute_cmd(argv[argc - 2], envp);
	wait_close(fd_in, fd_out);
	return (0);
}