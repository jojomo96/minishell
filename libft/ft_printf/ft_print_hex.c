/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:01:14 by flfische          #+#    #+#             */
/*   Updated: 2024/03/20 12:34:52 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_minus(t_format *format_info, unsigned int num, char *base,
		char *prefix)
{
	int	size;

	size = 0;
	size += ft_putstr_p(prefix, 1);
	size += ft_putnchr_fd('0', format_info->precision - ft_get_hexlen(num), 1);
	size += ft_putnbr_base(num, base);
	size += ft_putnchr_fd(' ', format_info->width - size, 1);
	return (size);
}

int	ft_print_hex_nominus(t_format *format_info, unsigned int num, char *base,
		char *prefix)
{
	int	size;
	int	spaces;
	int	zeros;

	size = 0;
	if (format_info->flags.zero && format_info->precision == -1)
	{
		size += ft_putstr_p(prefix, 1);
		zeros = format_info->width - ft_get_hexlen(num) - ft_strlen(prefix);
		size += ft_putnchr_fd('0', zeros, 1);
	}
	else
	{
		if (format_info->precision > ft_get_hexlen(num))
			spaces = format_info->width - format_info->precision;
		else
			spaces = format_info->width - ft_get_hexlen(num);
		size += ft_putnchr_fd(' ', spaces - ft_strlen(prefix), 1);
		size += ft_putstr_p(prefix, 1);
	}
	size += ft_putnchr_fd('0', format_info->precision - ft_get_hexlen(num), 1);
	size += ft_putnbr_base(num, base);
	return (size);
}

int	ft_print_hex(t_format *format_info, unsigned int num, char *base,
		char *prefix)
{
	int	size;

	size = 0;
	if (format_info->flags.minus)
		size += ft_print_hex_minus(format_info, num, base, prefix);
	else
		size += ft_print_hex_nominus(format_info, num, base, prefix);
	return (size);
}

int	ft_print_lowerhex(t_format *format_info, va_list args)
{
	unsigned int	num;
	int				size;

	size = 0;
	num = (unsigned int)va_arg(args, int);
	if (format_info->precision == 0 && num == 0)
	{
		while (format_info->width-- > 0)
			size += ft_putchar_p(' ', 1);
		return (size);
	}
	if (format_info->flags.alternative && num != 0)
		size += ft_print_hex(format_info, num, "0123456789abcdef", "0x");
	else
		size += ft_print_hex(format_info, num, "0123456789abcdef", "");
	return (size);
}

int	ft_print_upperhex(t_format *format_info, va_list args)
{
	unsigned int	num;
	int				size;

	size = 0;
	num = (unsigned int)va_arg(args, int);
	if (format_info->precision == 0 && num == 0)
	{
		while (format_info->width-- > 0)
			size += ft_putchar_p(' ', 1);
		return (size);
	}
	if (format_info->flags.alternative && num != 0)
		size += ft_print_hex(format_info, num, "0123456789ABCDEF", "0X");
	else
		size += ft_print_hex(format_info, num, "0123456789ABCDEF", "");
	return (size);
}
