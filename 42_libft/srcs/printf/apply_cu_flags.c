/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_cu_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaman <mhaman@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 10:14:01 by mhaman            #+#    #+#             */
/*   Updated: 2021/09/26 13:18:55 by mhaman           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ftprintf.h"
#include "../include/libft.h"

int	apply_u_option(char **str, va_list ap, size_t i, size_t j)
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
	arg = apply_point_flag_u(str, ap, i, j);
	if (j >= ft_strlen(arg))
		str[i] = ft_subfstr(str[i], 0, j - ft_strlen(arg));
	else
		str[i][0] = 0;
	ft_strfjoin(str[i], arg, 3);
	return (apply_minus_flag(str, i, 0, neg));
}

char	*apply_point_flag_u(char **str, va_list ap, size_t i, size_t j)
{
	size_t	nbr;
	char	*arg;
	size_t	d;

	d = 0;
	nbr = ft_atoi(str[i] + j);
	if (str[i][j] == '.')
		nbr = ft_atoi(str[i] + j + 1);
	arg = ft_itoa_unsigned(va_arg(ap, unsigned int));
	if (arg[0] == '-')
		d = 1;
	if (str[i][j] == '.' && nbr == 0 && arg[0] == '0')
	{
		ft_strfdup("", arg);
	}
	else if (nbr < 2147483648 && nbr >= ft_strlen(arg))
	{
		apply_point_flag_bis(nbr, d, arg);
	}
	return (arg);
}

int	apply_c_option(char **str, va_list ap, size_t i, size_t *len)
{
	if (str[i][0] == ' ')
	{
		apply_c_option_bis(str, i, ap);
	}
	else if (str[i][0] != '-' || str[i][1] == 0)
	{
		ft_putchar_fd(va_arg(ap, int), 1);
		str[i][0] = 0;
	}
	else if (str[i][0] == '-')
	{
		ft_putchar_fd(va_arg(ap, int), 1);
		if (str[i][1] != 0)
		{
			ft_subfstr(str[i], 0, ft_strlen(str[i]) - 2);
			if (str[i][0] == '-')
				str[i][0] = ' ';
			ft_putstr_fd(str[i], 1);
		}
	}
	*len += ft_strlen(str[i]) + 1;
	str[i][0] = 0;
	return (1);
}

int	apply_p_option(char **str, va_list ap, size_t i, size_t j)
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
	arg = apply_point_flag_p(str, ap, i, j);
	if (j >= ft_strlen(arg))
	{
		str[i] = ft_subfstr(str[i], 0, j - ft_strlen(arg));
	}
	else
		str[i][0] = 0;
	str[i] = ft_strfjoin(str[i], arg, 3);
	return (apply_minus_flag(str, i, 0, neg));
}

char	*apply_point_flag_p(char **str, va_list ap, size_t i, size_t j)
{
	size_t	nbr;
	char	*arg;
	char	*temp;

	nbr = ft_atoi(str[i] + j);
	if (str[i][j] == '.')
		nbr = ft_atoi(str[i] + j + 1);
	arg = ft_itoa_base_long(va_arg(ap, size_t), "0123456789abcdef");
	if (str[i][j] == '.' && arg[0] == '0')
		arg[0] = 0;
	arg = ft_strfjoin("0x", arg, 2);
	if (!arg)
		return (NULL);
	else if (nbr >= ft_strlen(arg))
	{
		temp = ft_str_malloc((nbr - ft_strlen(arg)), '0');
		if (arg[0] == '-')
		{
			temp[0] = '-';
			arg[0] = '0';
		}
		arg = ft_strfjoin(temp, arg, 3);
	}
	return (arg);
}
