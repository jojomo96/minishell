/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:16:18 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/21 20:52:53 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORY_H
# define HISTORY_H

# include "minishell.h"
# define HISTORY_FILE ".minishell_history"

void	ft_history_add(char *input);
void	ft_history_init(void);

#endif
