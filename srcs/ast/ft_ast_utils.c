/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ast_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:45:15 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/08 17:16:54 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

const char	*op_type_to_string(t_operation_type op_type)
{
	int			num_op_types;
	const char	*op_type_strings[] = {"OP_REDIRECT_IN", "OP_REDIRECT_OUT",
			"OP_APPEND_OUT", "OP_HEREDOC", "OP_PIPE", "OP_AND", "OP_OR",
			"OP_SUBSHELL"};

	num_op_types = sizeof(op_type_strings) / sizeof(op_type_strings[0]);
	if ((int)op_type >= num_op_types)
	{
		return ("UNKNOWN_OP");
	}
	return (op_type_strings[op_type]);
}

void	url_encode(char *dest, const char *src)
{
	//TODO: remove function
	char	*d;

	d = dest;
	for (; *src; src++)
	{
		if (('a' <= *src && *src <= 'z') || ('A' <= *src && *src <= 'Z')
			|| ('0' <= *src && *src <= '9'))
		{
			*d++ = *src;
		}
		else
		{
			sprintf(d, "%%%02X", (unsigned char)*src);
			d += 3;
		}
	}
	*d = '\0';
}

static void	print_dot(t_ast_node *node, char *graph)
{
	//TODO: remove function
	static int	nullcount = 0;
	char		buffer[1024];

	if (node == NULL)
	{
		sprintf(buffer, "    null%d [shape=point];\n", nullcount++);
		strcat(graph, buffer);
		return ;
	}
	if (node->type == AST_TYPE_LEAF)
	{
		sprintf(buffer, "    \"%p\" [label=\"%s\"];\n", (void *)node,
			node->u_data.leaf.value);
	}
	else
	{
		sprintf(buffer, "    \"%p\" [label=\"%s\"];\n", (void *)node,
			op_type_to_string(node->u_data.s_node.op_type));
	}
	strcat(graph, buffer);
	if (node->u_data.s_node.left != NULL)
	{
		print_dot(node->u_data.s_node.left, graph);
		sprintf(buffer, "    \"%p\" -> \"%p\";\n", (void *)node,
			(void *)node->u_data.s_node.left);
		strcat(graph, buffer);
	}
	if (node->u_data.s_node.right != NULL)
	{
		print_dot(node->u_data.s_node.right, graph);
		sprintf(buffer, "    \"%p\" -> \"%p\";\n", (void *)node,
			(void *)node->u_data.s_node.right);
		strcat(graph, buffer);
	}
}

void	write_ast_to_dot_file(t_ast_node *root)
{
	//TODO: remove function
	char *graph = malloc(10000);
	if (!graph)
	{
		perror("Failed to allocate memory for graph");
		exit(EXIT_FAILURE);
	}
	strcpy(graph, "digraph AST {\n");
	print_dot(root, graph);
	strcat(graph, "}\n");
	char *encoded_graph = malloc(3 * strlen(graph) + 1);
	if (!encoded_graph)
	{
		perror("Failed to allocate memory for encoded graph");
		free(graph);
		exit(EXIT_FAILURE);
	}
	url_encode(encoded_graph, graph);
	printf("https://dreampuf.github.io/GraphvizOnline/#%s\n", encoded_graph);
	free(graph);
	free(encoded_graph);
}
