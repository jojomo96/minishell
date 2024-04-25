/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 21:20:12 by flfische          #+#    #+#             */
/*   Updated: 2024/04/17 21:34:16 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Converts a string to a double.
 * @param str The string to convert.
 * @return The converted double.
 */
double	ft_atod(char *str)
{
	int		is_negative;
	double	out;
	double	divider;

	if (!strncmp(str, "-2147483648", 11))
		return (-2147483648);
	is_negative = 1;
	out = 0;
	ft_strskipif(&str, ft_isspace);
	if (*str == '-' && str++)
		is_negative = -1;
	else if (*str == '+')
		str++;
	while (ft_isdigit(*str))
		out = out * 10 + *str++ - '0';
	if (*str == '.' && str++)
	{
		divider = 1;
		while (ft_isdigit(*str))
		{
			divider /= 10;
			out += (*str++ - '0') * divider;
		}
	}
	return (out * is_negative);
}
