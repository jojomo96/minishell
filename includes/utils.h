/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:49:17 by flfische          #+#    #+#             */
/*   Updated: 2024/05/05 12:27:30 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "minishell.h"

char	**ft_strarr_cpy(char **arr);
void	ft_strarr_free(char **arr);
void	ft_strarr_sort(char **arr);

#endif
