/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 19:27:00 by flfische          #+#    #+#             */
/*   Updated: 2024/03/20 12:34:38 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_percent(t_format *format_info)
{
	int	size;

	size = 0;
	if (format_info->flags.minus)
		size += ft_putchar_p('%', 1);
	while (format_info->width-- > 1)
	{
		if (format_info->flags.zero && !format_info->flags.minus)
			size += ft_putchar_p('0', 1);
		else
			size += ft_putchar_p(' ', 1);
	}
	if (!format_info->flags.minus)
		size += ft_putchar_p('%', 1);
	return (size);
}
