/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:22:34 by skayed            #+#    #+#             */
/*   Updated: 2025/03/26 17:31:45 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	first_child(t_fd *list_fd, char **envp, char *argv)
{
	char	*cmd1_path;
	char	**cmd1_args;

	dup2(list_fd->fd_in, STDIN_FILENO);
	dup2(list_fd->pipe_fd[1], STDOUT_FILENO);
	close_fd(list_fd);
	cmd1_args = get_cmd(argv);
	cmd1_path = check_path(find_path(envp), cmd1_args[0]);
	execve(cmd1_path, cmd1_args, envp);
	perror("execve failed");
	exit(1);
}

static void	second_child(t_fd *list_fd, char **envp, char *argv)
{
	char	*cmd2_path;
	char	**cmd2_args;

	dup2(list_fd->fd_out, STDOUT_FILENO);
	dup2(list_fd->pipe_fd[0], STDIN_FILENO);
	close_fd(list_fd);
	cmd2_args = get_cmd(argv);
	cmd2_path = check_path(find_path(envp), cmd2_args[0]);
	execve(cmd2_path, cmd2_args, envp);
	perror("execve failed");
	exit(1);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_fd	*list_fd;
	pid_t	pid1;
	pid_t	pid2;

	list_fd = NULL;
	if (argc != 5)
		return (ft_printf("Usage: ./pipex file1 cmd1 cmd2 file2\n"), 1);
	list_fd = create_struct(argv, list_fd);
	if (!list_fd)
		exit(1);
	pid1 = fork();
	if (pid1 < 0)
		return (perror("Fork 1 failed"), 1);
	if (pid1 == 0)
		first_child(list_fd, envp, argv[2]);
	pid2 = fork();
	if (pid2 < 0)
		return (perror("Fork 2 failed"), 1);
	if (pid2 == 0)
		second_child(list_fd, envp, argv[3]);
	close_fd(list_fd);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	free(list_fd);
	return (0);
}
