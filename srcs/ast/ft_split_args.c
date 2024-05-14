/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:49:37 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/14 13:09:52 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// helper function for ft_estimate_arg_count
static void	process_segment(const char **content, int *in_quotes,
		char *current_quote)
{
	while (**content)
	{
		if (**content == '"' || **content == '\'')
		{
			if (*in_quotes && **content == *current_quote)
				*in_quotes = 0;
			else if (!*in_quotes)
			{
				*in_quotes = 1;
				*current_quote = **content;
			}
		}
		(*content)++;
		if (!*in_quotes && **content == ' ')
			break ;
		if (!*in_quotes && (**content != ' ' && **content != '"'
				&& **content != '\''))
			break ;
	}
}

static int	ft_estimate_arg_count(const char *content)
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
		process_segment(&content, &in_quotes, &current_quote);
	}
	return (count);
}

// helper function fot ft_spin_args_norm
static void	process_quotes(char *cont, int *end, char *quote_type,
		int *in_quote)
{
	while (cont[*end] != '\0')
	{
		if ((cont[*end] == '\'' || cont[*end] == '\"') && (*in_quote == 0
				|| cont[*end] == *quote_type))
		{
			if (*in_quote)
				*in_quote = 0;
			else
				*in_quote = 1;
			*quote_type = cont[*end];
		}
		*end += 1;
		if (cont[*end] == ' ' && !(*in_quote))
			break ;
	}
}

static char	**ft_split_args_norm(char *content, char **args, char quote_type,
		int in_quote)
{
	int	i;
	int	start;
	int	end;

	i = 0;
	end = 0;
	start = 0;
	while (content[end] != '\0')
	{
		while (content[end] == ' ' && !in_quote)
			end++;
		start = end;
		process_quotes(content, &end, &quote_type, &in_quote);
		if (end > start)
			args[i++] = ft_strndup(content + start, end - start);
		if (content[end] != '\0')
			end++;
	}
	args[i] = NULL;
	return (args);
}

char	**ft_split_args(char *content)
{
	char	**args;
	char	quote_type;
	int		in_quote;

	args = (char **)ft_malloc(sizeof(char *) * (ft_estimate_arg_count(content)
				+ 1));
	quote_type = 0;
	in_quote = 0;
	return (ft_split_args_norm(content, args, quote_type, in_quote));
}
