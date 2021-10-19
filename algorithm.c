/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaman <mhaman@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 10:26:46 by mhaman            #+#    #+#             */
/*   Updated: 2021/10/19 18:17:03 by mhaman           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

bool stack_sorted(t_list *stack_a, t_list *stack_b)
{
	return(false);
}

int calc_base_score(int *tab, t_list *value, t_list *prev,t_list *next)
{
	int		i;
	int		stacksize;
	t_list *ptr;

	stacksize = stack_size(ptr_top_node(prev));
	dprintf(2,"ss = %d\n",stacksize);
	i = 0;
	while (stacksize >= 0)
	{
		if (value->value < next->value)
		{
			i++;
		}
		stacksize--;
		next = ptr_next_node(next);
	}
	stacksize = stack_size(ptr_top_node(prev));
	while (stacksize >= 0)
	{
		if (value->value > prev->value)
		{
			i++;
		}
		stacksize--;
		prev = ptr_prev_node(prev);
	}
	dprintf(2,"%d\n",i);
	return (i);
}

int	calc_score(int *tab, t_list *value, t_list *stack_b)
{
	return(0);
}

int	calc_operation(int *tab, t_list *stack_a, t_list *stack_b)
{
	int		base_score;
	int		new_score;
	t_list	*ptr;

	ptr = ptr_top_node(stack_a);
	//while (stack_a != ptr)
	//{
	//	ptr = ptr_next_node(ptr);
	//	tab[STACK_A]++;
	//}
	move_top_list(&stack_b);
	dprintf(2,"V->V=%d\tSb->V=%d\n",ptr_top_node(stack_b)->value,stack_b->value);
	//dprintf(2,"%d\n",calc_base_score(tab, ptr_top_node(stack_b), ptr_prev_node(stack_b),ptr_next_node(stack_b)));
	//dprintf(2,"%d\n",calc_base_score(tab, ptr_top_node(stack_a), stack_b, ptr_prev_node(stack_b)));
	//while (calc_base_score(tab, ptr_top_node(stack_b), stack_b) != (calc_score(tab, stack_a, stack_b) + 2))
	//{
	//	dprintf(2,"%d\t%d\n",calc_base_score(tab, stack_b, stack_b),calc_score(tab, stack_a, stack_b));
	//	stack_b = stack_b->next;
	//	tab[STACK_B]++;
	//}
	return (0);	
}

void algorithm(t_list **stack_a, t_list **stack_b)
{
	int     op[2];
	int     nbop;
	t_list	*bestptr;


	op[STACK_A] = 0;
	op[STACK_B] = 0;
	nbop = INT_MAX;
	if ((*stack_a)->value == stack_size(*stack_a))
		rotate_stack(stack_a);
	push_node(stack_a, stack_b);
	push_node(stack_a, stack_b);
	if ((*stack_b)->value < (*stack_b)->next->value)
	swap_node(stack_b);
	show_stack_state(*stack_a,*stack_b);
	puts("///////////////////////////////\n");
	while(stack_sorted(*stack_a, *stack_b) == false)
	{
		while (1)
		{
			if (calc_operation(op, *stack_a, *stack_b) < nbop)
			{
				nbop = calc_operation(op, *stack_a, *stack_b);
				bestptr = *stack_a;
			}
			if ((*stack_a)->next == NULL)
				break ;
			(*stack_a) = (*stack_a)->next;
			break;
		}
		break;
		//use_operation()
		move_top_list(stack_a);
	}  
}