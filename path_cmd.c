/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:22:31 by skayed            #+#    #+#             */
/*   Updated: 2025/03/26 15:22:44 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char **envp)
{
	int	i;

	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5))
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

char	*check_path(char *env_path, char *cmd)
{
	char	**matrix;
	char	*full_path;

	matrix = ft_split(env_path, ":");
	while (*matrix)
	{
		full_path = ft_strjoin(*matrix, "/");
		full_path = ft_strjoin(full_path, cmd);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		matrix++;
		free(full_path);
	}
	free(matrix);
	return (NULL);
}
