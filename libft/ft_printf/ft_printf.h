/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:06:17 by skayed            #+#    #+#             */
/*   Updated: 2025/01/27 17:18:01 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_strlen(const char *s);
int	ft_putstr(char *s);
int	ft_putchar(int s);
int	ft_putnbr_dec(signed int n);
int	ft_putptr(void *ptr);
int	ft_put_uns(unsigned int n);
int	ft_putnbr_hex(unsigned int n, char *str);

#endif
