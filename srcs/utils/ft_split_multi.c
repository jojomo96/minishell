/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_multi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:15:11 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/14 07:48:47 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Function to split the string while keeping the delimiter
char	**ft_split_on_delim(const char *str, bool(delim)(char c))
{
	int		i;
	int		j;
	int		k;
	char	**result;
	char	*temp;
	bool	was_qestion_mark;

	result = malloc(sizeof(char *) * (ft_strlen(str) + 1));
	temp = malloc(sizeof(char) * (ft_strlen(str) + 2));
	i = 0;
	j = 0;
	k = 0;
	was_qestion_mark = false;
	while (str[i] != '\0')
	{
		if (!delim(str[i]) && !was_qestion_mark)
		{
			if(str[i] == '?')
				was_qestion_mark = true;
			temp[j++] = str[i++];
		}
		else
		{
			was_qestion_mark = false;
			temp[j] = '\0';
			if (j != 0)
				result[k++] = ft_strdup(temp);
			j = 0;
			temp[j] = str[i];
			while (str[i] == '\'' || str[i] == '\"' || str[i] == ' ')
			{
				i++;
				j++;
				temp[j] = '\0';
				result[k++] = ft_strdup(temp);
				j = 0;
				temp[j] = str[i];
			}
			i++;
			j++;
		}
	}
	if (j != 0)
	{
		temp[j] = '\0';
		result[k++] = ft_strdup(temp);
	}
	free(temp);
	result[k] = NULL;
	return (result);
}
