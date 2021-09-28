/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_d_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaman <mhaman@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 10:14:01 by mhaman            #+#    #+#             */
/*   Updated: 2021/04/21 15:07:54 by mhaman           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ftprintf.h"
#include "../include/libft.h"

int	apply_d_option(char **str, va_list ap, size_t i, size_t j)
{
	char	*arg;
	size_t	neg;

	neg = 0;
	if (str[i][0] == '-')
		neg = apply_d_option_neg(str, i);
	while (str[i][j] == ' ' || str[i][j] == '0' || str[i][j] == '-')
		j++;
	arg = apply_point_flag(str, ap, i, j);
	if (str[i][0] == '0' && arg[0] == '-' && j > ft_strlen(arg))
	{
		str[i][0] = '-';
		arg[0] = '0';
	}
	if (j >= ft_strlen(arg))
	{
		str[i] = ft_subfstr(str[i], 0, j - ft_strlen(arg));
	}
	else
		str[i][0] = 0;
	str[i] = ft_strfjoin(str[i], arg, 3);
	return (apply_minus_flag(str, i, 0, neg));
}

int	apply_stars_flag(char **str, va_list ap, size_t i, size_t j)
{
	while (str[i][j] && str[i][j] != '*')
		j++;
	while (str[i][j])
	{
		if (str[i][j] == '*')
		{
			if (apply_stars_flag_bis(str, ap, i, j) == -1)
				return (-1);
		}
		if (str[i][j])
			j++;
	}
	str[i] = ft_subfstr(str[i], 1, (ft_strlen(str[i]) - 1));
	return (1);
}

char	*apply_point_flag(char **str, va_list ap, size_t i, size_t j)
{
	size_t	nbr;
	char	*arg;
	size_t	d;

	d = 0;
	nbr = ft_atoi(str[i] + j);
	if (str[i][j] == '.')
		nbr = ft_atoi(str[i] + j + 1);
	arg = ft_itoa(va_arg(ap, int));
	if (arg[0] == '-')
		d = 1;
	if (str[i][j] == '.' && nbr == 0 && arg[0] == '0')
	{
		arg = ft_strfdup("", arg);
	}
	else if (nbr < 2147483648 && nbr >= ft_strlen(arg))
	{
		arg = apply_point_flag_bis(nbr, d, arg);
	}
	return (arg);
}

int	apply_minus_flag(char **str, size_t i, size_t j, size_t neg)
{
	if (neg != 1)
		return (1);
	while (str[i][j] && str[i][j] == ' ')
		j++;
	str[i] = ft_subfstr(str[i], j, ft_strlen(str[i]) - j);
	str[i] = ft_strfjoin(str[i], ft_str_malloc(j, ' '), 3);
	return (1);
}

int	apply_zero_flag(char **str, char c, size_t i, size_t j)
{
	size_t	nbr;
	char	*temp;
	char	*arg;

	while (str[i][j] && (str[i][j] == ' ' || str[i][j] == '-'))
		j++;
	nbr = ft_atoi(str[i] + j);
	if (nbr > 2147483647)
		nbr = 0;
	while (str[i] && (str[i][j] >= '0' && str[i][j] <= '9'))
		j++;
	temp = ft_str_malloc(nbr, c);
	arg = ft_subfstr(str[i], j, (ft_strlen(str[i]) - j));
	str[i] = ft_strfjoin(temp, arg, 3);
	return (1);
}
