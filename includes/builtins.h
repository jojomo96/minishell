/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:20:36 by flfische          #+#    #+#             */
/*   Updated: 2024/05/06 17:52:33 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

int	ft_pwd(void);
int	ft_env(char ***envp);
int	ft_cd(char ***env, char *path);
int	ft_unset(char ***env, char **keys);
int	ft_export(char ***env, char ***exp, char **args);

// TODO:
// ft_echo
// ft_cd
// ft_export
// ft_unset
// ft_exit

#endif
