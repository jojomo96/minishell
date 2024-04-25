/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 01:51:38 by flfische          #+#    #+#             */
/*   Updated: 2024/03/20 12:34:38 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(t_format *format_info, va_list args)
{
	int	size;
	int	c;

	size = 0;
	c = va_arg(args, int);
	if (format_info->flags.minus)
		size += ft_putchar_p(c, 1);
	while (format_info->width > 1)
	{
		if (format_info->flags.zero && !format_info->flags.minus)
			size += ft_putchar_p('0', 1);
		else
			size += ft_putchar_p(' ', 1);
		format_info->width--;
	}
	if (!format_info->flags.minus)
		size += ft_putchar_p(c, 1);
	return (size);
}
