/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaman <mhaman@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 11:01:07 by mhaman            #+#    #+#             */
/*   Updated: 2021/10/06 14:21:46 by mhaman           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int main(int argc, char **argv)
{
	t_list *pilea;
	t_list *pileb;

	pilea = NULL;
	pileb = NULL;
	if (argc == 1)
	{
		ft_printf("Error\n");
		return (-1);
	}
	if (check_arg_format(argc, argv) == -1)
	{
		ft_printf("Error\n");
		return (-1);
	}
	if (fill_list(&pilea, argc, argv) == -1)
	{
		ft_printf("Error\n");
		return (-1);
	}
	if (check_for_doublon(pilea) == -1)
	{
		ft_printf("Error\n");
		return (-1);
	}
	calc_order(&pilea);
	show_pile_state(pilea,pileb);
	puts("tutu\n");
	show_pile_state(pilea,pileb);
}
