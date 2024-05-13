/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarr_join.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:50:04 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/13 16:00:40 by jmoritz          ###   ########.fr       */
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
