/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_create_entry.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:41:47 by flfische          #+#    #+#             */
/*   Updated: 2024/05/06 18:09:49 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Creates an entry for the environment.
 * @param key The key of the entry.
 * @param val The value of the entry.
 * @return The entry on success, NULL on error.
 */
char	*ft_env_create_entry(char *key, char *val)
{
	char	*entry;
	int		i;

	i = 0;
	if (val == NULL)
		return (ft_strdup(key));
	entry = malloc(ft_strlen(key) + ft_strlen(val) + 2);
	if (!entry)
		return (NULL);
	while (*key)
		entry[i++] = *key++;
	entry[i++] = '=';
	while (*val)
		entry[i++] = *val++;
	entry[i] = '\0';
	return (entry);
}
