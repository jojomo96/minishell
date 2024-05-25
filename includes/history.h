/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:16:18 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/25 10:58:47 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORY_H
# define HISTORY_H

# include "minishell.h"
# define HISTORY_FILE "/.minishell_history"

void	ft_history_add(char *input);
void	ft_history_init(void);
void	ft_remove_newline(char *line);

#endif
