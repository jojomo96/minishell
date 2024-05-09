/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:42:04 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/09 09:15:36 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*dup;
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[len] && len < n)
	{
		len++;
	}
	dup = ft_malloc(len + 1);
	if (!dup)
	{
		return (NULL); //TODO: error handling
	}
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
