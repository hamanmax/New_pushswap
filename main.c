/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaman <mhaman@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 11:01:07 by mhaman            #+#    #+#             */
/*   Updated: 2021/09/28 19:07:49 by mhaman           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "42_libft/include/libft.h"
#include <limits.h>

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

void create_node(t_list **lst, int value)
{
	t_list *temp;

	temp = malloc(sizeof(t_list));
	temp->data.chunk = 0;
	temp->data.value = value;
	temp->next = *lst;
	temp->prev = NULL;
	(*lst)->prev = temp;
	*lst = temp;
}

void initialize_node(t_list **pile)
{
	t_list *temp;

	temp = malloc(sizeof(t_list));
	temp->next = NULL;
	temp->prev = NULL;
	temp->data.chunk = -1;
	temp->data.value = 0;

	*pile = temp;
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
			if ((*pile)->data.chunk == -1)
			{
				(*pile)->data.value = nbr;
				(*pile)->data.chunk = 0;
			}
			create_node(pile,(int)nbr);
		}
		while (str[j] >= '0' && str[j] <= '9' || str[j] == '-')
		{
			j++;
		}
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
		dprintf(2,"[%d]\t[%d]\n",pile->data.value, tmp->data.value);
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

	int main(int argc, char **argv)
{
	t_list *pilea;
	t_list *pileb;

	initialize_node(&pilea);
	initialize_node(&pileb);
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
}
