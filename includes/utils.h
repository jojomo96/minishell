/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz <jmoritz@studen.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:49:17 by flfische          #+#    #+#             */
/*   Updated: 2024/05/04 09:21:49 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "minishell.h"

char	**ft_strarr_cpy(char **arr);
void	ft_strarr_free(char **arr);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);

#endif
