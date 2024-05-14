/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:41:12 by flfische          #+#    #+#             */
/*   Updated: 2024/05/14 11:23:07 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "minishell.h"

int	ft_execute(t_shell *ms, t_ast_node *node);
int	ft_exec_builtin(t_shell *ms, t_builtin builtin, char **argv, int fd_out);

#endif
