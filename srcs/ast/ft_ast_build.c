/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ast_build.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:05:31 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/24 19:03:44 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_split_nodes(t_ast_node **nodes, t_ast_node ***left_nodes,
		t_ast_node ***right_nodes, int index)
{
	int	i;
	int	total_nodes;
	int	left_nodes_count;
	int	right_nodes_count;

	total_nodes = 0;
	while (nodes[total_nodes])
		total_nodes++;
	left_nodes_count = index;
	right_nodes_count = total_nodes - index - 1;
	*left_nodes = ft_malloc(sizeof(t_ast_node *) * (left_nodes_count + 1));
	*right_nodes = ft_malloc(sizeof(t_ast_node *) * (right_nodes_count + 1));
	i = 0;
	while (nodes[i])
	{
		if (i < index)
			(*left_nodes)[i] = nodes[i];
		else if (i > index)
			(*right_nodes)[i - index - 1] = nodes[i];
		i++;
	}
	(*left_nodes)[left_nodes_count] = NULL;
	(*right_nodes)[right_nodes_count] = NULL;
}

static bool	ft_remove_surrounding_parenthesis(t_ast_node ***nodes)
{
	int			pre_size;
	t_ast_node	**new_nodes;
	t_ast_node	**temp;

	pre_size = 0;
	while ((*nodes)[pre_size])
		pre_size++;
	if (pre_size < 2)
		return (false);
	new_nodes = ft_malloc(sizeof(t_ast_node *) * (pre_size - 1));
	ft_memcpy(new_nodes, *nodes + 1, sizeof(t_ast_node *) * (pre_size - 2));
	new_nodes[pre_size - 2] = NULL;
	temp = *nodes;
	*nodes = new_nodes;
	ft_free(temp);
	return (true);
}

void	ft_handle_ast_type_leaf_or_perentisis(t_ast_node **ast,
		t_ast_node **nodes)
{
	if (nodes[0] && nodes[0]->type == AST_TYPE_LEAF)
		*ast = nodes[0];
	else if (nodes[0] && nodes[0]->type == AST_TYPE_PARANTHESIS)
	{
		if (!ft_remove_surrounding_parenthesis(&nodes) || nodes[0] == NULL)
		{
			ft_print_syntax_error(")");
			return ;
		}
		build_ast(ast, nodes);
	}
}

// Use this function to build your AST
void	build_ast(t_ast_node **ast, t_ast_node **nodes)
{
	int			highest_precedence_index;
	int			is_in_parenthesis;
	t_ast_node	**left_nodes;
	t_ast_node	**right_nodes;

	left_nodes = NULL;
	right_nodes = NULL;
	highest_precedence_index = 0;
	is_in_parenthesis = 0;
	highest_precedence_index = find_highest_precedence_index(nodes,
			&is_in_parenthesis);
	if (highest_precedence_index == -1)
		ft_handle_ast_type_leaf_or_perentisis(ast, nodes);
	else
	{
		ft_split_nodes(nodes, &left_nodes, &right_nodes,
			highest_precedence_index);
		build_ast(&nodes[highest_precedence_index]->u_data.s_node.left,
			left_nodes);
		build_ast(&nodes[highest_precedence_index]->u_data.s_node.right,
			right_nodes);
		*ast = nodes[highest_precedence_index];
	}
}
