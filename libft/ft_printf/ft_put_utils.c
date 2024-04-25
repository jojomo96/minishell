/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:28:15 by flfische          #+#    #+#             */
/*   Updated: 2024/03/20 12:34:52 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_p(char c, int fd)
{
	int	status;
	int	*error;

	status = 0;
	error = get_write_error();
	if (*error != 1)
	{
		status = write(fd, &c, 1);
		if (status == -1)
		{
			*error = 1;
		}
	}
	return (status);
}

int	*get_write_error(void)
{
	static int	status;

	return (&status);
}

void	set_write_error(int status)
{
	int	*error;

	error = get_write_error();
	*error = status;
}

int	ft_putstr_p(char *s, int fd)
{
	int	i;

	i = 0;
	while (*s)
	{
		i += ft_putchar_p(*s, fd);
		s++;
	}
	return (i);
}

int	ft_putnbr_p(int n, int fd)
{
	int		div;
	char	c;
	int		size;

	size = 0;
	div = 1;
	if (n == -2147483648)
		return (ft_putstr_p("-2147483648", fd));
	if (n < 0)
	{
		size += ft_putchar_p('-', fd);
		n = -n;
	}
	while (n / div > 9)
		div = div * 10;
	while (div > 0)
	{
		c = (n / div) + '0';
		n = n - ((n / div) * div);
		size += ft_putchar_p(c, fd);
		div = div / 10;
	}
	return (size);
}
