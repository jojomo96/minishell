/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traverse_and_process.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 09:06:52 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/13 11:42:46 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fr_traverse_and_process(t_ast_node *root, t_ast_node_type node_type,
		void (*process)(t_ast_node *))
{
	if (root == NULL)
		return ;
	if (root->type == AST_TYPE_NODE)
	{
		fr_traverse_and_process(root->u_data.s_node.left, node_type, process);
		fr_traverse_and_process(root->u_data.s_node.right, node_type, process);
	}
	if (root->type == node_type)
		process(root);
}
