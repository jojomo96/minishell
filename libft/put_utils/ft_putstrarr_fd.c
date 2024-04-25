/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrarr_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:32:09 by flfische          #+#    #+#             */
/*   Updated: 2024/03/26 13:34:30 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Outputs each string in the array to the given file descriptor.
 * The array must be NULL-terminated.
 * @param arr array of strings
 * @param fd file descriptor
 */
void	ft_putstrarr_fd(char **arr, int fd)
{
	while (*arr)
	{
		ft_putstr_fd(*arr, fd);
		ft_putchar_fd('\n', fd);
		arr++;
	}
}
