/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ast_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:45:15 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/09 16:41:00 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

const char	*op_type_to_string(t_operation_type op_type)
{
	int			num_op_types;
	const char	*op_type_strings[] = {"<", ">",
			">>", "<<", "|", "&&", "||"};

	num_op_types = sizeof(op_type_strings) / sizeof(op_type_strings[0]);
	if ((int)op_type >= num_op_types)
	{
		return ("UNKNOWN_OP");
	}
	return (op_type_strings[op_type]);
}

void	url_encode(char *dest, const char *src)
{
	char	*d;

	// TODO: remove function
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
	static int	nullcount = 0;
	char		buffer[1024];
	char		label[512];
	int			i;

	if (node == NULL)
	{
		sprintf(buffer, "    null%d [shape=point];\n", nullcount++);
		strcat(graph, buffer);
		return ;
	}
	if (node->type == AST_TYPE_LEAF)
	{
		label[0] = '\0';
		i = 0;
		while (node->u_data.leaf.argv[i] != NULL)
		{
			if (i > 0)
				strcat(label, " ");
			strcat(label, node->u_data.leaf.argv[i]);
			i++;
		}
		sprintf(buffer, "    \"%p\" [label=\"%s\"];\n", (void *)node, label);
	}
	else
	{
		sprintf(buffer, "    \"%p\" [label=\"%s\"];\n", (void *)node,
			op_type_to_string(node->u_data.s_node.op_type));
	}
	strcat(graph, buffer);
	if (node->type == AST_TYPE_NODE)
	{
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
}

void	write_ast_to_dot_file(t_ast_node *root)
{
	char	*graph;
	char	*encoded_graph;

	// TODO: remove function
	graph = malloc(10000);
	if (!graph)
	{
		perror("Failed to allocate memory for graph");
		exit(EXIT_FAILURE);
	}
	strcpy(graph, "digraph AST {\n");
	print_dot(root, graph);
	strcat(graph, "}\n");
	encoded_graph = malloc(3 * strlen(graph) + 1);
	if (!encoded_graph)
	{
		perror("Failed to allocate memory for encoded graph");
		free(graph);
		exit(EXIT_FAILURE);
	}
	url_encode(encoded_graph, graph);
	printf("\e]8;;https://dreampuf.github.io/GraphvizOnline/#%s\e\\Tree\e]8;;\e\\\n",
		encoded_graph);
	char *url = ft_strjoin("https://dreampuf.github.io/GraphvizOnline/#", encoded_graph);
	char *args[] = {"open", url, NULL};
	execve("/usr/bin/open", args, NULL);

	free(url);


	printf("https://dreampuf.github.io/GraphvizOnline/#%s\n",
		encoded_graph);

	free(graph);
	free(encoded_graph);
}

t_range_split	ft_create_range_split(void)
{
	t_range_split	range;

	range.start = 0;
	range.end = 0;
	range.i = 0;
	return (range);
}
