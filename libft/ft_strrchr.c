/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:41:45 by skayed            #+#    #+#             */
/*   Updated: 2024/12/14 16:15:23 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	unsigned char	ch;
	int				len;

	len = ft_strlen(str);
	ch = (unsigned char)c;
	if (ch == '\0')
		return ((char *)str + len);
	while (len >= 0)
	{
		if (str[len] == ch)
			return ((char *)str + len);
		len--;
	}
	return (NULL);
}
