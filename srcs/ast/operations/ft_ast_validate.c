/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ast_validate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:08:09 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/24 19:49:54 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	ft_ast_validate(t_ast_node *node)
{
	if ((node->u_data.s_node.op_type == OP_REDIRECT_IN
			|| node->u_data.s_node.op_type == OP_REDIRECT_OUT
			|| node->u_data.s_node.op_type == OP_APPEND_OUT
			|| node->u_data.s_node.op_type == OP_HEREDOC))
	{
		if (node->u_data.s_node.right == NULL)
		{
			ft_print_syntax_error("newline");
			return (true);
		}
	}
	else if (node->u_data.s_node.left == NULL
		|| node->u_data.s_node.right == NULL)
	{
		ft_print_syntax_error(
			(char *)op_type_to_string(node->u_data.s_node.op_type));
		return (true);
	}
	return (false);
}
