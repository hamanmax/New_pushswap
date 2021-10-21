/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaman <mhaman@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 16:35:42 by mhaman            #+#    #+#             */
/*   Updated: 2021/10/21 13:00:12 by mhaman           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void    create_node(t_list **lst, int value)
{
	t_list *temp;

	temp = malloc(sizeof(t_list));
	temp->order = value;
    temp->value = value;
    temp->prev = *lst;
	temp->next = NULL;
    if ((*lst))
	    (*lst)->next = temp;
	*lst = temp;
}

void    move_top_list(t_list **stack)
{
    while (*stack && (*stack)->prev)
        *stack = (*stack)->prev;
}

void    move_bot_list(t_list **stack)
{
    while (*stack && (*stack)->next)
        *stack = (*stack)->next;
}


void    *move_above_node(t_list **stack)
{
    if ((*stack)->prev) 
    {
        *stack = (*stack)->prev;
        return (*stack);
    }
    return (NULL);
}

void    move_below_node(t_list **stack)
{
    if ((*stack)->next) 
        *stack = (*stack)->next;
}

void show_stack_state(t_list *stack_a, t_list *stack_b)
{
    int i;

    move_top_list(&stack_a);
    move_top_list(&stack_b);
    if (stack_b != NULL)
    {
        i = (stack_size(stack_a) > stack_size(stack_b));
        if ( i == 1)
            i = stack_size(stack_a);
        else
            i = stack_size(stack_b);
    }
    else
        i = stack_size(stack_a);
    while (i > 0)
    {
        if (stack_a != NULL && stack_b != NULL)
            dprintf(2,"%d\t%d\n",stack_a->order,stack_b->order);
        else if (stack_a == NULL && stack_b)
            dprintf(2,"R\t%d\n", stack_b->order);
        else
            dprintf(2,"%d\tR\n",stack_a->order);
        if (stack_a != NULL)
        stack_a = stack_a->next;
        if (stack_b != NULL)
        stack_b = stack_b->next;
        i--;
    }
}