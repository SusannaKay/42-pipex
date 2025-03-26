#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_fd *list_fd;
	pid_t	pid1;
	pid_t	pid2;

	list_fd = create_struct(argv, list_fd);
	if (list_fd == 1)
		exit(0);
	pid1 = fork();
	if (pid1 < 0)
		return(perror("Fork 1 failed"), 1);
	if (pid1 == 0)
	{
		dup2(list_fd->fd_in, STDIN_FILENO);
		dup2(list_fd->pipe_fd[1], STDOUT_FILENO);
		close_fd(list_fd);
		execve(cmd1_path, cmd1_args, envp);
	}
	pid2 = fork();
	if (pid2 < 0)
		return(perror("Fork 2 failed"), 1);
	if (pid2 == 0)
	{
		dup2(list_fd->fd_out, STDOUT_FILENO);
		dup2(list_fd->pipe_fd[0], STDIN_FILENO);
		close_fd(list_fd);
		execve(cmd2_path, cmd2_args, envp);
	}
	close_fd(list_fd);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	free_struct(list_fd);
	return (0);
}
