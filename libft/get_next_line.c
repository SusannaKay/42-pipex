/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 10:16:22 by skayed            #+#    #+#             */
/*   Updated: 2025/01/11 10:47:29 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4
#endif

#include "libft.h"

static char	*ft_bytes(char **tmp, char *buf, int bytes_read)
{
	char	*rtn;

	if (bytes_read == 0)
	{
		if (*tmp && **tmp)
		{
			rtn = *tmp;
			*tmp = NULL;
			free(buf);
			return (rtn);
		}
		free(buf);
		free(*tmp);
		*tmp = NULL;
		return (NULL);
	}
	if (bytes_read < 0)
	{
		free (buf);
		free (*tmp);
		*tmp = NULL;
		return (NULL);
	}
	return (NULL);
}

static char	*ft_nl_tmp(char **tmp, char *buf)
{
	char	*new_pos;
	char	*rtn;
	char	*old_tmp;

	new_pos = ft_strchr(*tmp, '\n');
	rtn = ft_substr(*tmp, 0, new_pos - *tmp + 1);
	old_tmp = *tmp;
	*tmp = ft_strdup(new_pos + 1);
	free(old_tmp);
	free(buf);
	return (rtn);
}

static char	*ft_nl_buf(char **tmp, char *buf)
{
	char	*rtn;
	char	*new_pos;
	char	*subs;

	new_pos = ft_strchr(buf, '\n');
	subs = ft_substr(buf, 0, new_pos - buf + 1);
	if (*tmp)
	{
		rtn = ft_strjoin(*tmp, subs);
		free(*tmp);
		free(subs);
		*tmp = ft_strdup(new_pos + 1);
	}
	else
	{
		rtn = subs;
		*tmp = ft_strdup(new_pos + 1);
	}
	free(buf);
	return (rtn);
}

static void	ft_append(char **tmp, char *buf)
{
	char	*old_tmp;

	if (*tmp)
	{
		old_tmp = *tmp;
		*tmp = ft_strjoin(old_tmp, buf);
		free(old_tmp);
	}
	else
		*tmp = ft_strdup(buf);
}

char	*get_next_line(int fd)
{
	char		*buf;
	int			bytes_read;
	static char	*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	while (1)
	{
		if (tmp && ft_strchr(tmp, '\n'))
			return (ft_nl_tmp(&tmp, buf));
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (ft_bytes(&tmp, buf, bytes_read));
		buf[bytes_read] = '\0';
		if (ft_strchr(buf, '\n'))
			return (ft_nl_buf(&tmp, buf));
		ft_append(&tmp, buf);
	}
}
