/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarr_join.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:50:04 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/24 18:44:27 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strarr_join(char **arr)
{
	int		total_length;
	char	**temp;
	char	*result;

	if (arr == NULL)
		return (NULL);
	total_length = 1;
	temp = arr;
	while (*temp)
		total_length += ft_strlen(*temp++);
	result = (char *)ft_malloc(total_length);
	if (result == NULL)
		return (NULL);
	*result = '\0';
	temp = arr;
	while (*temp)
		ft_strlcat(result, *temp++, total_length);
	if (total_length)
		ft_strarr_free(arr);
	return (result);
}

char	*ft_strarr_join_del(char **arr, char del)
{
	int		total_length;
	char	**temp;
	char	*result;
	char	del_str[2];

	del_str[0] = del;
	del_str[1] = '\0';
	if (arr == NULL)
		return (NULL);
	total_length = 1;
	temp = arr;
	while (*temp)
		total_length += ft_strlen(*temp++) + 1;
	result = (char *)ft_malloc(total_length);
	*result = '\0';
	temp = arr;
	while (*temp)
	{
		ft_strlcat(result, *temp++, total_length);
		if (*temp)
			ft_strlcat(result, del_str, total_length);
	}
	if (total_length)
		ft_strarr_free(arr);
	return (result);
}
