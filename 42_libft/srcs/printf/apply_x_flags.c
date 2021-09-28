/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_x_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaman <mhaman@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 10:14:01 by mhaman            #+#    #+#             */
/*   Updated: 2021/09/26 13:19:28 by mhaman           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ftprintf.h"
#include "../include/libft.h"

int	apply_x_option(char **str, va_list ap, size_t i, size_t j)
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
	arg = apply_point_flag_x(str, ap, i, j);
	if (j >= ft_strlen(arg))
	{
		str[i] = ft_subfstr(str[i], 0, j - ft_strlen(arg));
	}
	else
		str[i][0] = 0;
	str[i] = ft_strfjoin(str[i], arg, 3);
	return (apply_minus_flag(str, i, 0, neg));
}

char	*apply_point_flag_x(char **str, va_list ap, size_t i, size_t j)
{
	size_t	nbr;
	char	*arg;
	char	*temp;
	size_t	d;

	d = 0;
	if (str[i][j] == '.')
		d = 1;
	nbr = ft_atoi(str[i] + j + d);
	arg = ft_itoa_base(va_arg(ap, unsigned int), "0123456789abcdef");
	if (str[i][j] == '.' && nbr == 0 && arg[0] == '0')
	{
		arg = ft_strfdup("", arg);
	}
	else if (nbr >= ft_strlen(arg))
	{
		temp = ft_str_malloc((nbr - ft_strlen(arg)), '0');
		arg = ft_strfjoin(temp, arg, 3);
	}
	return (arg);
}

int	apply_ux_option(char **str, va_list ap, size_t i, size_t j)
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
	arg = apply_point_flag_ux(str, ap, i, j);
	if (j >= ft_strlen(arg))
	{
		str[i] = ft_subfstr(str[i], 0, j - ft_strlen(arg));
	}
	else
		str[i][0] = 0;
	str[i] = ft_strfjoin(str[i], arg, 3);
	return (apply_minus_flag(str, i, 0, neg));
}

char	*apply_point_flag_ux(char **str, va_list ap, size_t i, size_t j)
{
	size_t	nbr;
	char	*arg;
	char	*temp;
	size_t	d;

	d = 0;
	if (str[i][j] == '.')
		d = 1;
	nbr = ft_atoi(str[i] + j + d);
	arg = ft_itoa_base(va_arg(ap, unsigned int), "0123456789ABCDEF");
	if (str[i][j] == '.' && nbr == 0 && arg[0] == '0')
	{
		arg = ft_strfdup("", arg);
	}
	else if (nbr >= ft_strlen(arg))
	{
		temp = ft_str_malloc((nbr - ft_strlen(arg)), '0');
		arg = ft_strfjoin(temp, arg, 3);
	}
	return (arg);
}

int	check_precision(char **str, size_t i)
{
	size_t	j;

	j = 0;
	while (str[i][j] && str[i][j] != '.')
		j++;
	if (str[i][j] == '.')
	{
		str[i] = ft_subfstr(str[i], 0, j);
		str[i] = ft_strfjoin(str[i], "%", 1);
	}
	return (1);
}
