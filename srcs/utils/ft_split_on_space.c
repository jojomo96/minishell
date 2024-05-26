/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_on_space.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:00:00 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/26 13:30:51 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	find_next_space(char **end)
{
	bool	in_s_quotes;
	bool	in_d_quotes;

	in_s_quotes = false;
	in_d_quotes = false;
	while (**end != '\0')
	{
		ft_toggle_quotes(*end, &in_s_quotes, &in_d_quotes);
		if (!in_s_quotes && !in_d_quotes && ft_isspace(**end))
			break ;
		(*end)++;
	}
}

static void	find_last_space(char **end)
{
	char	*last_space;
	bool	in_s_quotes;
	bool	in_d_quotes;

	in_s_quotes = false;
	in_d_quotes = false;
	last_space = NULL;
	while (**end != '\0')
	{
		ft_toggle_quotes(*end, &in_s_quotes, &in_d_quotes);
		if (!in_s_quotes && !in_d_quotes)
		{
			if (ft_isspace(**end))
				last_space = *end;
			else if (last_space != NULL)
			{
				*end = last_space;
				return ;
			}
		}
		(*end)++;
	}
	if (last_space != NULL)
		*end = last_space;
}

static void	split_and_add(char *str, char **result, int *index, bool find_last)
{
	char	*start;
	char	*end;

	start = str;
	while (*start != '\0')
	{
		if (*start == '\0')
			break ;
		end = start;
		if (find_last)
			find_last_space(&end);
		else
			find_next_space(&end);
		if (*end == '\0')
		{
			result[(*index)++] = start;
			break ;
		}
		*end = '\0';
		result[(*index)++] = start;
		start = end + 1;
	}
}

static int	determine_size(char **array)
{
	int	size;
	int	i;
	int	j;

	size = 0;
	i = 0;
	while (array[i] != NULL)
	{
		j = 0;
		while (array[i][j] != '\0')
		{
			size++;
			j++;
		}
		i++;
	}
	return (size);
}

void	ft_split_on_space(char ***array, bool find_last_space)
{
	int		i;
	int		index;
	int		size;
	int		size_malloc;
	char	**result;

	i = 0;
	index = 0;
	size = 0;
	while ((*array)[size] != NULL)
		size++;
	size_malloc = determine_size(*array);
	result = (char **)ft_malloc(size_malloc * 10 * sizeof(char *));
	if (!result)
	{
		perror("Failed to allocate memory");
		return ;
	}
	while (i < size)
	{
		split_and_add((*array)[i], result, &index, find_last_space);
		i++;
	}
	result[index] = NULL;
	*array = result;
}
