/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num_nopre.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:11:12 by flfische          #+#    #+#             */
/*   Updated: 2024/03/20 12:35:07 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_zero_nopre(t_format *format_info)
{
	int	size;

	size = 0;
	if (format_info->flags.space && !format_info->flags.plus
		&& !format_info->width)
		size += ft_putchar_p(' ', 1);
	if (format_info->flags.plus && format_info->flags.minus)
		size += ft_putchar_p('+', 1);
	size += ft_putnchr_fd(' ', format_info->width - format_info->flags.plus, 1);
	if (format_info->flags.plus && !format_info->flags.minus)
		size += ft_putchar_p('+', 1);
	return (size);
}

int	ft_print_n_nopre_w_nonum(t_format *format_info)
{
	int	size;

	size = 0;
	size += ft_putnchr_fd(' ', format_info->width - format_info->flags.plus, 1);
	if (format_info->flags.plus)
		size += ft_putchar_p('+', 1);
	return (size);
}

int	ft_print_n_nopre_w_num_min(t_format *format_info, int num)
{
	int	size;

	size = 0;
	if (format_info->flags.plus && num >= 0)
		size += ft_putchar_p('+', 1);
	size += ft_putnbr_p(num, 1);
	size += ft_putnchr_fd(' ', format_info->width - ft_get_numlen(num)
			- format_info->flags.plus, 1);
	return (size);
}

int	ft_print_n_nopre_w_num(t_format *format_info, int num)
{
	int	size;

	size = 0;
	size += ft_putnchr_fd(' ', format_info->width - ft_get_numlen(num)
			- format_info->flags.plus, 1);
	if (format_info->flags.plus && num >= 0)
		size += ft_putchar_p('+', 1);
	size += ft_putnbr_p(num, 1);
	return (size);
}

int	ft_print_num_nopre(t_format *format_info, va_list args)
{
	int	size;
	int	num;

	num = va_arg(args, int);
	size = 0;
	if (num == 0)
		return (ft_print_zero_nopre(format_info));
	if (num < 0)
		format_info->flags.plus = 0;
	if (num >= 0 && format_info->flags.space)
		size += ft_putchar_p(' ', 1);
	if (num >= 0 && format_info->flags.space && format_info->width)
		format_info->width--;
	if (format_info->flags.plus && num >= 0 && !format_info->width)
		size += ft_putchar_p('+', 1);
	if (num && !format_info->width)
		size += ft_putnbr_p(num, 1);
	else if (format_info->width && !num)
		size += ft_print_n_nopre_w_nonum(format_info);
	else if (format_info->width && num && format_info->flags.minus)
		size += ft_print_n_nopre_w_num_min(format_info, num);
	else if (format_info->width && num && !format_info->flags.minus)
		size += ft_print_n_nopre_w_num(format_info, num);
	return (size);
}
