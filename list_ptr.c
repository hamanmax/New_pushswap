/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_ptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaman <mhaman@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 12:10:10 by mhaman            #+#    #+#             */
/*   Updated: 2021/10/21 12:46:54 by mhaman           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_list	*ptr_top_node(t_list *stack)
{
	if (stack == NULL)
		return (NULL);
    while (stack->prev)
        stack = (stack)->prev;
    return (stack);
}

t_list	*ptr_bot_node(t_list *stack)
{
    while (stack && (stack)->next)
        stack = (stack)->next;
    return (stack);
}

t_list	*ptr_prev_node(t_list *stack)
{
    if (stack->prev)
        return (stack->prev);
    return (ptr_bot_node(stack));
}

t_list	*ptr_next_node(t_list *stack)
{
    if (stack->next)
        return (stack->next);
    return (ptr_top_node(stack));
}

int stack_size(t_list *stack)
{
    int i;

    i = 0;
    move_top_list( &stack);
    while (stack && stack->next)
    {
        i++;
        stack = stack->next;
    }
    if (stack != NULL)
        i++;
    return (i);
}