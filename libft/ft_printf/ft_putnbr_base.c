/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:58:34 by flfische          #+#    #+#             */
/*   Updated: 2024/03/20 12:34:38 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_errors(char *base);

int	ft_putnbr_base(long nbr, char *base)
{
	int	len;
	int	size;

	size = 0;
	if (!check_errors(base))
		return (0);
	len = ft_strlen(base);
	if (nbr < 0)
		size += ft_putchar_p('-', 1);
	if (nbr == (long)LONG_MIN)
	{
		size += ft_putnbr_base(-(nbr / len), base);
		size += ft_putnbr_base(-(nbr % len), base);
	}
	else if (nbr < 0)
		size += ft_putnbr_base(-nbr, base);
	else if (nbr >= len)
	{
		size += ft_putnbr_base(nbr / len, base);
		size += ft_putnbr_base(nbr % len, base);
	}
	else
		size += ft_putchar_p(base[nbr], 1);
	return (size);
}

static int	check_errors(char *base)
{
	int	len;
	int	i;
	int	j;

	len = ft_strlen(base);
	if (len < 2)
		return (0);
	i = 0;
	while (i < len)
	{
		if (!(base[i] >= 32 && base[i] <= 126) || base[i] == '+'
			|| base[i] == '-' || base[i] == ' ')
			return (0);
		j = i + 1;
		while (j < len)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
