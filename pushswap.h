/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaman <mhaman@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 15:56:24 by mhaman            #+#    #+#             */
/*   Updated: 2021/10/07 15:31:54 by mhaman           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
#include "42_libft/include/libft.h"
#include <limits.h>
#include <stdbool.h>

typedef struct s_list	t_list;

struct s_list
{
	t_list	*prev;
	int		value;
	t_list	*next;
};

/* Parsing Data */

int		check_arg_format(int argc, char **argv);
int		fill_list(t_list **stack, int argc, char **argv);
int		check_for_doublon(t_list *stack);
void	calc_order(t_list **stack);

/* List Fonction */

void	create_node(t_list **lst, int value);
void	initialize_node(t_list **stack);
void	move_top_list(t_list **stack);
void	show_stack_state(t_list *stack_a, t_list *stack_b);
void	show_node_info(t_list *node);
int		stack_size(t_list *stack);
t_list	*move_above_node(t_list **stack);


/* Instruction Fonction */
 
void	rotate_stack(t_list **stack);
void	rev_rotate_stack(t_list **stack);
void	swap_node(t_list **stack);
void	push_node(t_list **src, t_list **dst);

/* Algorythm Fonction */

void	algorithm(t_list **stack_a, t_list **stack_b);

#endif