/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaman <mhaman@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 18:08:31 by mhaman            #+#    #+#             */
/*   Updated: 2021/10/06 14:21:51 by mhaman           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void show_node_info(t_list *node)
{
    dprintf(2,"Chunk\t=%d\nValue\t=%d\nCurrent\t=%p\nPrev\t=%p\nNext\t=%p\n\n",node->data.chunk,node->data.value,node,node->prev,node->next);
}


void rotate_pile(t_list **pile)
{
    t_list *tmp;
    tmp = *pile;
    while ((*pile)->next)
        *pile = (*pile)->next;
    tmp->prev = *pile;
    (*pile)->next = tmp;
    tmp = (*pile)->prev;
    tmp->next = NULL;
    (*pile)->prev = tmp;
    (*pile)->prev = NULL;
    move_top_list(pile);

}

void rev_rotate_pile(t_list **pile)
{
    t_list *tmp;

    tmp = *pile;
    (*pile)->next->prev = NULL;
    while ((*pile)->next)
        *pile = (*pile)->next;
    tmp->prev = (*pile);
    tmp->next = NULL;
    (*pile)->next = tmp;
    (*pile) = (*pile)->next;
    move_top_list((pile));

}
void swap_node(t_list **pile)
{
    void *next;
    void *prev;

    (*pile)->prev = (*pile)->next;
    (*pile)->next = (*pile)->next->next;
    (*pile) = (*pile)->prev;
    (*pile)->next->prev = (*pile)->prev;
    (*pile)->next = (*pile)->prev;
    (*pile)->prev = NULL;
    move_top_list(pile);
}

void push_node(t_list **src, t_list **dst)
{
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