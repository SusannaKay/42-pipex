#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>     // open(), O_CREAT, O_TRUNC, O_RDONLY, O_WRONLY
# include <stdio.h>     // perror(), printf()
# include <stdlib.h>    // malloc(), free(), exit()
# include <string.h>    // strerror()
# include <sys/types.h> // pid_t
# include <sys/wait.h>  // wait(), waitpid()
# include <unistd.h>    // fork(), pipe(), execve(), access(), dup2(), close()
# include "./libft/libft.h"
typedef struct s_fd
{
	int	fd_in;
	int	fd_out;
	int	pipe_fd[2];
}		t_fd;

t_fd	*create_struct(char *argv[], t_fd *list_fd);
void	close_fd(t_fd *list_fd);
void	free_struct(t_fd *list_fd);

#endif