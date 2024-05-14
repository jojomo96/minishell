/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:45:02 by flfische          #+#    #+#             */
/*   Updated: 2024/05/12 10:36:52 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(t_shell *ms, int fd_out)
{
	int	i;

	debug_message("executing builtin: env");
	i = 0;
	while (ms->env[i] != NULL)
	{
		ft_putendl_fd(ms->env[i], fd_out);
		i++;
	}
	return (0);
}
