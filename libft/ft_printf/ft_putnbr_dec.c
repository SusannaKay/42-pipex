/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:07:43 by skayed            #+#    #+#             */
/*   Updated: 2025/01/27 17:07:55 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr_dec(signed int n)
{
	char	*digits;
	int		count;

	count = 0;
	digits = "0123456789";
	if (n < 0)
	{
		if (n == -2147483648)
		{
			write(1, "-2147483648", 11);
			return (11);
		}
		write(1, "-", 1);
		count += 1;
		n *= -1;
	}
	if (n / 10 != 0)
		count += ft_putnbr_dec(n / 10);
	write(1, &(digits[n % 10]), 1);
	return (count + 1);
}
