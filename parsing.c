/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaman <mhaman@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 15:52:11 by mhaman            #+#    #+#             */
/*   Updated: 2021/10/01 17:54:22 by mhaman           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int check_arg_format(int argc, char **argv)
{
	int i;
	char *str;

	i = 1;
	str = argv[i];
	while (i < argc)
	{
		if ((*str >= '0' && *str <= '9') || *str == ' ' || *str == '-')
		{
			str++;
			if ((*(str - 1) == '-' && (*str < '0' || *str > '9')) ||
				*str == '-' && (*(str - 1) >= '0' && *(str - 1) <= '9'))
				return (-1);
		}
		else if (*str == 0)
			i++;
		else
			return (-1);
	}
	return (1 - 2 * (argc < 1));
}

int fill_list(t_list **pile, int argc, char **argv)
{
	int		i;
	int		j;
	long	nbr;
	char	*str;

	i = 1;
	j = 0;
	str = argv[i];
	
	int k = 0;
	while (i < argc)
	{
		while (str[j] == ' ')
			j++;
		nbr = ft_atol(str + j);
		if (nbr > INT_MAX || nbr < INT_MIN)
		{
			ft_printf("ErrorINTMAX\n");
			return (-1);
		}
		else
		{
			k++;
			if ((*pile)->data.chunk == -1)
			{
				(*pile)->data.value = nbr;
				(*pile)->data.chunk = 0;
			}
			else
				create_node(pile,(int)nbr);
		}
		while (str[j] >= '0' && str[j] <= '9' || str[j] == '-')
		{
			j++;
		}
		while (str[j] == ' ')
			j++;
		if (str[j] == 0)
		{
			i++;
			str = argv[i];
			j = 0;
		}
	}
}

int	check_for_doublon(t_list *pile)
{
	t_list *tmp;
	int value;

	tmp = pile->next;

	while (pile->next)
	{
		if (pile->data.value == tmp->data.value)
		{
			ft_printf("Error\n");
			return (-1);
		}
		if (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		else
		{
			pile = pile->next;
			if (tmp->prev == pile)
				break ;
			while (tmp->prev != pile)
			{
				tmp = tmp->prev;
			}
		}
	}
	return (0);
}

void calc_order(t_list **pile)
{
	t_list *tmp;

	tmp = *pile;

	while (1)
	{	
		if ((*pile)->data.value > tmp->data.value)
		{
			(*pile)->data.chunk++;
		}
		if (tmp->next)
			tmp = tmp->next;
		else if ((*pile)->next == NULL)
			break ;
		else
		{
			*pile = (*pile)->next;
			while (tmp->prev)
				tmp = tmp->prev;
		}
	}
	while (1)
	{
		(*pile)->data.value = (*pile)->data.chunk;
		(*pile)->data.chunk = 0;
		if ((*pile)->prev)
			*pile = (*pile)->prev;
		else
			break;
	}
}