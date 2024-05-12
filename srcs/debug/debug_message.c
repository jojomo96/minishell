/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 10:32:44 by flfische          #+#    #+#             */
/*   Updated: 2024/05/12 10:35:43 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	debug_message(char *message)
{
	if (DEBUG)
	{
		ft_putstr_fd(BOLD, STDERR_FILENO);
		ft_putstr_fd(UNDERLINE, STDERR_FILENO);
		ft_putstr_fd(BLUE, STDERR_FILENO);
		ft_putstr_fd("DEBUG:", STDERR_FILENO);
		ft_putstr_fd(RESET, STDERR_FILENO);
		ft_putstr_fd(" ", STDERR_FILENO);
		ft_putstr_fd(BLUE, STDERR_FILENO);
		ft_putendl_fd(message, STDERR_FILENO);
		ft_putstr_fd(RESET, STDERR_FILENO);
	}
}
