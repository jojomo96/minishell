/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_all_quotes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:24:41 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/25 17:26:23 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_remove_all_quotes(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '"' && str[i] != '\'')
		{
			str[j] = str[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
}
