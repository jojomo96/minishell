/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_leaf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:33:53 by flfische          #+#    #+#             */
/*   Updated: 2024/05/15 14:10:32 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exec_pipe_leaf(t_shell *ms, t_ast_node *node)
{
	int	builtin;
	int	std_in;
	int	std_out;

	std_in = dup(STDIN_FILENO);
	std_out = dup(STDOUT_FILENO);
	if (node->u_data.leaf.fd_in != STDIN_FILENO)
		dup2(node->u_data.leaf.fd_in, STDIN_FILENO);
	if (node->u_data.leaf.fd_out != STDOUT_FILENO)
		dup2(node->u_data.leaf.fd_out, STDOUT_FILENO);
	builtin = ft_is_builtin(node->u_data.leaf.argv[0]);
	if (builtin)
		ms->exit_code = ft_exec_builtin_fork(ms, node, builtin);
	else
		ms->exit_code = ft_exec_command(ms, node);
	close(node->u_data.leaf.fd_in);
	close(node->u_data.leaf.fd_out);
	dup2(std_in, STDIN_FILENO);
	dup2(std_out, STDOUT_FILENO);
	close(std_in);
	close(std_out);
	return (ms->exit_code);
}

// dont fork for builtins
int	ft_exec_leaf(t_shell *ms, t_ast_node *node)
{
	int	builtin;

	builtin = ft_is_builtin(node->u_data.leaf.argv[0]);
	if (builtin)
		ms->exit_code = ft_exec_builtin(ms, builtin, node->u_data.leaf.argv,
				node->u_data.leaf.fd_out);
	else
		ms->exit_code = ft_exec_command(ms, node);
	return (ms->exit_code);
}
