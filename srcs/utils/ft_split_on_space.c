/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_on_space.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:00:00 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/23 18:11:57 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	find_next_space(char **end, bool *in_s_quotes, bool *in_d_quotes)
{
	while (**end != '\0')
	{
		ft_toggle_quotes(*end, in_s_quotes, in_d_quotes);
		if (!*in_s_quotes && !*in_d_quotes && ft_isspace(**end))
			break ;
		(*end)++;
	}
}

static void	split_and_add(char *str, char **result, int *index)
{
	char	*start;
	char	*end;
	bool	in_s_quotes;
	bool	in_d_quotes;

	in_s_quotes = false;
	in_d_quotes = false;
	start = str;
	while (*start != '\0')
	{
		while (*start == ' ')
			start++;
		if (*start == '\0')
			break ;
		end = start;
		find_next_space(&end, &in_s_quotes, &in_d_quotes);
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

	size = 0;
	while (array[size] != NULL)
	{
		size++;
	}
	return (size);
}

void	ft_split_on_space(char ***array)
{
	int		i;
	int		index;
	int		size;
	char	**result;

	i = 0;
	index = 0;
	size = determine_size(*array);
	result = (char **)ft_malloc(size * 10 * sizeof(char *));
	if (!result)
	{
		perror("Failed to allocate memory");
		return ;
	}
	while (i < size)
	{
		split_and_add((*array)[i], result, &index);
		i++;
	}
	result[index] = NULL;
	*array = result;
}
