/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:21:31 by flfische          #+#    #+#             */
/*   Updated: 2024/04/27 12:32:45 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

# include "minishell.h"

int		ft_env_index(char **env, char *key);
int		ft_env_add(char ***env, char *key, char *val);
int		ft_env_change(char ***env, char *key, char *val);
char	*ft_env_create_entry(char *key, char *val);
int		ft_env_remove(char ***env, char *key);
char	*ft_get_env(char **env, char *key);

#endif
