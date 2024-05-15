/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:42:40 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/15 12:30:27 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include "minishell.h"

void	ft_signals_init(void);
void	ft_sigint_handler_heredoc(int signum);
void	ft_sigint_handler_normal(int signum);
void	ft_switch_to_heredoc_mode(void);
void	ft_switch_to_normal_mode(void);

#endif
