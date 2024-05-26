/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quotes_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 14:28:43 by flfische          #+#    #+#             */
/*   Updated: 2024/05/26 14:32:49 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_encase_outer_quotes_in_array(char **arr)
{
	char	**splited_args;

	splited_args = ft_split_on_delim(*arr, &is_delimiter);
	encase_outer_quotes(splited_args);
	*arr = ft_strarr_join(splited_args);
}

char	*ft_dupe_quotes(char *str)
{
	char	*new_str;

	new_str = ft_strdup(str);
	ft_gc_safe(new_str);
	return (new_str);
}
