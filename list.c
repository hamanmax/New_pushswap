/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaman <mhaman@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 16:35:42 by mhaman            #+#    #+#             */
/*   Updated: 2021/10/06 14:20:37 by mhaman           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void create_node(t_list **lst, int value)
{
	t_list *temp;

	temp = malloc(sizeof(t_list));
	temp->data.chunk = 0;
	temp->data.value = value;
    temp->next = *lst;
	temp->prev = NULL;
    if ((*lst))
	    (*lst)->prev = temp;
	*lst = temp;
}

int pile_size(t_list *pile)
{
    int i;

    i = 0;
    move_top_list( &pile);
    while (pile && pile->next)
    {
        i++;
        pile = pile->next;
    }
    if (pile != NULL)
        i++;
    return (i);
}

void move_top_list(t_list **pile)
{
    while (*pile && (*pile)->prev)
    {
        *pile = (*pile)->prev;
    }
}

void show_pile_state(t_list *pilea, t_list *pileb)
{
    int i;

    if (pileb != NULL)
    {
        i = (pile_size(pilea) > pile_size(pileb));
        if ( i == 1)
            i = pile_size(pilea);
        else
            i = pile_size(pileb);
    }
    else
        i = pile_size(pilea);
    while (i > 0)
    {
        if (pilea != NULL && pileb != NULL)
            dprintf(2,"%d\t%d\n",pilea->data.value,pileb->data.value);
        else if (pilea == NULL && pileb)
            dprintf(2,"R\t%d\n", pileb->data.value);
        else
            dprintf(2,"%d\tR\n",pilea->data.value);
        if (pilea != NULL)
        pilea = pilea->next;
        if (pileb != NULL)
        pileb = pileb->next;
        i--;
    }
}