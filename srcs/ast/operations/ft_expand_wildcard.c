/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_wildcard.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:07:49 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/26 14:20:44 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_wildcard_data	*ft_init_wildcard_data(void)
{
	t_wildcard_data	*data;

	data = ft_malloc(sizeof(t_wildcard_data));
	data->dir = NULL;
	data->entry = NULL;
	data->show_hidden = false;
	data->result = ft_gc_safe(ft_strdup(""));
	data->count = 0;
	return (data);
}

static bool	ft_processe_file(char **result, const char *filename,
		const char *pattern)
{
	char	*tmp;

	tmp = ft_gc_safe(ft_strjoin(filename, " "));
	if (ft_match_pattern(filename, pattern))
	{
		*result = ft_gc_safe(ft_strjoin(*result, tmp));
		ft_free(tmp);
		return (true);
	}
	ft_free(tmp);
	return (false);
}

static struct dirent	*ft_readdir(DIR *dir, struct dirent **entry)
{
	*entry = readdir(dir);
	return (*entry);
}

void	expand_wildcard(char **pattern, t_wildcard_data *data)
{
	data->dir = opendir(".");
	if (data->dir == NULL)
	{
		perror("opendir");
		return ;
	}
	if (*pattern[0] == '.' || ft_strncmp(*pattern, "\".\"", 3) == 0
		|| ft_strncmp(*pattern, "'.'", 3) == 0)
		data->show_hidden = true;
	while (ft_readdir(data->dir, &data->entry) != NULL)
	{
		if (data->show_hidden == false && data->entry->d_name[0] == '.')
			continue ;
		if (ft_processe_file(&data->result, data->entry->d_name, *pattern))
			data->count++;
	}
	closedir(data->dir);
	if (data->count == 0)
		ft_free(data->result);
	else
	{
		ft_free(*pattern);
		*pattern = data->result;
	}
	ft_free(data);
}

void	ft_expand_wildcard(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		if (ft_strchr(arr[i], '*') != NULL || ft_strchr(arr[i], '?') != NULL)
		{
			expand_wildcard(&arr[i], ft_init_wildcard_data());
		}
		i++;
	}
}
