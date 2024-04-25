/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 00:46:44 by flfische          #+#    #+#             */
/*   Updated: 2024/03/09 02:41:05 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_flag(const char *format, int *i, t_flags *flags)
{
	if (format[*i] == '-')
		flags->minus = 1;
	else if (format[*i] == '0')
		flags->zero = 1;
	else if (format[*i] == '#')
		flags->alternative = 1;
	else if (format[*i] == ' ')
		flags->space = 1;
	else if (format[*i] == '+')
		flags->plus = 1;
	else
		return (0);
	return (1);
}

void	ft_skip_digits(const char *format, int *i)
{
	while (ft_isdigit(format[*i]))
		(*i)++;
}

t_format	*ft_alloc_format(void)
{
	t_format	*format_info;

	format_info = (t_format *)malloc(sizeof(t_format));
	if (format_info == NULL)
		return (NULL);
	format_info->width = 0;
	format_info->precision = -1;
	format_info->conversion = '\0';
	format_info->flags = (t_flags){0, 0, 0, 0, 0};
	return (format_info);
}

t_format	*ft_parse_format(const char *format, int *i, va_list args)
{
	t_format	*format_info;

	format_info = ft_alloc_format();
	if (format_info == NULL)
		return (NULL);
	while (ft_get_flag(format, i, &format_info->flags))
		(*i)++;
	if (format[*i] == '*' && (*i)++)
		format_info->width = va_arg(args, int);
	else if (ft_isdigit(format[*i]))
		format_info->width = ft_atoi(&format[*i]);
	ft_skip_digits(format, i);
	if (format[*i] == '.')
	{
		(*i)++;
		if (format[*i] == '*' && (*i)++)
			format_info->precision = va_arg(args, int);
		else
			format_info->precision = ft_atoi(&format[*i]);
		ft_skip_digits(format, i);
	}
	format_info->conversion = format[*i];
	return (format_info);
}
