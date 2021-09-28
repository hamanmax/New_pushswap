/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaman <mhaman@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 18:01:46 by mhaman            #+#    #+#             */
/*   Updated: 2021/04/21 16:22:39 by mhaman           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	while (c != (char)*str && i != 0)
	{
		str--;
		i--;
	}
	if (c == (char)*str)
		return ((char *)str);
	return (NULL);
}
