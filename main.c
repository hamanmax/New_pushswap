/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaman <mhaman@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 11:01:07 by mhaman            #+#    #+#             */
/*   Updated: 2021/10/21 19:10:58 by mhaman           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	simple_sort(t_list **stack_a)
{
	if (stack_size(*stack_a) == 2 && (*stack_a)->value > (*stack_a)->next->value)
		return (swap_node(stack_a, STACK_A));
}

void	free_stack(t_list *stack_a)
{
	if (stack_a)
	{
		while (stack_a->next)
		{
			stack_a = stack_a->next;
			free(stack_a->prev);
		}
		free(stack_a);
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	if (check_arg_format(argc, argv) == -1 ||fill_list(&stack_a, argv) == -1
		||check_for_doublon(stack_a) == -1)
		exit(write(STDOUT_FILENO, "Error\n", 7));
	move_top_list(&stack_a);
	calc_order(&stack_a);
	move_top_list(&stack_b);
	move_top_list(&stack_a);
	if (stack_size(stack_a) > 5 && stack_sorted(stack_a, stack_b) == false)
	{
		push_node(&stack_a, &stack_b, STACK_B);
		push_node(&stack_a, &stack_b, STACK_B);
		algorithm(&stack_a, &stack_b);
	}
	else if (stack_size(stack_a) < 6 && stack_sorted(stack_a, stack_b) == false)
		simple_sort(&stack_a);
	free_stack(ptr_top_node(stack_a));
	return (0);
}
