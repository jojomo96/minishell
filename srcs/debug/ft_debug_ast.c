/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug_ast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 08:11:00 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/09 12:59:07 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_debug_node_creation(t_ast_node *new_node)
{
	int	i;

	printf("DEBUG: New node created: ");
	if (new_node->type == AST_TYPE_LEAF)
	{
		i = 0;
		printf("Leaf: ");
		while (*new_node->u_data.leaf.argv)
		{
			printf("		arg[%d]: %s ", i, *new_node->u_data.leaf.argv);
			new_node->u_data.leaf.argv++;
			i++;
		}
		printf("\n");
	}
	else if (new_node->type == AST_TYPE_NODE)
		printf("Node:		%s\n",
			op_type_to_string(new_node->u_data.s_node.op_type));
	else if (new_node->type == AST_TYPE_PARANTHESIS)
	{
		if (new_node->u_data.type == AST_PARANTHESIS_OPEN)
			printf("Paranthesis: 	(\n");
		else
			printf("Paranthesis: 	)\n");
	}
}
