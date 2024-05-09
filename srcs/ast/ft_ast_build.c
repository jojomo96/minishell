/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ast_build.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:05:31 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/09 13:23:53 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	node_precedence(t_ast_node *node)
{
	if (node->type == AST_TYPE_LEAF || node->type == AST_TYPE_PARANTHESIS)
		return (0);
	if (node->u_data.s_node.op_type == OP_REDIRECT_IN
		|| node->u_data.s_node.op_type == OP_REDIRECT_OUT
		|| node->u_data.s_node.op_type == OP_APPEND_OUT
		|| node->u_data.s_node.op_type == OP_HEREDOC)
	{
		return (1);
	}
	else if (node->u_data.s_node.op_type == OP_PIPE)
	{
		return (2);
	}
	else if (node->u_data.s_node.op_type == OP_AND
		|| node->u_data.s_node.op_type == OP_OR)
	{
		return (4);
	}
	else if (node->u_data.s_node.op_type == OP_SUBSHELL)
	{
		return (3);
	}
	else
	{
		return (0);
	}
}

// Use this function to build your AST
void	build_ast(t_ast_node **ast, t_ast_node **nodes)
{
	int	index;
	int	highest_precedence;
	int	highest_precedence_index;
	int	is_in_parenthesis;

	(void)ast;
	index = 0;
	highest_precedence = 0;
	highest_precedence_index = 0;
	is_in_parenthesis = 0;
	while (nodes[index])
	{
		if (nodes[index]->type == AST_TYPE_PARANTHESIS)
		{
			if (nodes[index]->u_data.type == AST_PARANTHESIS_OPEN)
				is_in_parenthesis += 1;
			else
				is_in_parenthesis -= 1;
			if (is_in_parenthesis < 0)
				ft_print_syntax_error(")");
		}
		if (is_in_parenthesis > 0)
		{
			index++;
			continue ;
		}
		if (node_precedence(nodes[index]) > highest_precedence)
		{
			highest_precedence = node_precedence(nodes[index]);
			highest_precedence_index = index;
		}
		index++;
	}
	printf("highest precedence: %d\n", highest_precedence);
	printf("highest precedence index: %d\n", highest_precedence_index);
}
