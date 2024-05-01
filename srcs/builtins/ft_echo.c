/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:41:48 by flfische          #+#    #+#             */
/*   Updated: 2024/05/01 14:01:38 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_has_nl(char *str)
{
	if (!ft_strcmp(str, "-n"))
		return (1);
	if (*str != '-')
		return (0);
	str++;
	if (*str != 'n')
		return (0);
	while (*str == 'n')
		str++;
	if (*str != '\0')
		return (0);
	return (1);
}

// TODO: use ast input
int	ft_echo(char **arr)
{
	int	i;
	int	nl;

	i = 0;
	nl = 1;
	while (arr[i] && ft_has_nl(arr[i]))
	{
		nl = 0;
		i++;
	}
	while (arr[i])
	{
		ft_putstr_fd(arr[i], 1);
		if (arr[i + 1])
			ft_putchar_fd(' ', 1);
		i++;
	}
	if (nl)
		ft_putchar_fd('\n', 1);
	return (0);
}
