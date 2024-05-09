/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:09:31 by flfische          #+#    #+#             */
/*   Updated: 2024/05/09 14:24:30 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

void	debug_printgc(void);
void	ft_print_debug_node_creation(t_ast_node *new_node);
void	ft_print_debug_node(t_ast_node *node);
void	ft_print_debuge_node_array(t_ast_node **nodes);

#endif
