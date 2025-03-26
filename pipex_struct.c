/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:22:37 by skayed            #+#    #+#             */
/*   Updated: 2025/03/26 15:22:38 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_fd	*create_struct(char *argv[], t_fd *list_fd)
{
	list_fd = malloc(sizeof(t_fd));
	if (!list_fd)
		return (perror("Struct init failed"), NULL);
	list_fd->fd_in = open(argv[1], O_RDONLY);
	if (list_fd->fd_in < 0)
		return (perror("open failed"), 1);
	list_fd->fd_out = open(argv[4], O_WRONLY);
	if (list_fd->fd_out < 0)
		return (perror("write failed"), 1);
	if (pipe(list_fd->pipe_fd) < 0)
		return (perror("pipe failed"), 1);
	return (list_fd);
}

void	close_fd(t_fd *list_fd)
{
	close(list_fd->fd_in);
	close(list_fd->fd_out);
	close(list_fd->pipe_fd[0]);
	close(list_fd->pipe_fd[1]);
}

void	free_struct(t_fd *list_fd)
{
	free(list_fd->pipe_fd[0]);
	free(list_fd->pipe_fd[1]);
	free(list_fd);
}
