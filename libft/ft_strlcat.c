/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:53:40 by skayed            #+#    #+#             */
/*   Updated: 2024/12/14 14:54:13 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	l_dest;
	size_t	l_src;
	size_t	j;

	l_dest = ft_strlen(dest);
	l_src = ft_strlen(src);
	j = 0;
	if (l_dest >= size)
		return (size + l_src);
	if (l_dest >= size)
		return (size + l_src);
	while (src[j] != '\0' && (l_dest + j) < size - 1)
	{
		dest[l_dest + j] = src[j];
		j++;
	}
	dest[l_dest + j] = '\0';
	return (l_dest + l_src);
}
