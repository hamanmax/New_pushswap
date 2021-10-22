/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaman <mhaman@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 10:26:46 by mhaman            #+#    #+#             */
/*   Updated: 2021/10/21 19:11:34 by mhaman           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	set_minmax(int tab[2], t_list *stack)
{
	tab[MIN] = INT_MAX;
	tab[MAX] = INT_MIN;
	while (1)
	{
		if (tab[MIN] > stack->order)
			tab[MIN] = stack->order;
		if (stack->next == NULL)
			break ;
		stack = stack->next;
	}
	while (1)
	{
		if (tab[MAX] < stack->order)
			tab[MAX] = stack->order;
		if (stack->prev == NULL)
			break ;
		stack = stack->prev;
	}
}

int	set_stack_b_operation(t_list *stack, int minmax, bool sup)
{
	int	i;

	i = 0;
	if (sup == true)
		i = 1;
	while (stack->order != minmax)
	{
		i++;
		stack = stack->next;
	}
	if (i > stack_size(ptr_top_node(stack)) / 2)
		return ((stack_size(ptr_top_node(stack)) - i) * -1);
	return (i);
}

int	calc_base_score(t_list *value, t_list *stack_b)
{
	int	minmax[2];
	int	i;

	i = 0;
	set_minmax(minmax, stack_b);
	if (value->order < minmax[MIN])
		return (set_stack_b_operation(stack_b, minmax[MAX], false));
	if (value->order > minmax[MAX])
		return (set_stack_b_operation(stack_b, minmax[MIN], true));
	move_top_list(&stack_b);
	while (stack_b->next)
	{
		if (value->order > stack_b->order && value->order
			< ptr_prev_node(stack_b)->order)
			break ;
		i++;
		stack_b = stack_b->next;
	}
	if (i > stack_size(ptr_top_node(stack_b)) / 2)
		return ((stack_size(ptr_top_node(stack_b)) - i) * -1);
	return (i);
}

int	calc_operation(int *tab, t_list *stack_a, t_list *stack_b)
{
	t_list	*ptr;

	ptr = ptr_top_node(stack_a);
	tab[STACK_A] = 0;
	while (stack_a != ptr)
	{
		ptr = ptr_next_node(ptr);
		tab[STACK_A]++;
	}
	if (tab[STACK_A] > stack_size(ptr_top_node(stack_a)) / 2)
		tab[STACK_A] = (stack_size(ptr_top_node(stack_a)) - tab[STACK_A]) * -1;
	move_top_list(&stack_b);
	tab[STACK_B] = calc_base_score(stack_a, ptr_top_node(stack_b));
	return (abs(tab[0]) + abs(tab[1]));
}

void	algorithm(t_list **stack_a, t_list **stack_b)
{
	int	op[2];
	int	op2[2];
	int	nbop;

	op[STACK_A] = 0;
	op[STACK_B] = 0;
	nbop = INT_MAX;
	while (stack_sorted(ptr_top_node(*stack_a), ptr_top_node(*stack_b)) == 0)
	{
		while (1)
		{
			if (calc_operation(op, *stack_a, *stack_b) < nbop)
			{
				nbop = calc_operation(op, *stack_a, *stack_b);
				op2[STACK_A] = op[STACK_A];
				op2[STACK_B] = op[STACK_B];
			}
			if ((*stack_a)->next == NULL)
				break ;
			*stack_a = (*stack_a)->next;
		}
		sort_stack(op2, stack_a, stack_b);
		nbop = INT_MAX;
	}
	push_back(stack_a, stack_b);
}
