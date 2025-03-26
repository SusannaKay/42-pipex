#include "pipex.h"

int main(int argc, char *argv[], char *envp[])
{
	int fd_in;
	int fd_out;

	int fd_in = open(argv[1], O_RDONLY);
	if (fd_in == -1)
	{
		perror("open");
		return(1);
	}

	return(0);
}