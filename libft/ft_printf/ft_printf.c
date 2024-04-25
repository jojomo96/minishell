/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 00:05:17 by flfische          #+#    #+#             */
/*   Updated: 2024/03/20 12:34:38 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		size;
	va_list	args;

	va_start(args, format);
	set_write_error(0);
	size = ft_print_loop(format, args);
	if (*get_write_error() == 1)
		return (-1);
	va_end(args);
	return (size);
}

int	ft_print_loop(const char *format, va_list args)
{
	int	size;
	int	new;
	int	i;

	i = 0;
	size = 0;
	new = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				break ;
			else
				new = ft_print_format(format, &i, args);
		}
		else
			new = ft_putchar_p(format[i++], 1);
		if (new == -1)
			return (-1);
		size += new;
	}
	return (size);
}

int	ft_print_format(const char *format, int *i, va_list args)
{
	t_format	*format_info;

	format_info = ft_parse_format(format, i, args);
	if (format_info == NULL)
		return (-1);
	if (format[*i] == '\0')
		return (0);
	format_info->conversion = format[*i];
	(*i)++;
	return (ft_print_conversion(format_info, args));
}

int	ft_print_conversion(t_format *format_info, va_list args)
{
	int	size;

	size = 0;
	if (format_info->conversion == 'c')
		size = ft_print_char(format_info, args);
	else if (format_info->conversion == 's')
		size = ft_print_string(format_info, args);
	else if (!format_info->precision && (format_info->conversion == 'd'
			|| format_info->conversion == 'i'))
		size = ft_print_num_nopre(format_info, args);
	else if (format_info->conversion == 'd' || format_info->conversion == 'i')
		size = ft_print_decnum(format_info, args);
	else if (format_info->conversion == 'p')
		size = ft_print_pointer(format_info, args);
	else if (format_info->conversion == 'u')
		size = ft_print_unsigned(format_info, args);
	else if (format_info->conversion == 'x')
		size = ft_print_lowerhex(format_info, args);
	else if (format_info->conversion == 'X')
		size = ft_print_upperhex(format_info, args);
	else if (format_info->conversion == '%')
		size = ft_print_percent(format_info);
	free(format_info);
	return (size);
}
