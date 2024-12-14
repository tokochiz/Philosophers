/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 22:42:33 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/12/14 13:08:47 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static int	_ft_isdigit(int c)
{
	return ((c >= '0' && c <= '9'));
}

static const char	*_move_to_digit(const char *str, int *sign)
{
	while (ft_isspace(str))
		str++;
	if (*str == '-')
		*sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	return (str);
}

int	ft_atoi(const char *str)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	str = _move_to_digit(str, &sign);
	while (_ft_isdigit(*str))
	{
		if ((LONG_MAX - (*str - '0')) / 10 < (sign * result))
			return ((int)LONG_MAX);
		if ((LONG_MIN + (*str - '0')) / 10 > (sign * result))
			return ((int)LONG_MIN);
		result = result * 10 + (*str - '0');
		str++;
	}
	return (sign * result);
}
