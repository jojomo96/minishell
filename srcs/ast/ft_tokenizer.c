/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:44:10 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/22 12:54:49 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_starts_with_operator(const char *input, bool in_s_quotes,
		bool in_d_quotes)
{
	const char	*double_char_operators[] = {"<<", ">>", "&&", "||", NULL};
	const char	*single_char_operators[] = {"<", ">", "|", "(", ")", NULL};
	int			i;

	if (in_s_quotes || in_d_quotes)
		return (0);
	i = 0;
	while (double_char_operators[i])
	{
		if (ft_strncmp(input, double_char_operators[i], 2) == 0)
			return (2);
		i++;
	}
	i = 0;
	while (single_char_operators[i])
	{
		if (ft_strncmp(input, single_char_operators[i], 1) == 0)
			return (1);
		i++;
	}
	return (0);
}

static void	ft_extract_tokens(t_ast_node **nodes, char *input, int *position,
		int *node_count)
{
	int		start;
	int		end;
	bool	in_s_quotes;
	bool	in_d_quotes;

	in_s_quotes = false;
	in_d_quotes = false;
	start = *position;
	end = start;
	ft_toggle_quotes(input + start, &in_s_quotes, &in_d_quotes);
	if (ft_starts_with_operator(input + start, in_s_quotes, in_d_quotes))
		end += ft_starts_with_operator(input + start, in_s_quotes, in_d_quotes);
	else
	{
		while (input[end] && !ft_starts_with_operator(&input[end], in_s_quotes,
				in_d_quotes))
		{
			end++;
			ft_toggle_quotes(input + end, &in_s_quotes, &in_d_quotes);
		}
	}
	nodes[*node_count] = ft_ast_new_node(input, start, end - start);
	(*node_count)++;
	*position = end;
}

static void	ft_realloc_nodes(t_ast_node ***nodes, int *buffer_size,
		int node_count)
{
	int			new_buffer_size;
	t_ast_node	**new_nodes;

	if (node_count >= *buffer_size)
	{
		if (DEBUG)
			printf("DEBUG: Reallocating tokens\n");
		new_buffer_size = *buffer_size * 2 + 1;
		new_nodes = (t_ast_node **)ft_realloc(*nodes, sizeof(t_ast_node *)
				* (*buffer_size), sizeof(t_ast_node *) * new_buffer_size);
		*nodes = new_nodes;
		*buffer_size = new_buffer_size;
	}
}

t_ast_node	**ft_tokenize_input(char *input)
{
	t_ast_node	**nodes;
	int			position;
	int			node_count;
	int			input_length;
	int			buffer_size;

	buffer_size = TOKEN_BUFFER_SIZE + 1;
	input_length = ft_strlen(input);
	nodes = (t_ast_node **)ft_malloc(sizeof(t_ast_node *) * buffer_size);
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
