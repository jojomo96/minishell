/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:21:31 by flfische          #+#    #+#             */
/*   Updated: 2024/05/26 13:32:07 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

# include "minishell.h"

# define ENV_INV "not a valid identifier"

int		ft_env_index(char **env, char *key);
int		ft_env_add(char ***env, char *key, char *val);
int		ft_env_change(char ***env, char *key, char *val);
char	*ft_env_create_entry(char *key, char *val);
int		ft_env_remove(char ***env, char *key);
char	*ft_env_get(char **env, char *key);
int		ft_env_init(char ***env);
int		ft_valid_env_key(char *key);
int		ft_env_set(char ***env, char *key, char *val);
int		ft_env_set_both(t_shell *ms, char *key, char *val);
char	*ft_fetch_env_var(char *name);
int		ft_env_split(char *entry);

#endif
