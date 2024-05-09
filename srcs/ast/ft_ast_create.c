/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ast_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:29:51 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/09 12:56:10 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_get_operation_type(char *value, int *is_op,
		t_operation_type *op_type)
{
	*is_op = 1;
	if (ft_strcmp(value, "<") == 0)
		*op_type = OP_REDIRECT_IN;
	else if (ft_strcmp(value, ">") == 0)
		*op_type = OP_REDIRECT_OUT;
	else if (ft_strcmp(value, ">>") == 0)
		*op_type = OP_APPEND_OUT;
	else if (ft_strcmp(value, "<<") == 0)
		*op_type = OP_HEREDOC;
	else if (ft_strcmp(value, "&&") == 0)
		*op_type = OP_AND;
	else if (ft_strcmp(value, "|") == 0)
		*op_type = OP_PIPE;
	else if (ft_strcmp(value, "||") == 0)
		*op_type = OP_OR;
	else if (ft_strcmp(value, "(") == 0)
		*is_op = -1;
	else if (ft_strcmp(value, ")") == 0)
		*is_op = -2;
	else
		*is_op = 0;
}

static void	ft_set_node_type(t_ast_node *new_node, int is_operator,
		t_operation_type op_type, char *content)
{
	if (is_operator == 1)
	{
		new_node->type = AST_TYPE_NODE;
		new_node->u_data.s_node.op_type = op_type;
		new_node->u_data.s_node.left = NULL;
		new_node->u_data.s_node.right = NULL;
		ft_free(content);
	}
	else if (is_operator == -1 || is_operator == -2)
	{
		new_node->type = AST_TYPE_PARANTHESIS;
		if (is_operator == -1)
			new_node->u_data.type = AST_PARANTHESIS_OPEN;
		if (is_operator == -2)
			new_node->u_data.type = AST_PARANTHESIS_CLOSE;
		ft_free(content);
	}
	else
	{
		new_node->type = AST_TYPE_LEAF;
		new_node->u_data.leaf.argv = (char **)ft_malloc(sizeof(char *) * 2);
		if (new_node->u_data.leaf.argv == NULL)
			return ; // TODO: handle error
		new_node->u_data.leaf.argv = ft_split_args(content);
	}
}

t_ast_node	*ft_ast_new_node(const char *input, size_t start,
		size_t value_length)
{
	t_ast_node			*new_node;
	t_operation_type	op_type;
	char				*content;
	int					is_operator;

	new_node = (t_ast_node *)ft_malloc(sizeof(t_ast_node));
	if (new_node == NULL)
		return (NULL); // TODO: handle error
	content = (char *)ft_malloc(sizeof(char) * (value_length + 1));
	if (content == NULL)
		return (ft_free(new_node), NULL); // TODO: handle error
	ft_strlcpy(content, input + start, value_length + 1);
	ft_get_operation_type(content, &is_operator, &op_type);
	ft_set_node_type(new_node, is_operator, op_type, content);
	if (DEBUG)
		ft_print_debug_node_creation(new_node);
	return (new_node);
}

void	ft_ast_free_node(t_ast_node *node)
{
	char	**args;

	if (!node)
		return ;
	if (node->type == AST_TYPE_LEAF)
	{
		if (node->u_data.leaf.argv)
		{
			args = node->u_data.leaf.argv;
			while (*args)
			{
				ft_free(*args);
				args++;
			}
			ft_free(node->u_data.leaf.argv);
			node->u_data.leaf.argv = NULL;
		}
	}
	else if (node->type == AST_TYPE_NODE)
	{
		ft_ast_free_node(node->u_data.s_node.left);
		ft_ast_free_node(node->u_data.s_node.right);
	}
	ft_free(node);
}
