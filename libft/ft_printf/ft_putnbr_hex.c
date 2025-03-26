/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:08:09 by skayed            #+#    #+#             */
/*   Updated: 2025/01/27 17:08:13 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr_hex(unsigned int n, char *str)
{
	char	*digits;
	int		count;

	count = 0;
	if (n / 16 != 0)
		count += ft_putnbr_hex(n / 16, str);
	if (*str == 'x')
		digits = "0123456789abcdef";
	if (*str == 'X')
		digits = "0123456789ABCDEF";
	write(1, &(digits[n % 16]), 1);
	return (count + 1);
}
