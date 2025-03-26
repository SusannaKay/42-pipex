/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:02:20 by skayed            #+#    #+#             */
/*   Updated: 2024/12/20 21:17:17 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_numlen(int n)
{
	int	count;

	count = 0;
	if (n < 0)
		count++;
	if (n == 0)
		count = 1;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*ft_isempty(void)
{
	char	*str;

	str = (char *)malloc(2 * sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

static char	*ft_reverse(char *str)
{
	char	temp;
	int		end;
	int		start;

	start = 0;
	end = ft_strlen(str) - 1;
	if (str[start] == '-')
		start++;
	while (start <= end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int			i;
	char		*str;
	long int	l;

	l = (long int)n;
	i = 0;
	if (l == 0)
		return (ft_isempty());
	str = (char *)malloc((ft_numlen(n) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (l < 0)
	{
		str[0] = '-';
		l *= -1;
		i++;
	}
	while (l > 0)
	{
		str[i] = '0' + (l % 10);
		l /= 10;
		i++;
	}
	str[i] = '\0';
	return (ft_reverse(str));
}
