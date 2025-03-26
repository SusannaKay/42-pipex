/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:22:37 by skayed            #+#    #+#             */
/*   Updated: 2025/03/26 17:27:03 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_fd	*create_struct(char *argv[], t_fd *list_fd)
{
	list_fd = malloc(sizeof(t_fd));
	if (!list_fd)
	{
		perror("Struct init failed");
		exit(1);
	}
	list_fd->fd_in = open(argv[1], O_RDONLY);
	if (list_fd->fd_in < 0)
	{
		perror("open failed");
		exit(1);
	}
	list_fd->fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (list_fd->fd_out < 0)
	{
		perror("write failed");
		exit(1);
	}
	if (pipe(list_fd->pipe_fd) < 0)
	{
		perror("pipe failed");
		exit(1);
	}
	return (list_fd);
}

void	close_fd(t_fd *list_fd)
{
	close(list_fd->fd_in);
	close(list_fd->fd_out);
	close(list_fd->pipe_fd[0]);
	close(list_fd->pipe_fd[1]);
}
