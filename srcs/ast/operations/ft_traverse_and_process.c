/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traverse_and_process.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 09:06:52 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/24 19:52:47 by jmoritz          ###   ########.fr       */
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

bool	ft_traverse_process_return(t_ast_node *root,
		t_ast_node_type node_type, bool (*process)(t_ast_node *))
{
	bool	ret;

	if (root == NULL)
		return (false);
	if (root->type == AST_TYPE_NODE)
	{
		ret = ft_traverse_process_return(root->u_data.s_node.left,
				node_type, process);
		if (ret)
			return (true);
		ret = ft_traverse_process_return(root->u_data.s_node.right,
				node_type, process);
		if (ret)
			return (true);
	}
	if (root->type == node_type)
		return (process(root));
	return (false);
}
