/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:41:48 by flfische          #+#    #+#             */
/*   Updated: 2024/05/12 10:36:15 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_has_nl(char *str)
{
	int	has_quote;

	has_quote = 0;
	if (!ft_strcmp(str, "-n"))
		return (1);
	if (ft_isquoted(str) && ft_strlen(str) > 2)
	{
		has_quote = 1;
		str++;
	}
	if (*str != '-')
		return (0);
	str++;
	if (*str != 'n')
		return (0);
	while (*str == 'n')
		str++;
	if (*str != '\0' && !has_quote)
		return (0);
	if (has_quote && str[1] != '\0')
		return (0);
	return (1);
}

int	ft_echo(char **argv, int fd_out)
{
	int	i;
	int	nl;

	debug_message("executing builtin: echo");
	i = 1;
	nl = 1;
	while (argv[i] && ft_has_nl(argv[i]))
	{
		nl = 0;
		i++;
	}
	while (argv[i])
	{
		ft_putstr_fd(argv[i], fd_out);
		if (argv[i + 1])
			ft_putchar_fd(' ', fd_out);
		i++;
	}
	if (nl)
		ft_putchar_fd('\n', fd_out);
	return (0);
}
