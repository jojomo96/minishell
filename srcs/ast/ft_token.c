/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz <jmoritz@studen.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:29:51 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/03 15:56:21 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

e_token_type	ft_get_token_type(char *token_content)
{
	if (ft_strcmp(token_content, "<") == 0)
		return (NODE_REDIRECT_IN);
	if (ft_strcmp(token_content, ">") == 0)
		return (NODE_REDIRECT_OUT);
	if (ft_strcmp(token_content, ">>") == 0)
		return (NODE_APPEND_OUT);
	if (ft_strcmp(token_content, "<<") == 0)
		return (NODE_HEREDOC);
	if (ft_strcmp(token_content, "&&") == 0)
		return (NODE_AND);
	if (ft_strcmp(token_content, "|") == 0)
		return (NODE_PIPE);
	if (ft_strcmp(token_content, "||") == 0)
		return (NODE_OR);
	if (ft_strcmp(token_content, "(") == 0)
		return (NODE_SUBSHELL);
	if (ft_strcmp(token_content, ")") == 0)
		return (NODE_SUBSHELL);
	return (NODE_ARGUMENT);
}

t_token	*ft_token_new(const char *input, size_t start, size_t token_length)
{
	t_token	*token;
	char	*token_content;

	token = (t_token *)ft_malloc(sizeof(t_token));
	if (!token)
		return (NULL); // TODO: handle error
	token_content = (char *)ft_malloc(sizeof(char) * (token_length + 1));
	if (!token_content)
	{
		free(token);
		return (NULL); // TODO: handle error
	}
	ft_strlcpy(token_content, input + start, token_length + 1);
	token->content = token_content;
	token->type = ft_get_token_type(token_content);
	return (token);
}

void	ft_token_free(t_token *token)
{
	free(token->content);
	free(token);
}

void	ft_tokens_free(t_token **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		ft_token_free(tokens[i]);
		i++;
	}
	free(tokens);
}
