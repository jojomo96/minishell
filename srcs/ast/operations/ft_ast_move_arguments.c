/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ast_move_arguments.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 10:53:28 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/15 11:27:54 by test             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	ft_is_redirect(t_ast_node *node)
{
	t_operation_type	type;

	if (node->type != AST_TYPE_NODE)
		return (false);
	type = node->u_data.s_node.op_type;
	return (type == OP_REDIRECT_IN || type == OP_REDIRECT_OUT
		|| type == OP_APPEND_OUT || type == OP_HEREDOC);
}

static void	ft_ast_find_leftmost_leaf(t_ast_node *origin, t_ast_node **dst)
{
	if (*dst == NULL)
	{
		origin->u_data.s_node.left = ft_ast_new_node("", 0, 0);
		*dst = origin->u_data.s_node.left;
	}
	while (*dst && (*dst)->type == AST_TYPE_NODE
		&& (*dst)->u_data.s_node.left != NULL)
		*dst = (*dst)->u_data.s_node.left;
	if ((*dst)->u_data.s_node.left == NULL)
		(*dst)->u_data.s_node.left = ft_ast_new_node("", 0, 0);
}

static void	ft_ast_move_arguments_help(t_ast_node *origin, t_ast_node *dst,
		t_ast_node *src)
{
	int	dst_argv_len;
	int	src_argv_len;
	int	i;

	if (src->type != AST_TYPE_LEAF)
		return ;
	ft_ast_find_leftmost_leaf(origin, &dst);
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
	if (node->type != AST_TYPE_NODE)
		return ;
	if (ft_is_redirect(node))
		ft_ast_move_arguments_help(node, node->u_data.s_node.left,
			node->u_data.s_node.right);
}
