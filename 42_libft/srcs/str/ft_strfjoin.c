/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaman <mhaman@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:18:25 by mhaman            #+#    #+#             */
/*   Updated: 2021/04/21 16:25:15 by mhaman           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static void	sn_free(char *s1, char *s2, int f)
{
	if (f == 1)
		free(s1);
	else if (f == 2)
		free(s2);
	else if (f == 3)
	{
		free(s1);
		free(s2);
	}
}

char	*ft_strfjoin(char *s1, char *s2, int f)
{
	char			*s3;
	const size_t	lens1 = ft_strlen(s1);
	const size_t	lens2 = ft_strlen(s2);

	s3 = (char *)malloc((lens1 + lens2) + 1);
	if (s3 == NULL)
		return (NULL);
	ft_memcpy(s3, s1, lens1);
	ft_memcpy(s3 + lens1, s2, lens2);
	s3[lens2 + lens1] = '\0';
	sn_free(s1, s2, f);
	return (s3);
}
