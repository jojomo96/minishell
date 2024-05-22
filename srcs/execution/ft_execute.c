/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:29:43 by flfische          #+#    #+#             */
/*   Updated: 2024/05/22 20:00:19 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_execute(t_shell *ms, t_ast_node *node)
{
	errno = 0;
	ft_expand_arguments(node);
	return (ft_execute_node(ms, node));
}

// add expander
int	ft_execute_node(t_shell *ms, t_ast_node *node)
{
	if (node->type == AST_TYPE_LEAF && (node->u_data.leaf.argv[0] == NULL
			|| node->u_data.leaf.argv[0][0] == '\0'))
		return (0);
	if (node->type == AST_TYPE_LEAF)
		return (ft_exec_leaf(ms, node));
	if (node->u_data.s_node.op_type == OP_PIPE)
		return (ft_exec_pipe(ms, node));
	if (node->u_data.s_node.op_type == OP_AND)
		return (ft_exec_and(ms, node));
	if (node->u_data.s_node.op_type == OP_OR)
		return (ft_exec_or(ms, node));
	if (node->u_data.s_node.op_type == OP_REDIRECT_IN)
		return (ft_exec_redirect_in(ms, node));
	if (node->u_data.s_node.op_type == OP_REDIRECT_OUT)
		return (ft_exec_redirect_out(ms, node));
	if (node->u_data.s_node.op_type == OP_APPEND_OUT)
		return (ft_exec_append_out(ms, node));
	// if (node->u_data.s_node.op_type == OP_HEREDOC)
	// 	return (ft_exec_heredoc(ms, node));
	return (0);
}
