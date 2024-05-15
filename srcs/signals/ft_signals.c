/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:45:10 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/15 12:26:29 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	set_signal_handler(int signum, void (*handler)(int))
{
	struct sigaction	sa;

	sa.sa_handler = handler;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	if (sigaction(signum, &sa, NULL) == -1)
	{
		perror("sigaction");
		exit(EXIT_FAILURE);
	}
}

static void	ft_switch_to_normal_mode(void)
{
	set_signal_handler(SIGINT, ft_sigint_handler_normal);
	set_signal_handler(SIGQUIT, SIG_IGN);
}

static void	ft_switch_to_heredoc_mode(void)
{
	set_signal_handler(SIGINT, ft_sigint_handler_heredoc);
	set_signal_handler(SIGQUIT, SIG_IGN);
}

void	ft_signals_init(void)
{
	rl_catch_signals = 0;
	ft_switch_to_normal_mode();
	if (false)
		ft_switch_to_heredoc_mode();
}
