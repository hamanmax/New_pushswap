/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaman <mhaman@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 18:08:31 by mhaman            #+#    #+#             */
/*   Updated: 2021/10/11 15:22:23 by mhaman           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void show_node_info(t_list *node)
{
    dprintf(2,"Value\t=%d\nCurrent\t=%p\nPrev\t=%p\nNext\t=%p\n\n",node->value,node,node->prev,node->next);
}


void rotate_stack(t_list **stack)
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

}

void rev_rotate_stack(t_list **stack)
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

}
void swap_node(t_list **stack)
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
}

void push_node(t_list **src, t_list **dst)
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
}