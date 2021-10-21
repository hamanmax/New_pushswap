/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaman <mhaman@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 11:01:07 by mhaman            #+#    #+#             */
/*   Updated: 2021/10/21 13:10:01 by mhaman           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void free_stack(t_list *stack_a, t_list *stack_b)
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

int main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	if (check_arg_format(argc, argv) == -1 || 
	fill_list(&stack_a, argc, argv) == -1 || check_for_doublon(stack_a) == -1)
	{
		write(STDOUT_FILENO, "Error\n", 7);
		exit(EXIT_FAILURE);
	}
	move_top_list(&stack_a);
	calc_order(&stack_a);
	move_top_list(&stack_b);
	move_top_list(&stack_a);
	algorithm(&stack_a, &stack_b);
	//show_stack_state(stack_a,stack_b);
	free_stack(ptr_top_node(stack_a), ptr_top_node(stack_b));
	return (0);
}
