/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaman <mhaman@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 09:47:12 by mhaman            #+#    #+#             */
/*   Updated: 2021/04/21 14:46:06 by mhaman           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static	int	ft_lenint(unsigned long n)
{
	unsigned long		nb;
	int					k;

	nb = n;
	k = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb = nb / 10;
		k++;
	}
	return (k);
}

char	*ft_itoa_unsigned(unsigned int n)
{
	char			*str;
	int				k;
	unsigned long	nbr;

	nbr = n;
	k = ft_lenint(nbr);
	str = ft_xmalloc(k + 1);
	while (k-- > 0)
	{
		str[k] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (str);
}
