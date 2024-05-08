/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:44:10 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/08 14:40:47 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_extract_tokens(t_ast_node **nodes, char *input, int *position,
		int *node_count)
{
	int		start;
	int		end;
	char	quote_type;

	start = *position;
	end = start;
	if (input[start] == '\'' || input[start] == '\"')
	{
		quote_type = input[end++];
		while (input[end] && input[end] != quote_type)
			end++;
		end++;
		while (input[end] && !ft_isspace(input[end]))
			end++;
	}
	else
	{
		while (input[end] && !ft_isspace(input[end]))
			end++;
	}
	if (start == end)
		return ;
	nodes[*node_count] = ft_ast_new_node(input, start, end - start);
	(*node_count)++;
	*position = end;
}

static void	ft_realloc_nodes(t_ast_node ***nodes, int *buffer_size,
		int node_count)
{
	int		new_buffer_size;
	t_ast_node	**new_nodes;

	if (node_count >= *buffer_size)
	{
		if (DEBUG)
			printf("DEBUG: Reallocating tokens\n");
		new_buffer_size = *buffer_size * 2 + 1;
		new_nodes = (t_ast_node **)ft_realloc(*nodes, sizeof(t_ast_node *)
				* (*buffer_size), sizeof(t_ast_node *) * new_buffer_size);
		if (!new_nodes)
			return ; //TODO handle error
		*nodes = new_nodes;
		*buffer_size = new_buffer_size;
	}
}

t_ast_node	**ft_tokenize_input(char *input)
{
	t_ast_node	**nodes;
	int		position;
	int		node_count;
	int		input_length;
	int		buffer_size;

	buffer_size = TOKEN_BUFFER_SIZE + 1;
	input_length = ft_strlen(input);
	nodes = (t_ast_node **)ft_malloc(sizeof(t_ast_node *) * buffer_size);
	if (!nodes) // TODO: handle error
		return (NULL);
	position = 0;
	node_count = 0;
	while (position < input_length)
	{
		if (ft_isspace(input[position]) && position++)
			continue ;
		ft_extract_tokens(nodes, input, &position, &node_count);
		ft_realloc_nodes(&nodes, &buffer_size, node_count);
	}
	nodes[node_count] = NULL;
	return (nodes);
}
