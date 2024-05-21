/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:09:31 by flfische          #+#    #+#             */
/*   Updated: 2024/05/21 20:16:20 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

void	debug_printgc(void);
void	ft_print_debug_node_creation(t_ast_node *new_node);
void	ft_print_debug_node(t_ast_node *node);
void	ft_print_debuge_node_array(t_ast_node **nodes);
void	debug_message(char *message);
void	debug_message_1(char *message, char *arg1);
void	debug_print_node(t_ast_node *node);

#endif
