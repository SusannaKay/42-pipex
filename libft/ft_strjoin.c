/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:22:09 by skayed            #+#    #+#             */
/*   Updated: 2024/12/18 10:27:26 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	char	*sjoin;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	sjoin = (char *)malloc(len1 + len2 + 1);
	if (sjoin == NULL)
		return (NULL);
	ft_strlcpy(sjoin, s1, len1 + 1);
	ft_strlcat(sjoin, s2, len1 + len2 + 1);
	return (sjoin);
}
