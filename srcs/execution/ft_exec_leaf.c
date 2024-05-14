/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_leaf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:33:53 by flfische          #+#    #+#             */
/*   Updated: 2024/05/14 18:16:06 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_execute_pipe_leaf(t_shell *ms, t_ast_node *node)
{
	char	*builtin;

	builtin = ft_is_builtin(node->u_data.leaf.argv[0]);
	if (builtin)
		ms->exit_code = ft_exec_builtin_fork(ms, node, builtin);
	else
		ms->exit_code = ft_exec_command_pipe(ms, node);
	return (ms->exit_code);
}

// dont fork for builtins
int	ft_execute_leaf(t_shell *ms, t_ast_node *node)
{
	char	*builtin;

	builtin = ft_is_builtin(node->u_data.leaf.argv[0]);
	if (builtin)
		ms->exit_code = ft_exec_builtin(ms, builtin, node->u_data.leaf.argv,
				node->u_data.leaf.fd_out);
	else
		ms->exit_code = ft_exec_command(ms, node);
	return (ms->exit_code);
}
