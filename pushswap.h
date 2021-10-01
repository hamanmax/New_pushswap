/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaman <mhaman@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 15:56:24 by mhaman            #+#    #+#             */
/*   Updated: 2021/10/01 18:09:45 by mhaman           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
#include "42_libft/include/libft.h"
#include <limits.h>

typedef struct s_list	t_list;

typedef struct s_data
{
	int	value;
	int	chunk;
}				t_data;

struct s_list
{
	t_list	*prev;
	t_list	*next;
	t_data	data;
};

/* Parsing Data */

int		check_arg_format(int argc, char **argv);
int		fill_list(t_list **pile, int argc, char **argv);
int		check_for_doublon(t_list *pile);
void	calc_order(t_list **pile);

/* List Fonction */

void	create_node(t_list **lst, int value);
void	initialize_node(t_list **pile);
void	move_top_list(t_list **pile);
void	show_pile_state(t_list *pilea,t_list *pileb);
int		pile_size(t_list *pile);

/* Instruction Fonction */
 
void	rotate_pile(t_list **pile);
void	rev_rotate_pile(t_list **pile);
void	swap_node(t_list **pile);
void	push_node(t_list **src,t_list **dst);

/* Algorythm Fonction */

#endif