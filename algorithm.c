/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaman <mhaman@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 10:26:46 by mhaman            #+#    #+#             */
/*   Updated: 2021/10/21 13:10:27 by mhaman           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

bool stack_sorted(t_list *stack_a, t_list *stack_b)
{
	int i = 0;
	int max = INT_MIN;

	move_top_list(&stack_b);
	move_top_list(&stack_a);
	while (1)
	{
		if (stack_b->order > max)
		{
			max = stack_b->order;
		}
		if (stack_b->next == NULL)
			break;
		stack_b = stack_b->next;
	}
	move_top_list(&stack_b);
	while (stack_b->order != 0)
	{
		stack_b = stack_b->next;
		if (stack_b->next == NULL && stack_b->order != 0)
			return (false);
	}
	if (stack_a == NULL)
	{
		while (stack_b->order == i)
		{
			stack_b = ptr_prev_node(stack_b);
			if (i  == max)
				return (true);
			i++;
		}
	}
	return (false);
}

int	calc_base_score(int *tab, t_list *value, t_list *stack_b)
{
	int min;
	int max;
	int i;

	max = INT_MIN;
	min = INT_MAX;
	i = 0;
	while (1) // Create min
	{
		if (min > stack_b->order)
			min = stack_b->order;
		if (stack_b->next == NULL)
			break;
		stack_b = stack_b->next;
	}
	while (1) // Create Max
	{
		if (max < stack_b->order)
			max = stack_b->order;
		if (stack_b->prev == NULL)
			break;
		stack_b = stack_b->prev;
	}
	if (value->order < min)
	{
		while (stack_b->order != max)
		{
			i++;
			stack_b = stack_b->next;
		}
		if (i > stack_size(ptr_top_node(stack_b)) / 2)
			return ((stack_size(ptr_top_node(stack_b)) - i) * -1);
		return (i);
	}
	if (value->order > max)
	{
		i++;
		while (stack_b->order != min)
		{
			i++;
			stack_b = stack_b->next;
		}
		if (i > stack_size(ptr_top_node(stack_b)) / 2)
			return ((stack_size(ptr_top_node(stack_b)) - i) * -1);
		return (i);
	}
	move_top_list(&stack_b);
	while (stack_b->next)
	{
		if (value->order > stack_b->order && value->order < ptr_prev_node(stack_b)->order )
			break;
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
	tab[STACK_B] = calc_base_score(tab, stack_a, ptr_top_node(stack_b));
	return (abs(tab[0]) + abs(tab[1]));	
}

void sort_stack(int tab[2], t_list **stack_a, t_list **stack_b)
{
	if (tab[STACK_A] > 0 && tab[STACK_B] > 0) // Optimisation RR
	{
		if (tab[STACK_A] >= tab[STACK_B])
		{
			while (tab[STACK_B] > 0)
			{
				rotate_stack(stack_a, 3);
				rotate_stack(stack_b, 3);
        		write(STDOUT_FILENO, "rr\n", 3);
				tab[STACK_B]--;
				tab[STACK_A]--;
			}
		}
		else
		{
			while (tab[STACK_A] > 0)
			{
				rotate_stack(stack_a, 3);
				rotate_stack(stack_b, 3);
        		write(STDOUT_FILENO, "rr\n", 3);
				tab[STACK_B]--;
				tab[STACK_A]--;
			}
		}
	}
	else if (tab[STACK_A] < 0 && tab[STACK_B] < 0)
	{
		if (tab[STACK_A] >= tab[STACK_B])
		{
			while (tab[STACK_A] < 0)
			{
				rev_rotate_stack(stack_a, 3);
				rev_rotate_stack(stack_b, 3);
        		write(STDOUT_FILENO, "rrr\n", 4);
				tab[STACK_B]++;
				tab[STACK_A]++;
			}
		}
		else
		{
			while (tab[STACK_B] < 0)
			{
				rev_rotate_stack(stack_a, 3);
				rev_rotate_stack(stack_b, 3);
        		write(STDOUT_FILENO, "rrr\n", 4);
				tab[STACK_B]++;
				tab[STACK_A]++;
			}
		}
	}
	if (tab[STACK_A] >= 0)
	{	
		while (tab[STACK_A]-- > 0)
		{
			rotate_stack(stack_a, STACK_A);
		}
	}
	else
	{	
		while (tab[STACK_A]++ < 0)
		{
			rev_rotate_stack(stack_a, STACK_A);
		}
	}
	if (tab[STACK_B] >= 0)
	{
		while (tab[STACK_B] > 0)
		{
			rotate_stack(stack_b, STACK_B);
			tab[STACK_B]--;
		}
	}
	else
	{
		while (tab[STACK_B] < 0)
		{
			rev_rotate_stack(stack_b, STACK_B);
			tab[STACK_B]++;
		}
	}
	push_node(stack_a, stack_b, STACK_B);
	tab[STACK_B] = 0;
	tab[STACK_A] = 0;
}

void push_back(t_list **stack_a, t_list **stack_b)
{
	const	int	maxsize = stack_size(*stack_b);
	int			opti;

	opti = 0;
	while ((*stack_b)->order != maxsize - 1)
	{
		opti++;
		*stack_b = (*stack_b)->next;
	}
	move_top_list(stack_b);
	if (opti > maxsize / 2)
	{
		opti = maxsize - opti;	
		while (opti-- > 0)
			rev_rotate_stack(stack_b, STACK_B);
	}
	else
		while (opti-- > 0)
			rotate_stack(stack_b, STACK_B);
	while (stack_size(*stack_a) < maxsize)
		push_node(stack_b,stack_a, STACK_A);
}

void algorithm(t_list **stack_a, t_list **stack_b)
{
	int     op[2];
	int		op2[2];
	int     nbop;

	op[STACK_A] = 0;
	op[STACK_B] = 0;
	nbop = INT_MAX;
	push_node(stack_a, stack_b, STACK_B);
	push_node(stack_a, stack_b, STACK_B);
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
		move_top_list(stack_b);
		move_top_list(stack_a);
		sort_stack(op2, stack_a, stack_b);
		nbop = INT_MAX;
	}  
		push_back(stack_a, stack_b);
}