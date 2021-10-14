/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaman <mhaman@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 10:26:46 by mhaman            #+#    #+#             */
/*   Updated: 2021/10/14 19:02:22 by mhaman           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"



bool stack_sorted(t_list *stack_a, t_list *stack_b)
{
	return(true);
}

void algorithm(t_list **stack_a, t_list **stack_b)
{
	t_list *aptr;
	t_list *bptr;
	int     op[2];
	int     op2[2];
	t_list *prev;
	t_list *next;


	op[STACK_A] = 0;
	op[STACK_B] = 0;
	op2[STACK_A] = 0;
	op2[STACK_B] = 0;
	if ((*stack_a)->value == stack_size(*stack_a))
		rotate_stack(stack_a);
	push_node(stack_a, stack_b);
	aptr = ptr_first_node(*stack_a);
	bptr = ptr_first_node(*stack_b);
	prev = ptr_first_node(*stack_b);
	next = ptr_next_node(*stack_b);
	while(stack_sorted(*stack_a, *stack_b) == false)
	{
		while ((*stack_a)->next)
		{
			while (1)
			{
				if (calc_placement() == calc_placement() + 2)
				{
					if (i > calc_operation())
					{
						i = calc_operation();
						aptr = new_ptr;
					}
				}
				if ((*stack_b)->next == NULL)
					break;
				stack_b++;
			}
			stack_b = move_top_list(stack_b);
			stack_a++;
		} 
	}  
	}