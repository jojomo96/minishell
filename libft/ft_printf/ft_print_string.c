/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 03:13:22 by flfische          #+#    #+#             */
/*   Updated: 2024/03/20 12:34:38 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnstr_fd(char *str, int n, int fd)
{
	int	i;

	i = 0;
	while (i < n && str[i] != '\0')
	{
		ft_putchar_p(str[i], fd);
		i++;
	}
	return (i);
}

int	ft_print_string_precision(t_format *format_info, char *str, int *space)
{
	int	size;

	*space = ft_strlen(str);
	size = 0;
	if (format_info->precision >= 0
		&& (size_t)format_info->precision < ft_strlen(str))
		*space = format_info->precision;
	if (format_info->flags.minus)
		size += ft_putnstr_fd(str, *space, 1);
	while (format_info->width > format_info->precision
		&& format_info->width > *space)
	{
		size += ft_putchar_p(' ', 1);
		format_info->width--;
	}
	return (size);
}

int	ft_print_string(t_format *format_info, va_list args)
{
	int		size;
	int		space;
	char	*str;

	size = 0;
	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";
	if (format_info->precision == 0)
		str = "";
	space = ft_strlen(str);
	size += ft_print_string_precision(format_info, str, &space);
	while ((size_t)format_info->width > ft_strlen(str))
	{
		if (format_info->flags.zero && !format_info->flags.minus)
			size += ft_putchar_p('0', 1);
		else
			size += ft_putchar_p(' ', 1);
		format_info->width--;
	}
	if (!format_info->flags.minus)
		size += ft_putnstr_fd(str, space, 1);
	return (size);
}
