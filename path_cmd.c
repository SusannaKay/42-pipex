/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:22:31 by skayed            #+#    #+#             */
/*   Updated: 2025/03/26 17:13:07 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}
char	*find_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			return (envp[i] + 5);
		}
		i++;
	}
	perror("PATH not found");
	exit(1);
}

char	*check_path(char *env_path, char *cmd)
{
	char	**matrix;
	char	*full_path;
	int		i;

	matrix = ft_split(env_path, ':');
	if (!matrix)
		return (NULL);
	i = 0;
	while (matrix[i])
	{
		full_path = ft_strjoin(matrix[i], "/");
		full_path = ft_strjoin(full_path, cmd);
		if (access(full_path, F_OK | X_OK) == 0)
		{
			ft_free_matrix(matrix);
			return (full_path);
		}
		i++;
		free(full_path);
	}
	ft_free_matrix(matrix);
	perror("Command not found");
	exit(127);
}

char	**get_cmd(char *cmd)
{
	char **cmd_args;

	cmd_args = ft_split(cmd, ' ');
	if (!cmd_args || !cmd_args[0])
	{
		ft_free_matrix(cmd_args);
		perror("Command not found");
		exit(1);
	}
	return (cmd_args);
}