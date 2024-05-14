/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 09:37:25 by flfische          #+#    #+#             */
/*   Updated: 2024/05/12 10:37:07 by flfische         ###   ########.fr       */
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
	(void)fd_out;
	debug_message("executing builtin: echo");
	if (argv[1])
	{
		if (argv[2])
		{
			ft_putendl_fd("exit", STDERR_FILENO);
			ft_print_error("too many arguments", "exit", NULL);
			ms->exit_code = 1;
			return ;
		}
		if (!ft_isdigits(argv[1]))
		{
			ft_putendl_fd("exit", STDERR_FILENO);
			ft_print_error("numeric argument required", "exit", argv[1]);
			ms->exit_code = 255;
			ft_destroy_shell(ms, 1);
		}
		ms->exit_code = ft_atoi(argv[1]);
		ms->exit_code = ms->exit_code % 256;
	}
	if (isatty(fileno(stdin)))
		ft_putendl_fd("exit", STDERR_FILENO);
	ft_destroy_shell(ms, 1);
}
