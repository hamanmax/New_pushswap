/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaman <mhaman@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 15:56:24 by mhaman            #+#    #+#             */
/*   Updated: 2021/10/20 20:05:45 by mhaman           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
#include "42_libft/include/libft.h"
#include <limits.h>
#include <stdbool.h>


#define STACK_A 0
#define STACK_B 1

typedef struct s_list	t_list;

struct s_list
{
	t_list	*prev;
	int		value;
	int		order;
	t_list	*next;
};

/* Parsing Data */

int		check_arg_format(int argc, char **argv);
int		fill_list(t_list **stack, int argc, char **argv);
int		check_for_doublon(t_list *stack);
void	calc_order(t_list **stack);

/* List Fonction */

void	create_node(t_list **lst, int value);
void	move_top_list(t_list **stack);
void	move_bot_list(t_list **stack);
void    *move_above_node(t_list **stack);
void    move_below_node(t_list **stack);
t_list	*ptr_top_node(t_list *stack);
t_list	*ptr_last_node(t_list *stack);
t_list	*ptr_next_node(t_list *stack);
t_list	*ptr_prev_node(t_list *stack);
void	show_stack_state(t_list *stack_a, t_list *stack_b);
void	show_node_info(t_list *node);
int		stack_size(t_list *stack);


/* Instruction Fonction */
 
void	rotate_stack(t_list **stack,int code);
void	rev_rotate_stack(t_list **stack,int code);
void	swap_node(t_list **stack,int code);
void	push_node(t_list **src, t_list **dst,int code);

/* Algorythm Fonction */

void	algorithm(t_list **stack_a, t_list **stack_b);

#endif