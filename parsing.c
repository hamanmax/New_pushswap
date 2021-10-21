/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaman <mhaman@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 15:52:11 by mhaman            #+#    #+#             */
/*   Updated: 2021/10/21 11:57:54 by mhaman           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		check_arg_format(int argc, char **argv)
{
	int		i;
	char	*str;

	i = 1;
	str = argv[i];
	while (i < argc)
	{
		if ((*str >= '0' && *str <= '9') || *str == ' ' || *str == '-')
		{
			str++;
			if (((*(str - 1) == '-' && (*str < '0' || *str > '9'))) ||
			(*str == '-' && (*(str - 1) >= '0' && *(str - 1) <= '9')))
				return (-1);
		}
		else if (*str == 0)
			i++;
		else
			return (-1);
	}
	return (1 - 2 * (argc < 1));
}

int		fill_list(t_list **stack, int argc, char **argv)
{
	int		j;
	long	nbr;

	j = 0;
	argv++;
	while (*argv)
	{
		while ((*argv)[j] == ' ')
			j++;
		nbr = ft_atol((*argv) + j);
		if (nbr > INT_MAX || nbr < INT_MIN)
			return (-1);
		create_node(stack,(int)nbr);
		while (((*argv)[j] >= '0' && (*argv)[j] <= '9') || (*argv)[j] == '-')
			j++;
		while ((*argv)[j] == ' ')
			j++;		
		if ((*argv)[j] == 0)
		{
			argv++;
			j = 0;
		}
	}
	return (0);
}

int		check_for_doublon(t_list *stack)
{
	t_list	*tmp;
	int		value;

	move_top_list(&stack);
	tmp = stack->next;
	while (stack->next)
	{
		if (stack->order == tmp->order)
			return (-1);
		if (tmp->next != NULL)
			tmp = tmp->next;
		else
		{
			stack = stack->next;
			if (tmp->prev == stack)
				break ;
			while (tmp->prev != stack)
				tmp = tmp->prev;
		}
	}
	return (0);
}

void	calc_order(t_list **stack)
{
	t_list	*ptr;
	int		*tmp;

	ptr = *stack;
	tmp = ft_calloc(stack_size(*stack), sizeof(int));
	while (1)
	{	
		if ((*stack)->order > ptr->order)
			(*tmp)++;
		if (ptr->next)
			ptr = ptr->next;
		else if ((*stack)->next == NULL)
			break ;
		else
		{
			tmp++;
			*stack = (*stack)->next;
			move_top_list(&ptr);
		}
	}
	ptr->value = ptr->order;
	ptr->order = *tmp;
	while (move_above_node(&ptr) && --tmp)
		ptr->order = *tmp;
	free(tmp);
}