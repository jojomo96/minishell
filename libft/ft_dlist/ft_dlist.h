/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:40:27 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/23 00:46:43 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DLIST_H
# define FT_DLIST_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_dlist_node
{
	void				*content;
	struct s_dlist_node	*next;
	struct s_dlist_node	*prev;
}						t_dlist_node;

typedef struct s_dlist
{
	t_dlist_node		*head;
	t_dlist_node		*tail;
	size_t				size;
}						t_dlist;

t_dlist					*ft_dlist_new(void);
t_dlist_node			*ft_dlist_new_node(void *content);
t_dlist_node			*ft_dlist_new_node_deep(void *content,
							size_t content_size);

void					ft_dlist_destroy(t_dlist **lst, void (*del)(void *));
void					ft_dlist_node_destroy(t_dlist_node **node,
							void (*del)(void *));

void					ft_dlist_prepend(t_dlist *lst, t_dlist_node *new);
void					ft_dlist_append(t_dlist *lst, t_dlist_node *new);

void					ft_dlist_rotate(t_dlist *lst);
void					ft_dlist_reverse_rotate(t_dlist *lst);

t_dlist_node			*ft_dlist_pop_front(t_dlist *lst);
t_dlist_node			*ft_dlist_pop_back(t_dlist *lst);

t_dlist_node			*ft_dlist_peek_front(t_dlist *lst);
t_dlist_node			*ft_dlist_peek_back(t_dlist *lst);

t_dlist_node			*ft_dlist_find(t_dlist *lst, void *content,
							int (*cmp)(void *, void *));

size_t					ft_dlist_size(t_dlist *lst);

void					ft_dlist_print(t_dlist *lst,
							void (*print)(t_dlist_node *));
bool					ft_dlist_append_unique(t_dlist *lst, t_dlist_node *new,
							int (*cmp)(void *, void *));

void					ft_dlist_sort(t_dlist *lst, int (*cmp)(void *, void *));
t_dlist					*ft_dlist_sort_copy(t_dlist *lst, int (*cmp)(void *,
								void *), size_t content_size);

void					*ft_dlist_get(t_dlist *lst, int index);
int						ft_dlist_index_of(t_dlist *lst, void *content,
							int (*cmp)(void *, void *));

void					*ft_dlist_get_max(t_dlist *lst, int (*cmp)(void *,
								void *));
void					*ft_dlist_get_min(t_dlist *lst, int (*cmp)(void *,
								void *));
int						ft_dlist_is_sorted(t_dlist *lst, int (*cmp)(void *,
								void *));

#endif
