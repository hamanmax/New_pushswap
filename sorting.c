/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaman <mhaman@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:08:42 by mhaman            #+#    #+#             */
/*   Updated: 2021/10/21 18:44:34 by mhaman           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_stack(int tab[2], t_list **stack_a, t_list **stack_b)
{
	move_top_list(stack_b);
	move_top_list(stack_a);
	if (tab[STACK_A] > 0 && tab[STACK_B] > 0)
		optimisation_rotate(tab, stack_a, stack_b);
	else if (tab[STACK_A] < 0 && tab[STACK_B] < 0)
		optimisation_rev_rotate(tab, stack_a, stack_b);
	if (tab[STACK_A] >= 0)
		while (tab[STACK_A]-- > 0)
			rotate_stack(stack_a, STACK_A);
	else
		while (tab[STACK_A]++ < 0)
			rev_rotate_stack(stack_a, STACK_A);
	if (tab[STACK_B] >= 0)
		while (tab[STACK_B]-- > 0)
			rotate_stack(stack_b, STACK_B);
	else
		while (tab[STACK_B]++ < 0)
			rev_rotate_stack(stack_b, STACK_B);
	push_node(stack_a, stack_b, STACK_B);
	tab[STACK_B] = 0;
	tab[STACK_A] = 0;
}

void	push_back(t_list **stack_a, t_list **stack_b)
{
	const int	maxsize = stack_size(*stack_b);
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
		push_node(stack_b, stack_a, STACK_A);
}

void	optimisation_rotate(int tab[2], t_list **stack_a, t_list **stack_b)
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

void	optimisation_rev_rotate(int tab[2], t_list **stack_a, t_list **stack_b)
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

bool	stack_sorted(t_list *stack_a, t_list *stack_b)
{
	if (stack_b == NULL)
	{
		while (stack_a->order < stack_a->next->order)
		{
			stack_a = stack_a->next;
			if (stack_a->next == NULL)
				return (true);
		}
		return (false);
	}
	if (stack_a != NULL)
		return (false);
	return (true);
}
