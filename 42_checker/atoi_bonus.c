/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zahrabar <zahrabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 19:18:03 by zahrabar          #+#    #+#             */
/*   Updated: 2026/01/18 00:06:33 by zahrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ov_check(unsigned long res, int digit, int sign)
{
	if (sign == 1)
	{
		if (res > (unsigned long)(INT_MAX - digit) / 10)
			return (0);
	}
	else
	{
		if (res > ((unsigned long)INT_MAX + 1 - digit) / 10)
			return (0);
	}
	return (1);
}

int	get_res(char *str, int i, int *error, int sign)
{
	int				digit;
	unsigned long	res;

	res = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			*error = -1;
			return (0);
		}
		digit = str[i] - '0';
		if (!ov_check(res, digit, sign))
		{
			*error = -1;
			return (0);
		}
		res = res * 10 + digit;
		i++;
	}
	return (res);
}

int	parse_sign(char *str, int *i, int *error)
{
	int	sign;
	int	idx;

	idx = *i;
	sign = 1;
	if (((str[idx] == '+' || str[idx] == '-') && ft_isdigit(str[idx + 1]))
		|| ft_isdigit(str[idx]))
	{
		if (str[idx] == '-')
		{
			sign = -1;
			idx++;
		}
		else if (str[idx] == '+')
			idx++;
	}
	else
	{
		*error = -1;
		return (0);
	}
	*i = idx;
	return (sign);
}

int	ft_atoi(char *str, int *error)
{
	int				i;
	unsigned long	res;
	int				sign;

	i = 0;
	res = 0;
	sign = 1;
	if (!str || !*str)
	{
		*error = -1;
		return (0);
	}
	parse_sign(str, &i, error);
	if (*error == -1)
		return (0);
	res = get_res(str, i, error, sign);
	return ((res * sign));
}
