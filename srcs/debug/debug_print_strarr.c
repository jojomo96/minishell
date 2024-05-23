/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print_strarr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:50:28 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/23 17:54:36 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	debug_print_strarr(char **arr)
{
	int	i;

	if (DEBUG)
		debug_message("Debug Print Start:");

	i = 0;
	while (arr[i])
	{
		debug_message_1("String at index", arr[i]);
		i++;
	}

	if (DEBUG)
		debug_message("Debug Print End.");
}

