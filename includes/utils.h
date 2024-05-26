/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:49:17 by flfische          #+#    #+#             */
/*   Updated: 2024/05/26 18:14:46 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "minishell.h"

typedef struct s_split_state
{
	int				str_idx;
	int				buffer_idx;
	int				result_idx;
	char			**result;
	char			*buffer;
	bool			found_exit_code;
}					t_split_state;

typedef struct s_wildcard_data
{
	DIR				*dir;
	struct dirent	*entry;
	bool			show_hidden;
	char			*result;
	int				count;
}					t_wildcard_data;

typedef struct s_in_quotes
{
	bool			in_s_quotes;
	bool			in_d_quotes;
}					t_in_quotes;

char				**ft_strarr_cpy(char **arr);
void				ft_strarr_free(char **arr);
void				*ft_realloc(void *ptr, size_t old_size, size_t new_size);
char				*ft_strndup(const char *s, size_t n);
void				ft_strarr_sort(char **arr);

int					ft_isquoted(char *str);
int					ft_isdir(char *path);
int					ft_strarr_len(char **arr);
char				**ft_split_on_delim(const char *str, bool(delim)(char c));
char				*ft_strarr_join(char **arr);
char				*ft_strarr_join_del(char **arr, char del);
void				ft_split_on_space(char ***array, bool find_last);
void				ft_remove_all_quotes(char *str);
char				*ft_strjoin_free(char *s1, char *s2, int to_free);
t_in_quotes			ft_init_quotes(void);
void				free_split(char **split);

#endif
