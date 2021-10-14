/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaman <mhaman@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 10:26:46 by mhaman            #+#    #+#             */
/*   Updated: 2021/10/13 12:08:21 by mhaman           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"



bool stack_sorted(t_list *stack_a, t_list *stack_b)
{
    return(true);
}

void algorithm(t_list **stack_a, t_list **stack_b)
{
    t_list *ptr;
    int     op[2];
    t_list *top;
    t_list *bot;


    op[STACK_A] = 0;
    op[STACK_B] = 0;
    if ((*stack_a)->value == stack_size(*stack_a))
        rotate_stack(stack_a);
    push_node(stack_a,stack_b);
    ptr = ptr_first_node(*stack_a);
    while(stack_sorted(*stack_a,*stack_b) == false)
    {
        if (ptr->value < (*stack_b)->value && ptr->value < ptr_next_node(*stack_b)->value)
            dprintf(2,"tutu\n");
        break;
    }
}