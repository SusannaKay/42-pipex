/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:05:52 by skayed            #+#    #+#             */
/*   Updated: 2025/01/27 17:06:04 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	check_conversion(char *str, va_list args)
{
	if (*str == 'p')
		return (ft_putptr(va_arg(args, void *)));
	if (*str == 'x' || *str == 'X')
		return (ft_putnbr_hex(va_arg(args, unsigned int), str));
	if (*str == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (*str == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (*str == '%')
		return (ft_putchar('%'));
	if (*str == 'i' || *str == 'd')
		return (ft_putnbr_dec(va_arg(args, int)));
	if (*str == 'u')
		return (ft_put_uns(va_arg(args, unsigned int)));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	args;

	count = 0;
	if (!str)
		return (0);
	va_start(args, str);
	while (*str)
	{
		if (*str != '%')
			count += ft_putchar((int)*str);
		else
		{
			str++;
			if (*str)
				count += check_conversion((char *)str, args);
		}
		str++;
	}
	va_end(args);
	return (count);
}
