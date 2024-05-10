/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 09:37:25 by flfische          #+#    #+#             */
/*   Updated: 2024/05/10 10:12:37 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_isdigits(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

void	ft_exit(t_shell *ms, char **argv, int fd_out)
{
	ft_putendl_fd("exit", fd_out);
	if (argv[1])
	{
		if (argv[2])
		{
			ft_putendl_fd("exit: too many arguments", fd_out);
			ms->exit_code = 1;
			return ;
		}
		if (!ft_isdigits(argv[1]))
		{
			ft_putendl_fd("exit: numeric argument required", fd_out);
			ms->exit_code = 255;
			ft_destroy_shell(ms, 1);
		}
		ms->exit_code = ft_atoi(argv[1]);
	}
	ft_destroy_shell(ms, 1);
}
