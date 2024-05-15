/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:41:12 by flfische          #+#    #+#             */
/*   Updated: 2024/05/15 14:11:47 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "minishell.h"

int		ft_execute(t_shell *ms, t_ast_node *node);
int		ft_execute_node(t_shell *ms, t_ast_node *node);
int		ft_exec_builtin(t_shell *ms, t_builtin builtin, char **argv,
			int fd_out);
int		ft_exec_builtin_fork(t_shell *ms, t_ast_node *node, t_builtin builtin);
int		ft_exec_command(t_shell *ms, t_ast_node *node);
int		ft_exec_leaf(t_shell *ms, t_ast_node *node);
int		ft_exec_pipe_leaf(t_shell *ms, t_ast_node *node);
int		ft_exec_and(t_shell *ms, t_ast_node *node);
int		ft_exec_or(t_shell *ms, t_ast_node *node);
int		ft_exec_redirect_in(t_shell *ms, t_ast_node *node);
int		ft_exec_redirect_out(t_shell *ms, t_ast_node *node);
int		ft_exec_append_out(t_shell *ms, t_ast_node *node);
int		ft_exec_pipe(t_shell *ms, t_ast_node *node);

void	ft_wait_node(t_ast_node *node);

#endif
