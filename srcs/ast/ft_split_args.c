/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:49:37 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/09 08:04:26 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	ft_is_quote(char c)
{
	return (c == '\'' || c == '\"');
}

int	ft_estimate_arg_count(const char *content)
{
	int		count;
	int		in_quotes;
	char	current_quote;

	count = 0;
	in_quotes = 0;
	current_quote = 0;
	while (*content)
	{
		while (*content == ' ')
			content++;
		if (*content == '\0')
			break ;
		if (!in_quotes && *content != ' ')
			count++;
		while (*content)
		{
			if (*content == '"' || *content == '\'')
			{
				if (in_quotes && *content == current_quote)
					in_quotes = 0;
				else if (!in_quotes)
				{
					in_quotes = 1;
					current_quote = *content;
				}
			}
			content++;
			if (!in_quotes && *content == ' ')
				break ;
			if (!in_quotes && (*content != ' ' && *content != '"'
					&& *content != '\''))
				break ;
		}
	}
	return (count);
}

char	**ft_split_args(char *content)
{
	char	**args;
	int		start;
	int		i;
	char	quote_type;
	int		in_quote;
	int		end;

	start = 0;
	start = 0;
	end = 0;
	i = 0;
	quote_type = 0;
	in_quote = 0;
	args = (char **)malloc(sizeof(char *) * (ft_estimate_arg_count(content)
				+ 1));
	if (args == NULL)
		return (NULL);
	while (content[end] != '\0')
	{
		while (content[end] == ' ' && !in_quote)
			end++;
		start = end;
		while (content[end] != '\0')
		{
			if ((content[end] == '"' || content[end] == '\'') && (in_quote == 0
					|| content[end] == quote_type))
			{
				if (in_quote)
					in_quote = 0;
				else
					in_quote = 1;
				quote_type = content[end];
			}
			end++;
			if (content[end] == ' ' && !in_quote)
				break ;
		}
		if (end > start)
			args[i++] = strndup(content + start, end - start);
		if (content[end] != '\0')
			end++;
	}
	args[i] = NULL;
	return (args);
}
