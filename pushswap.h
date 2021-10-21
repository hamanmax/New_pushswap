/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaman <mhaman@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 15:56:24 by mhaman            #+#    #+#             */
/*   Updated: 2021/10/21 18:03:24 by mhaman           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include "42_libft/include/libft.h"
# include <limits.h>
# include <stdbool.h>

# define STACK_A 0
# define STACK_B 1
# define MIN 0
# define MAX 1

typedef struct s_list	t_list;

struct s_list
{
	t_list	*prev;
	int		order;
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
void	free_stack(t_list *stack_a, t_list *stack_b);
void	move_top_list(t_list **stack);
void	move_bot_list(t_list **stack);
void	*move_above_node(t_list **stack);
void	move_below_node(t_list **stack);
t_list	*ptr_top_node(t_list *stack);
t_list	*ptr_bot_node(t_list *stack);
t_list	*ptr_next_node(t_list *stack);
t_list	*ptr_prev_node(t_list *stack);
int		stack_size(t_list *stack);

/* Instruction Fonction */

void	rotate_stack(t_list **stack, int code);
void	rev_rotate_stack(t_list **stack, int code);
void	swap_node(t_list **stack, int code);
void	push_node(t_list **src, t_list **dst, int code);

/* Algorythm Fonction */

void	algorithm(t_list **stack_a, t_list **stack_b);
void	push_back(t_list **stack_a, t_list **stack_b);
void	sort_stack(int tab[2], t_list **stack_a, t_list **stack_b);
int		calc_operation(int *tab, t_list *stack_a, t_list *stack_b);
int		calc_base_score(int *tab, t_list *value, t_list *stack_b);
bool	stack_sorted(t_list *stack_a, t_list *stack_b);
void	optimisation_rotate(int tab[2], t_list **stack_a, t_list **stack_b);
void	optimisation_rev_rotate(int tab[2], t_list **stack_a, t_list **stack_b);

/* Debug Fonction */

// void	show_node_info(t_list *node);
// void	show_stack_state(t_list *stack_a, t_list *stack_b);

#endif