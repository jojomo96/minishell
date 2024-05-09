/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:49:37 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/09 09:17:29 by jmoritz          ###   ########.fr       */
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
static void	process_quotes(char *content, t_range_split *r, char *quote_type,
		int *in_quote)
{
	while (content[r->end] != '\0')
	{
		if ((content[r->end] == '\'' || content[r->end] == '\"')
			&& (*in_quote == 0 || content[r->end] == *quote_type))
		{
			if (*in_quote)
				*in_quote = 0;
			else
				*in_quote = 1;
			*quote_type = content[r->end];
		}
		r->end++;
		if (content[r->end] == ' ' && !(*in_quote))
			break ;
	}
}

static char	**ft_split_args_norm(char *content, char **args, char quote_type,
		int in_quote)
{
	t_range_split	r;

	r = ft_create_range_split();
	while (content[r.end] != '\0')
	{
		while (content[r.end] == ' ' && !in_quote)
			r.end++;
		r.start = r.end;
		process_quotes(content, &r, &quote_type, &in_quote);
		if (r.end > r.start)
			args[r.i++] = ft_strndup(content + r.start, r.end - r.start);
		if (content[r.end] != '\0')
			r.end++;
	}
	args[r.i] = NULL;
	return (args);
}

char	**ft_split_args(char *content)
{
	char	**args;
	char	quote_type;
	int		in_quote;

	args = (char **)malloc(sizeof(char *) * (ft_estimate_arg_count(content)
				+ 1));
	if (args == NULL)
		return (NULL); // TODO: handle error
	quote_type = 0;
	in_quote = 0;
	return (ft_split_args_norm(content, args, quote_type, in_quote));
}
