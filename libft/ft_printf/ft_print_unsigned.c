/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 09:30:10 by flfische          #+#    #+#             */
/*   Updated: 2024/03/20 12:34:38 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr_fd(unsigned int n, int fd)
{
	int	size;

	size = 0;
	if (n >= 10)
	{
		size += ft_putunbr_fd(n / 10, fd);
		size += ft_putchar_p(n % 10 + '0', fd);
	}
	else
		size += ft_putchar_p(n + '0', fd);
	return (size);
}

int	ft_get_uns_numlen(unsigned int n)
{
	int	size;

	size = 1;
	while (n >= 10)
	{
		n /= 10;
		size++;
	}
	return (size);
}

int	ft_print_uns_minus(t_format *format_info, unsigned int num, int numlen)
{
	int	size;

	size = 0;
	if (num == 0 && format_info->precision == 0)
	{
		while (size < format_info->width)
			size += ft_putchar_p(' ', 1);
		return (size);
	}
	while (format_info->precision-- > numlen || (format_info->flags.zero
			&& format_info->width-- > numlen))
		size += ft_putchar_p('0', 1);
	if (num == 0 && format_info->precision == -1)
		return (size);
	size += ft_putunbr_fd(num, 1);
	while (size < format_info->width)
		size += ft_putchar_p(' ', 1);
	return (size);
}

int	ft_print_uns_nominus(t_format *format_info, unsigned int num, int numlen)
{
	int	size;

	size = 0;
	while (format_info->width > format_info->precision
		&& format_info->precision > 0 && format_info->width-- > numlen)
		size += ft_putchar_p(' ', 1);
	if (num == 0 && format_info->precision == 0 && format_info->width > 0)
		size += ft_putchar_p(' ', 1);
	while ((!format_info->flags.zero || (format_info->flags.zero
				&& !format_info->precision)) && format_info->width-- > numlen
		&& (format_info->precision < 0 || format_info->precision < numlen))
		size += ft_putchar_p(' ', 1);
	while (format_info->precision-- > numlen || (format_info->flags.zero
			&& format_info->width-- > numlen && format_info->precision < 0))
		size += ft_putchar_p('0', 1);
	if (num == 0 && format_info->precision == -1)
		return (size);
	size += ft_putunbr_fd(num, 1);
	return (size);
}

int	ft_print_unsigned(t_format *format_info, va_list args)
{
	unsigned int	num;
	int				numlen;
	int				size;

	num = (unsigned int)va_arg(args, unsigned int);
	numlen = ft_get_uns_numlen(num);
	size = 0;
	if (format_info->flags.minus)
		size += ft_print_uns_minus(format_info, num, numlen);
	else
		size += ft_print_uns_nominus(format_info, num, numlen);
	return (size);
}
