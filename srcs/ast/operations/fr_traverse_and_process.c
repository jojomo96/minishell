/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_traverse_and_process.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 09:06:52 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/13 09:11:52 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fr_traverse_and_process(t_ast_node *node, t_ast_node_type node_type,
		void (*process)(t_ast_node *))
{
	if (node == NULL)
		return ;
	if (node->type == AST_TYPE_NODE)
	{
		fr_traverse_and_process(node->u_data.s_node.left, node_type, process);
		fr_traverse_and_process(node->u_data.s_node.right, node_type, process);
	}
	if (node->type == node_type)
		process(node);
}
