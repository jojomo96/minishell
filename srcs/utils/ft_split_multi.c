/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_multi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:15:11 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/13 14:21:16 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



// Function to split the string while keeping the delimiter
char	**splitString(const char *str, bool (delim)(char c), int *count)
{
	int		len;
	int		i;
	int		j;
	int		k;
	char	**result;
	char	*temp;

	len = ft_strlen(str);
	result = malloc(sizeof(char *) * (len + 1));
	temp = malloc(sizeof(char) * (len + 2));
	i = 0;
	j = 0;
	k = 0;
	while (str[i] != '\0')
	{
		if (!delim(str[i]))
			temp[j++] = str[i++];
		else
		{
			temp[j] = '\0';
			result[k++] = ft_strdup(temp);
			j = 0;
			temp[j++] = str[i++];
		}
	}
	if (j != 0)
	{
		temp[j] = '\0';
		result[k++] = ft_strdup(temp);
	}
	free(temp);
	result[k] = NULL;
	*count = k;
	return (result);
}
