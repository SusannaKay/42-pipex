/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:08:24 by skayed            #+#    #+#             */
/*   Updated: 2025/01/27 17:08:31 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	putptr_recursive(unsigned long address)
{
	char	*digits;
	int		count;

	digits = "0123456789abcdef";
	count = 0;
	if (address >= 16)
		count += putptr_recursive(address / 16);
	count += write(1, &digits[address % 16], 1);
	return (count);
}

int	ft_putptr(void *ptr)
{
	int				count;
	unsigned long	address;

	address = (unsigned long)ptr;
	count = 0;
	if (!ptr)
	{
		write(1, "(nil)", ft_strlen("(nil)"));
		return (5);
	}
	write(1, "0x", 2);
	count = 2;
	count += putptr_recursive(address);
	return (count);
}
