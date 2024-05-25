/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_heredoc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:04:41 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/25 20:21:47 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_sigint_handler_heredoc(int signum)
{
	(void)signum;
	g_interrupted = 1;
	rl_done = 1;
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
	ft_get_shell()->exit_code = 1;
}
