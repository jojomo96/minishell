/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarr_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 12:26:11 by flfische          #+#    #+#             */
/*   Updated: 2024/05/05 12:30:32 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Sorts a string array in ascending order.
 * @param arr The string array to sort.
 * @note The array must be NULL-terminated.
 * @note The array will be sorted in place.
 * @note The sorting is done using ft_strcmp.
 */
void	ft_strarr_sort(char **arr)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (arr[i])
	{
		j = i + 1;
		while (arr[j])
		{
			if (ft_strcmp(arr[i], arr[j]) > 0)
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
