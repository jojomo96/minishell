/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ast_build.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:05:31 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/09 12:56:30 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	node_precedence(t_ast_node *node)
{
	if(node->type == AST_TYPE_LEAF)
		return (0);

	if (node->u_data.s_node.op_type == OP_REDIRECT_IN ||
		node->u_data.s_node.op_type == OP_REDIRECT_OUT ||
		node->u_data.s_node.op_type == OP_APPEND_OUT ||
		node->u_data.s_node.op_type == OP_HEREDOC) {
		return 3;
	} else if (node->u_data.s_node.op_type == OP_PIPE) {
		return 2;
	} else if (node->u_data.s_node.op_type == OP_AND ||
			   node->u_data.s_node.op_type == OP_OR) {
		return 4;
	} else if (node->u_data.s_node.op_type == OP_SUBSHELL) {
		return 3;
	} else {
		return 0;
	}
}


// Use this function to build your AST
void	build_ast(t_ast_node **ast, t_ast_node **nodes)
{
	(void)ast;
	(void)nodes;
	// int index = 0;
	// int highest_precedence = 0;
	// int highest_precedence_index = 0;
	// while(nodes[index])
	// {
	// 	if()
	// }
}
