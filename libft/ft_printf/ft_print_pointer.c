/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:57:02 by flfische          #+#    #+#             */
/*   Updated: 2024/03/20 12:34:52 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_numlen_base(unsigned long n, int base)
{
	int	len;

	len = 1;
	while (n >= (unsigned long)base)
	{
		n /= base;
		len++;
	}
	return (len);
}

int	ft_putnchr_fd(char c, int n, int fd)
{
	int	size;

	size = 0;
	while (n-- > 0)
		size += ft_putchar_p(c, fd);
	return (size);
}

int	ft_print_pointer_hex(unsigned long pointer)
{
	int	size;

	size = 0;
	if (pointer >= 16)
	{
		size += ft_print_pointer_hex(pointer / 16);
		size += ft_putchar_p("0123456789abcdef"[pointer % 16], 1);
	}
	else
		size += ft_putchar_p("0123456789abcdef"[pointer], 1);
	return (size);
}

int	ft_print_pointer_minus(t_format *format, unsigned long pointer)
{
	int	size;

	size = 0;
	size += ft_putstr_p("0x", 1);
	size += ft_putnchr_fd('0', format->precision - size, 1);
	if (!(format->precision == 0 && pointer == 0))
		size += ft_print_pointer_hex(pointer);
	size += ft_putnchr_fd(' ', format->width - size, 1);
	return (size);
}

int	ft_print_pointer(t_format *format, va_list args)
{
	unsigned long	pointer;
	int				size;
	int				numlen;

	pointer = (unsigned long)va_arg(args, long);
	numlen = ft_numlen_base(pointer, 16);
	if (format->precision > numlen)
		numlen = format->precision;
	size = 0;
	if (format->flags.minus)
		size += ft_print_pointer_minus(format, pointer);
	else
	{
		size += ft_putnchr_fd(' ', format->width - numlen - 2, 1);
		size += ft_putstr_p("0x", 1);
		size += ft_putnchr_fd('0', format->precision - (size + 2), 1);
		if (!(format->precision == 0 && pointer == 0))
			size += ft_print_pointer_hex(pointer);
	}
	return (size);
}
