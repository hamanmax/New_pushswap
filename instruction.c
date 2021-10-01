/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaman <mhaman@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 18:08:31 by mhaman            #+#    #+#             */
/*   Updated: 2021/10/01 19:04:20 by mhaman           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void show_node_info(t_list node)
{
    dprintf(2,"Chunk\t=%d\nValue\t=%d\nCurrent\t=%p\nPrev\t=%p\nNext\t=%p\n\n",node.data.chunk,node.data.value,node,node.prev,node.next);
}


void rotate_pile(t_list **pile)
{
}

void rev_rotate_pile(t_list **pile)
{

}
void swap_node(t_list **pile)
{

}

void push_node(t_list **src, t_list **dst)
{

}