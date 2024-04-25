/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:02:58 by flfische          #+#    #+#             */
/*   Updated: 2024/03/20 00:05:40 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_hexlen(unsigned int num)
{
	int	size;

	size = 1;
	while (num >= 16)
	{
		num /= 16;
		size++;
	}
	return (size);
}

int	ft_get_numlen(int i)
{
	int	size;

	size = 1;
	if (i == INT_MIN)
		return (11);
	if (i == 0)
		return (1);
	if (i < 0)
	{
		size++;
		i = -i;
	}
	while (i >= 10)
	{
		i /= 10;
		size++;
	}
	return (size);
}

int	ft_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_power(nb, power - 1));
}
