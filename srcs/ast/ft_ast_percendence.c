/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ast_percendence.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:55:21 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/09 15:45:58 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_node_precedence(t_ast_node *node)
{
	if (node->type == AST_TYPE_LEAF || node->type == AST_TYPE_PARANTHESIS)
		return (-2);
	if (node->u_data.s_node.op_type == OP_REDIRECT_IN
		|| node->u_data.s_node.op_type == OP_REDIRECT_OUT
		|| node->u_data.s_node.op_type == OP_APPEND_OUT
		|| node->u_data.s_node.op_type == OP_HEREDOC)
		return (1);
	else if (node->u_data.s_node.op_type == OP_PIPE)
		return (2);
	else if (node->u_data.s_node.op_type == OP_AND
		|| node->u_data.s_node.op_type == OP_OR)
		return (4);
	else if (node->u_data.s_node.op_type == OP_SUBSHELL)
		return (3);
	else
		return (0);
}

static void	ft_handle_parenthesis(t_ast_node *node, int *is_in_parenthesis)
{
	if (node->u_data.type == AST_PARANTHESIS_OPEN)
		(*is_in_parenthesis) += 1;
	else
		(*is_in_parenthesis) -= 1;
	if ((*is_in_parenthesis) < 0)
		ft_print_syntax_error(")");
}

int	find_highest_precedence_index(t_ast_node **nodes, int *is_in_parenthesis)
{
	int	index;
	int	highest_precedence;
	int	highest_precedence_index;

	index = 0;
	highest_precedence = 0;
	highest_precedence_index = -1;
	while (nodes[index])
	{
		if (nodes[index]->type == AST_TYPE_PARANTHESIS)
			ft_handle_parenthesis(nodes[index], is_in_parenthesis);
		if (!(*is_in_parenthesis > 0)
			&& ft_node_precedence(nodes[index]) >= highest_precedence)
		{
			highest_precedence = ft_node_precedence(nodes[index]);
			highest_precedence_index = index;
		}
		index++;
	}
	return (highest_precedence_index);
}
