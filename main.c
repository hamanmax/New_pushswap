/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaman <mhaman@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 11:01:07 by mhaman            #+#    #+#             */
/*   Updated: 2021/10/13 11:21:35 by mhaman           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
	{
		ft_printf("Error\n");
		return (-1);
	}
	if (check_arg_format(argc, argv) == -1)
	{
		ft_printf("Error\n");
		return (-1);
	}
	if (fill_list(&stack_a, argc, argv) == -1)
	{
		ft_printf("Error\n");
		return (-1);
	}
	if (check_for_doublon(stack_a) == -1)
	{
		ft_printf("Error\n");
		return (-1);
	}
	calc_order(&stack_a);
	algorithm(&stack_a,&stack_b);
	move_top_list(&stack_b);
	move_top_list(&stack_a);
	free(stack_a);
	free(stack_b);
}
