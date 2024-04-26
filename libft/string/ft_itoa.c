/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:46:27 by flfische          #+#    #+#             */
/*   Updated: 2024/03/26 10:36:52 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>

static int	ft_itoa_len(int n)
{
	int			len;
	long long	nb;

	len = 1;
	nb = n;
	if (nb < 0)
	{
		len++;
		nb *= -1;
	}
	while (nb > 9)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

/**
 * @brief converts an integer to a string
 * @param n integer to convert
 * @return string representation of the integer, or NULL if the allocation fails
 */
char	*ft_itoa(int n)
{
	char		*num;
	int			len;
	long long	nb;

	nb = n;
	len = ft_itoa_len(n);
	num = malloc(len + 1);
	if (num == NULL)
		return (NULL);
	num[len] = '\0';
	if (nb < 0)
	{
		num[0] = '-';
		nb *= -1;
	}
	if (nb == 0)
		num[0] = '0';
	while (nb > 0)
	{
		num[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (num);
}
