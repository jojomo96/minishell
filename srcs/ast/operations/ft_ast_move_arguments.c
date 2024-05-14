/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ast_move_arguments.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 10:53:28 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/13 09:49:16 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_ast_move_arguments_help(t_ast_node *dst, t_ast_node *src)
{
	int	dst_argv_len;
	int	src_argv_len;
	int	i;

	if (src->type != AST_TYPE_LEAF)
		return ;
	// find leftmost leaf
	while (dst->type == AST_TYPE_NODE)
		dst = dst->u_data.s_node.left;
	if (dst->u_data.leaf.argv == NULL || src->u_data.leaf.argv == NULL)
		return ;
	dst_argv_len = ft_strarr_len(dst->u_data.leaf.argv);
	src_argv_len = ft_strarr_len(src->u_data.leaf.argv);
	if (src_argv_len <= 1)
		return ;
	dst->u_data.leaf.argv = ft_realloc(dst->u_data.leaf.argv, sizeof(char *)
			* (dst_argv_len + 1), sizeof(char *) * (dst_argv_len
				+ src_argv_len));
	ft_memcpy(dst->u_data.leaf.argv + dst_argv_len, src->u_data.leaf.argv + 1,
		sizeof(char *) * (src_argv_len - 1));
	dst->u_data.leaf.argv[dst_argv_len + src_argv_len - 1] = NULL;
	i = 1;
	while (src->u_data.leaf.argv[i])
		src->u_data.leaf.argv[i++] = NULL;
}

void	ft_ast_move_arguments(t_ast_node *node)
{
	ft_ast_move_arguments_help(node->u_data.s_node.left,
		node->u_data.s_node.right);
}
