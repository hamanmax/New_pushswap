/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_s_option.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaman <mhaman@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 13:58:23 by mhaman            #+#    #+#             */
/*   Updated: 2021/04/21 15:48:24 by mhaman           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ftprintf.h"
#include "../include/libft.h"

int	apply_s_option(char **str, va_list ap, size_t i, size_t j)
{
	char	*arg;
	size_t	neg;

	neg = 0;
	if (str[i][0] == '-')
	{
		neg = 1;
		str[i][0] = ' ';
	}
	while (str[i][j] == ' ' || str[i][j] == '0' || str[i][j] == '-')
		j++;
	arg = apply_point_flag_s(str, ap, i, j);
	if (j >= ft_strlen(arg))
	{
		str[i] = ft_subfstr(str[i], 0, j - ft_strlen(arg));
	}
	else
		str[i][0] = 0;
	str[i] = ft_strfjoin(str[i], arg, 3);
	return (apply_minus_flag(str, i, 0, neg));
}

char	*apply_point_flag_s(char **str, va_list ap, size_t i, size_t j)
{
	char	*arg;
	char	*temp;
	size_t	nbr;

	nbr = 0;
	if (str[i][j] == '.')
		nbr = 1;
	temp = va_arg(ap, char *);
	if (temp)
		temp = ft_strdup(temp);
	if (temp == NULL)
		temp = ft_strfdup("(null)", temp);
	arg = ft_strdup(temp);
	nbr = (size_t)ft_atoi(str[i] + j + nbr);
	if (nbr < ft_strlen(arg) && str[i][j] == '.')
	{
		arg = ft_subfstr(arg, 0, nbr);
	}
	free(temp);
	return (arg);
}

int	check_multiflag_pourcent(char **str, size_t i, size_t j)
{
	while (str[i][j] == '0')
		j++;
	if (str[i][j] == '-')
	{
		while (str[i][j] == '0' || str[i][j] == '-')
			j++;
		if (str[i][j])
		{
			str[i] = ft_subfstr(str[i], j, ft_strlen(str[i]) - j);
			str[i] = ft_strfjoin("-", str[i], 2);
		}
	}
	return (1);
}
