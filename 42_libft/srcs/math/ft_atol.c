/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaman <mhaman@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 13:13:40 by mhaman            #+#    #+#             */
/*   Updated: 2021/09/26 13:24:48 by mhaman           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

long	ft_atol(const char *str)
{
	long		i;
	long		nb;
	long		neg;

	i = 0;
	nb = 0;
	neg = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		nb *= 10;
		nb += str[i] - '0';
		i++;
	}
	return (nb * neg);
}
