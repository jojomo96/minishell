/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_wildcard.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:07:49 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/22 14:55:06 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	match_pattern(const char *filename, const char *pattern)
{
	const char	*f = filename;
	const char	*p = pattern;

	while (*f && *p)
	{
		if (*p == '*')
		{
			p++;
			if (!*p)
				return (1);
			while (*f)
			{
				if (match_pattern(f, p))
					return (1);
				f++;
			}
			return (0);
		}
		else if (*p == '"')
		{
			p++;
			while (*p && *p != '"')
			{
				if (*p != *f)
					return (0);
				p++;
				f++;
			}
			if (*p == '"')
				p++;
		}
		else if (*p == '?')
		{
			if (!*f)
				return (0);
			p++;
			f++;
		}
		else
		{
			if (*p != *f)
				return (0);
			p++;
			f++;
		}
	}
	// Handle trailing '*'
	if (*p == '*')
		p++;
	return (!*f && !*p);
}

static bool ft_processe_file(char **result, const char *filename, const char *pattern)
{
	char	*tmp;

	tmp = ft_strjoin(filename, " ");
	if (match_pattern(filename, pattern))
	{
		*result = ft_strjoin(*result, tmp);
		free(tmp);
		return (true);
	}
	free(tmp);
	return (false);
}

void	expand_wildcard(char **pattern)
{
	DIR				*dir;
	struct dirent	*entry;
	bool			show_hidden;
	char			*result;
	int				count;

	result = ft_strdup("");
	count = 0;
	show_hidden = false;
	dir = opendir(".");
	if (dir == NULL)
	{
		perror("opendir");
		return ;
	}
	if (*pattern[0] == '.')
		show_hidden = true;
	while ((entry = readdir(dir)) != NULL)
	{
		if (show_hidden == false && entry->d_name[0] == '.')
			continue ;
		if (ft_processe_file(&result, entry->d_name, *pattern))
			count++;
	}
	closedir(dir);
	if (count == 0)
		free(result);
	else
	{
		free(*pattern);
		*pattern = result;
	}
}
