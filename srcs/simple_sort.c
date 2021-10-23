/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaman <mhaman@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 00:27:30 by mhaman            #+#    #+#             */
/*   Updated: 2021/10/23 02:24:57 by mhaman           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

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

void	sort_three_last(t_list *stack_a, int mod)
{
	const int	order[3] = {stack_a->order + mod,
	stack_a->next->order + mod, stack_a->next->next->order + mod};

	if ((order[0] == 2 && order[1] == 4))
	{
		rev_rotate_stack(&stack_a, STACK_A);
		swap_node(&stack_a, STACK_A);
	}
	else if ((order[0] == 3 && order[1] == 4))
		rev_rotate_stack(&stack_a, STACK_A);
	else if ((order[0] == 3 && order[1] == 2))
		swap_node(&stack_a, STACK_A);
	else if ((order[0] == 4 && order[1] == 2))
		rotate_stack(&stack_a, STACK_A);
	else if ((order[0] == 4 && order[1] == 3))
	{
		rotate_stack(&stack_a, STACK_A);
		swap_node(&stack_a, STACK_A);
	}
}

void	five_size_sort(t_list **stack_a, t_list **stack_b)
{
	int		minmax[2];

	set_minmax(minmax, *stack_a);
	while (1)
	{
		if ((*stack_a)->order == minmax[MIN]
			|| (*stack_a)->order == minmax[MIN] + 1)
			push_node(stack_a, stack_b, STACK_B);
		if ((*stack_a)->order == minmax[MIN]
			|| (*stack_a)->order == minmax[MIN] + 1)
			push_node(stack_a, stack_b, STACK_B);
		if (stack_size(*stack_b) == 2)
			break ;
		rotate_stack(stack_a, STACK_A);
	}
	sort_three_last(*stack_a, 0);
	if ((*stack_b)->order == 0)
		swap_node(stack_b, STACK_B);
	push_node(stack_b, stack_a, STACK_A);
	push_node(stack_b, stack_a, STACK_A);
}

void	four_size_sort(t_list **stack_a, t_list **stack_b)
{
	int		minmax[2];

	set_minmax(minmax, *stack_a);
	while (1)
	{
		if ((*stack_a)->order == minmax[MIN])
			push_node(stack_a, stack_b, STACK_B);
		if (stack_size(*stack_b) == 1)
			break ;
		rotate_stack(stack_a, STACK_A);
	}
	sort_three_last(*stack_a, 1);
	push_node(stack_b, stack_a, STACK_A);
}

void	simple_sort(t_list **stack_a, t_list **stack_b)
{
	if (stack_size(*stack_a) == 2)
		return (swap_node(stack_a, STACK_A));
	else if (stack_size(*stack_a) == 3)
		sort_three_last(*stack_a, 2);
	else if (stack_size(*stack_a) == 4)
		four_size_sort(stack_a, stack_b);
	else if (stack_size(*stack_a) == 5)
		five_size_sort(stack_a, stack_b);
}
