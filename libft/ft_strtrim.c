/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@>                           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:28:16 by skayed            #+#    #+#             */
/*   Updated: 2024/12/20 18:21:13 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*ft_isempty(void)
{
	char	*trimmed;

	trimmed = (char *)malloc(1);
	if (!trimmed)
		return (NULL);
	trimmed[0] = '\0';
	return (trimmed);
}

static char	*ft_cpytrim(char *trimmed, const char *s1, int start, int end)
{
	int	j;

	j = 0;
	while (start <= end)
	{
		trimmed[j] = s1[start];
		j++;
		start++;
	}
	trimmed[j] = '\0';
	return (trimmed);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	int		start;
	int		end;

	end = ft_strlen(s1) - 1;
	if (end < 0)
		return (ft_strdup(""));
	start = 0;
	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	if (start > end)
		return (ft_isempty());
	trimmed = (char *)malloc(end - start + 2);
	if (trimmed == NULL)
		return (NULL);
	return (ft_cpytrim(trimmed, s1, start, end));
}
