/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:41:12 by flfische          #+#    #+#             */
/*   Updated: 2024/05/26 17:07:43 by jmoritz          ###   ########.fr       */
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
int		ft_exec_heredoc(t_shell *ms, t_ast_node *node);
void	ft_preprocess_heredoc(t_ast_node *node);
void	ft_heredoc_read_input(char *delim, char *file_name);

int		handle_ambigous_redirect(t_ast_node *node);
void	red_set_exit_err(t_ast_node *node, bool print_content, bool print);
int		ft_set_left_fd_in(t_ast_node *node, int fd);

void	ft_wait_node(t_ast_node *node);

void	ft_close_fds(t_ast_node *node);
int		ft_get_exit_status(int status);
#endif
