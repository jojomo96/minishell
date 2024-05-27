/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print_ast.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:35:57 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/27 16:36:44 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	url_encode(char *dest, const char *src)
{
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

static void	escape_quotes(const char *input, char *output)
{
	while (*input)
	{
		if (*input == '\"')
		{
			*output++ = '\\';
		}
		else if (*input == '\'')
		{
			*output++ = '\\';
		}
		*output++ = *input++;
	}
	*output = '\0';
}

static void	print_dot(t_ast_node *node, char *graph)
{
	static int	nullcount = 0;
	char		buffer[1024];
	char		label[512];
	int			i;
	char		escaped_label[1024];

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
		escape_quotes(label, escaped_label);
		sprintf(buffer, "    \"%p\" [label=\"%s\"];\n", (void *)node,
			escaped_label);
	}
	else if (node->type == AST_TYPE_NODE)
	{
		sprintf(buffer, "    \"%p\" [shape=diamond, label=\"%s\"];\n",
			(void *)node, op_type_to_string(node->u_data.s_node.op_type));
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
			sprintf(buffer, "    \"%p\" [color=red];\n",
				(void *)node->u_data.s_node.left);
			strcat(graph, buffer);
			sprintf(buffer, "    \"%p\" -> \"%p\";\n", (void *)node,
				(void *)node->u_data.s_node.left);
			strcat(graph, buffer);
		}
		if (node->u_data.s_node.right != NULL)
		{
			print_dot(node->u_data.s_node.right, graph);
			sprintf(buffer, "    \"%p\" [color=green];\n",
				(void *)node->u_data.s_node.right);
			strcat(graph, buffer);
			sprintf(buffer, "    \"%p\" -> \"%p\";\n", (void *)node,
				(void *)node->u_data.s_node.right);
			strcat(graph, buffer);
		}
	}
}

void	start_graph(t_ast_node *root, char *graph)
{
	strcpy(graph, "digraph AST {\n");
	print_dot(root, graph);
	strcat(graph, "    // Legend\n");
	strcat(graph, "    subgraph cluster_01 {\n");
	strcat(graph, "        label = \"Legend\";\n");
	strcat(graph, "        color = black;\n");
	strcat(graph, "        style = \"filled\";\n");
	strcat(graph, "        fillcolor = \"lightgrey\";\n");


	strcat(graph, "        key [label=<<table border=\"0\" cellpadding=\"2\" cellspacing=\"0\" cellborder=\"0\">\n");

	strcat(graph, "               <tr><td align=\"right\" port=\"i1\"> </td><td bgcolor=\"red\">Left</td></tr>\n");

	strcat(graph, "               <tr><td align=\"right\" port=\"i2\"> </td><td bgcolor=\"green\">Right</td></tr>\n");

	strcat(graph, "             </table>> shape=none];\n");
	strcat(graph, "        rankdir=LR;\n");
	strcat(graph, "        node [style=invis];\n");
	strcat(graph, "        edge [style=invis];\n");
	strcat(graph, "    }\n");
	strcat(graph, "}\n");
}

void	write_ast_to_dot_file(t_ast_node *root)
{
	char	*graph;
	char	*encoded_graph;
	char	*url;
	char	*args[3] = {"/usr/bin/open", NULL, NULL};
	pid_t	pid;

	// TODO: remove function
	if (!DEBUG)
		return ;
	graph = malloc(10000);
	if (!graph)
	{
		perror("Failed to allocate memory for graph");
		exit(EXIT_FAILURE);
	}
	start_graph(root, graph);
	encoded_graph = malloc(3 * strlen(graph) + 1);
	if (!encoded_graph)
	{
		perror("Failed to allocate memory for encoded graph");
		free(graph);
		exit(EXIT_FAILURE);
	}
	url_encode(encoded_graph, graph);

	printf("\e]8;;https://dreampuf.github.io/GraphvizOnline/#%s\e\\Tree\e]8;;\e\\\n", encoded_graph);
	url = ft_strjoin("https://dreampuf.github.io/GraphvizOnline/#",
			encoded_graph);
	args[1] = url;
	if (OPEN_AST)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("Failed to fork");
			free(graph);
			free(encoded_graph);
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			execve("/usr/bin/open", args, NULL);
			perror("Failed to execute open");
			free(graph);
			free(encoded_graph);
			exit(EXIT_FAILURE);
		}
		else
		{
			waitpid(pid, NULL, 0);
		}
	}
	free(url);
	free(graph);
	free(encoded_graph);
}
