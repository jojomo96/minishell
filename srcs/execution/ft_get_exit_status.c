/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_exit_status.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 14:54:02 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/26 17:24:08 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_get_exit_status(int status)
{
	if (WIFSIGNALED(status) && status == SIGTERM)
	{
		ft_putstr_fd("Terminated: ", STDERR_FILENO);
		ft_putnbr_fd(WTERMSIG(status), STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
		return (128 + WTERMSIG(status));
	}
	return (WEXITSTATUS(status));
}
