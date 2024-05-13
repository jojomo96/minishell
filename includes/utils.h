/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:49:17 by flfische          #+#    #+#             */
/*   Updated: 2024/05/13 14:20:11 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "minishell.h"

char	**ft_strarr_cpy(char **arr);
void	ft_strarr_free(char **arr);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);
char	*ft_strndup(const char *s, size_t n);
void	ft_strarr_sort(char **arr);

int		ft_isquoted(char *str);
int		ft_strarr_len(char **arr);
char	**splitString(const char *str, bool (delim)(char c), int *count);

#endif
