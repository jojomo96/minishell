/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdellen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:18:29 by flfische          #+#    #+#             */
/*   Updated: 2024/03/26 13:20:04 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strdellen(const char *s, char del)
{
	int	size;

	size = 0;
	while (s[size] && s[size] != del)
		size++;
	return (size);
}
