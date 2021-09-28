/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaman <mhaman@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:48:44 by mhaman            #+#    #+#             */
/*   Updated: 2021/04/21 14:48:34 by mhaman           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = ft_xmalloc(count * size);
	return (ft_memset(ptr, '\0', (count * size)));
}
