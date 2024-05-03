/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz <jmoritz@studen.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:44:10 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/03 16:01:59 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_extract_tokens(t_token **tokens, char *input, int *position,
		int *token_count)
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
	tokens[*token_count] = ft_token_new(input, start, end - start);
	(*token_count)++;
	*position = end;
}

static void	ft_realloc_tokens(t_token ***tokens, int *buffer_size,
		int token_count)
{
	int		new_buffer_size;
	t_token	**new_tokens;

	if (token_count >= *buffer_size)
	{
		new_buffer_size = *buffer_size * 2 + 1;
		new_tokens = (t_token **)realloc(*tokens, sizeof(t_token *)
				* new_buffer_size);
		if (!new_tokens)
			return ; //TODO handle error
		*tokens = new_tokens;
		*buffer_size = new_buffer_size;
	}
}

t_token	**ft_tokenize_input(char *input)
{
	t_token	**tokens;
	int		position;
	int		token_count;
	int		input_length;
	int		buffer_size;

	buffer_size = TOKEN_BUFFER_SIZE;
	input_length = ft_strlen(input);
	tokens = (t_token **)ft_malloc(sizeof(t_token *) * (buffer_size + 1));
	if (!tokens) // TODO: handle error
		return (NULL);
	position = 0;
	token_count = 0;
	while (position < input_length)
	{
		if (ft_isspace(input[position]) && position++)
			continue ;
		ft_extract_tokens(tokens, input, &position, &token_count);
		ft_realloc_tokens(&tokens, &buffer_size, token_count);
	}
	tokens[token_count] = NULL;
	return (tokens);
}
