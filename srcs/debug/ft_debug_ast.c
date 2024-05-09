/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug_ast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 08:11:00 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/09 16:41:46 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_debug_node(t_ast_node *node)
{
	int	i;
	if (node->type == AST_TYPE_LEAF)
	{
		i = 0;
		printf("Leaf: ");
		while (node->u_data.leaf.argv[i])
		{
			printf("		arg[%d]: %s ", i, node->u_data.leaf.argv[i]);
			i++;
		}
		printf("\n");
	}
	else if (node->type == AST_TYPE_NODE)
		printf("Node:		%s\n",
					op_type_to_string(node->u_data.s_node.op_type));
	else if (node->type == AST_TYPE_PARANTHESIS)
	{
		if (node->u_data.type == AST_PARANTHESIS_OPEN)
			printf("Paranthesis: 	(\n");
		else
			printf("Paranthesis: 	)\n");
	}
}

void	ft_print_debug_node_creation(t_ast_node *new_node)
{
	printf("DEBUG: New node created: ");
	ft_print_debug_node(new_node);
}

void	ft_print_debuge_node_array(t_ast_node **nodes)
{
	int	i;

	i = 0;
	printf("DEBUG: Printing node array\n");
	while (nodes && nodes[i])
	{
		printf("	Node[%d]: ", i);
		ft_print_debug_node(nodes[i]);
		i++;
	}
}
