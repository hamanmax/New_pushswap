/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaman <mhaman@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 16:35:42 by mhaman            #+#    #+#             */
/*   Updated: 2021/10/19 18:50:00 by mhaman           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void create_node(t_list **lst, int value)
{
	t_list *temp;

	temp = malloc(sizeof(t_list));
	temp->value = value;
    temp->next = *lst;
	temp->prev = NULL;
    if ((*lst))
	    (*lst)->prev = temp;
	*lst = temp;
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

void move_top_list(t_list **stack)
{
    while (*stack && (*stack)->prev)
    {
        *stack = (*stack)->prev;
    }
}

void move_bot_list(t_list **stack)
{
    while (*stack && (*stack)->next)
    {
        *stack = (*stack)->next;
    }
}


void    *move_above_node(t_list **stack)
{
    if ((*stack)->prev) 
    {
        *stack = (*stack)->prev;
        return(*stack);
    }
    return(NULL);
}

void    move_below_node(t_list **stack)
{
    if ((*stack)->next) 
        *stack = (*stack)->next;
}

t_list *ptr_top_node(t_list *stack)
{
    while (stack->prev)
    {
        stack = (stack)->prev;
    }
    return (stack);
}

t_list *ptr_bot_node(t_list *stack)
{
    while (stack && (stack)->next)
    {
        stack = (stack)->next;
    }
    return (stack);
}

t_list *ptr_prev_node(t_list *stack)
{
    if (stack->prev)
        return(stack->prev);
    return (ptr_top_node(stack));
}

t_list *ptr_next_node(t_list *stack)
{
    if (stack->next)
        return(stack->next);
    return (ptr_bot_node(stack));
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
            dprintf(2,"%d\t%d\n",stack_a->value,stack_b->value);
        else if (stack_a == NULL && stack_b)
            dprintf(2,"R\t%d\n", stack_b->value);
        else
            dprintf(2,"%d\tR\n",stack_a->value);
        if (stack_a != NULL)
        stack_a = stack_a->next;
        if (stack_b != NULL)
        stack_b = stack_b->next;
        i--;
    }
}