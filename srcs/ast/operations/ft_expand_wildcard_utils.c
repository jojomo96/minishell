/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_wildcard_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:25:16 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/24 11:05:00 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	process_star(const char *f, const char *p)
{
	p++;
	if (!*p)
		return (1);
	while (*f)
	{
		if (ft_match_pattern(f, p))
			return (1);
		f++;
	}
	return (0);
}

static int	process_quotes(const char **f, const char **p)
{
	(*p)++;
	while (**p && **p != '"')
	{
		if (**p != **f)
			return (0);
		(*p)++;
		(*f)++;
	}
	if (**p == '"')
		(*p)++;
	return (1);
}

static int	process_character(const char **f, const char **p)
{
	if (**p == '?')
	{
		if (!**f)
			return (0);
		(*p)++;
		(*f)++;
	}
	else
	{
		if (**p != **f)
			return (0);
		(*p)++;
		(*f)++;
	}
	return (1);
}

int	ft_match_pattern(const char *filename, const char *pattern)
{
	const char	*f = filename;
	const char	*p = pattern;

	while (*f && *p)
	{
		if (*p == '*')
			return (process_star(f, p));
		else if (*p == '"')
		{
			if (!process_quotes(&f, &p))
				return (0);
		}
		else
		{
			if (!process_character(&f, &p))
				return (0);
		}
	}
	if (*p == '*')
		p++;
	return (!*f && !*p);
}
