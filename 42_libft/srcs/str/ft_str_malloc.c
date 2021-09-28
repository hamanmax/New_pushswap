/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_malloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaman <mhaman@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 14:41:49 by mhaman            #+#    #+#             */
/*   Updated: 2021/04/21 16:20:59 by mhaman           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_str_malloc(int n, char c)
{
	char	*dest;

	dest = (char *)malloc(sizeof(char) * (n + 1));
	if (dest == NULL)
		return (NULL);
	dest[n] = 0;
	ft_memset(dest, c, n);
	return (dest);
}
