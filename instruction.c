/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaman <mhaman@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 18:08:31 by mhaman            #+#    #+#             */
/*   Updated: 2021/10/21 13:11:15 by mhaman           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void rev_rotate_stack(t_list **stack, int code)
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
        write(STDOUT_FILENO, "rra\n", 4);
    else if (code == STACK_B)
        write(STDOUT_FILENO, "rrb\n", 4);
}

void rotate_stack(t_list **stack, int code)
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
        write(STDOUT_FILENO, "ra\n", 3);
    else if (code == STACK_B)
        write(STDOUT_FILENO, "rb\n", 3);
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
        write(STDOUT_FILENO, "sa\n", 3);
    else
        write(STDOUT_FILENO, "sb\n", 3);
}

void push_node(t_list **src, t_list **dst, int code)
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
        write(STDOUT_FILENO, "pa\n", 3);
    else
        write(STDOUT_FILENO, "pb\n", 3);
}