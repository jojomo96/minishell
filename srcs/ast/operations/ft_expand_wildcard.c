/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_wildcard.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:07:49 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/24 11:07:43 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	ft_processe_file(char **result, const char *filename,
		const char *pattern)
{
	char	*tmp;

	tmp = ft_strjoin(filename, " ");
	if (ft_match_pattern(filename, pattern))
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
		ft_free(*pattern);
		*pattern = result;
	}
}

void	ft_expand_wildcard(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		if (ft_strchr(arr[i], '*') != NULL || ft_strchr(arr[i], '?') != NULL)
			expand_wildcard(&arr[i]);
		i++;
	}
}
