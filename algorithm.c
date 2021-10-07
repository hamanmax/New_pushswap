/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaman <mhaman@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 10:26:46 by mhaman            #+#    #+#             */
/*   Updated: 2021/10/07 18:48:35 by mhaman           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"



bool stack_sorted(t_list *stack_a, t_list *stack_b)
{
    return(true);
}

void algorithm(t_list **stack_a, t_list **stack_b)
{
    if ((*stack_a)->value == stack_size(*stack_a))
        rotate_stack(stack_a);
    push_node(stack_a,stack_b);
    while(stack_sorted(*stack_a,*stack_b) == false)
    {
        if ((*stack_a)->value )
    }
}