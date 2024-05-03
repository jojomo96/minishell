/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:56:05 by flfische          #+#    #+#             */
/*   Updated: 2024/04/29 16:24:23 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include "minishell.h"

void	ft_print_error(char *error, char *arg1, char *arg2);
void	ft_print_error_env(char *error, char *arg1, char *key);

#endif