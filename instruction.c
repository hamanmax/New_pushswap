/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaman <mhaman@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 18:08:31 by mhaman            #+#    #+#             */
/*   Updated: 2021/10/21 13:03:53 by mhaman           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void rev_rotate_stack(t_list **stack,int code)
{
    t_list *tmp;
    tmp = *stack;
    while ((*stack)->next)
        *stack = (*stack)->next;
    tmp->prev = *stack;
    (*stack)->next = tmp;
    tmp = (*stack)->prev;
    tmp->next = NULL;
    (*stack)->prev = tmp;
    (*stack)->prev = NULL;
    move_top_list(stack);
    if (code == STACK_A)
        dprintf(1,"rra\n");
    else if (code == STACK_B)
        dprintf(1,"rrb\n");
}

void rotate_stack(t_list **stack,int code)
{
    t_list *tmp;

    tmp = *stack;
    (*stack)->next->prev = NULL;
    while ((*stack)->next)
        *stack = (*stack)->next;
    tmp->prev = (*stack);
    tmp->next = NULL;
    (*stack)->next = tmp;
    (*stack) = (*stack)->next;
    move_top_list((stack));
    if (code == STACK_A)
        dprintf(1,"ra\n");
    else if (code == STACK_B)
        dprintf(1,"rb\n");
}
void swap_node(t_list **stack,int code)
{
    void *next;
    void *prev;

    (*stack)->prev = (*stack)->next;
    (*stack)->next = (*stack)->next->next;
    (*stack) = (*stack)->prev;
    (*stack)->next->prev = (*stack)->prev;
    (*stack)->next = (*stack)->prev;
    (*stack)->prev = NULL;
    move_top_list(stack);
    if (code == STACK_A)
        dprintf(1,"sa\n");
    else
        dprintf(1,"sb\n");
}

void push_node(t_list **src, t_list **dst,int code)
{
    move_top_list(src);
    if (*dst == NULL)
    {
        *dst = *src;
        *src = (*src)->next;
        (*src)->prev = NULL;
        (*dst)->prev = NULL;
        (*dst)->next = NULL;
    }
    else
    {
        (*dst)->prev = (*src);
        if ((*src)->next)
        {
            *src = (*src)->next;
            (*src)->prev = NULL;
        }
        else
            *src = NULL;
        (*dst)->prev->next = (*dst);
        (*dst) = (*dst)->prev;
    }
    if (code == STACK_A)
        dprintf(1,"pa\n");
    else
        dprintf(1,"pb\n");
}