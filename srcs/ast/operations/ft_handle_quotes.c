/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_quotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:59:01 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/22 18:29:20 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_remove_outer_quotes(char **arr)
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
