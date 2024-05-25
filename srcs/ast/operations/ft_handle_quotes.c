/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_quotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:59:01 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/25 16:44:05 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_delimiter(char c)
{
	return (!ft_isalnum(c) && c != '_' && c != '*');
}

void	remove_outer_quotes(char **arr)
{
	bool	in_s_quotes;
	bool	in_d_quotes;
	int		i;

	in_s_quotes = false;
	in_d_quotes = false;
	i = 0;
	while (arr[i])
	{
		if (arr[i][0] == '\'' && !in_d_quotes)
		{
			in_s_quotes = !in_s_quotes;
			arr[i][0] = '\0';
		}
		else if (arr[i][0] == '\"' && !in_s_quotes)
		{
			in_d_quotes = !in_d_quotes;
			arr[i][0] = '\0';
		}
		i++;
	}
}

void	ft_remove_outer_quotes_in_array(char ***arr)
{
	int		i;
	char	**splited_args;

	i = 0;
	while ((*arr)[i] != NULL)
	{
		splited_args = ft_split_on_delim((*arr)[i], &is_delimiter);
		remove_outer_quotes(splited_args);
		(*arr)[i] = ft_strarr_join(splited_args);
		i++;
	}
}

void	ft_toggle_quotes(char *arr, bool *in_s_quotes, bool *in_d_quotes)
{
	if (arr == NULL || *arr == '\0')
		return ;
	if (arr[0] == '\'' && !*in_d_quotes)
	{
		*in_s_quotes = !*in_s_quotes;
	}
	if (arr[0] == '\"' && !*in_s_quotes)
	{
		*in_d_quotes = !*in_d_quotes;
	}
}
