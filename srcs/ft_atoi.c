/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 21:02:25 by ctokoyod          #+#    #+#             */
/*   Updated: 2024/09/26 22:07:58 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isspaces(int c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v')
		return (1);
	return (0);
}

static const char	*move_to_digit(const char *str, int *sign)
{
	*sign = 1;
	while (ft_isspaces(*str))
		str++;
	if (*str == '-')
		*sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	return (str);
}

int	ft_atoi(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	str = move_to_digit(str, &sign);
	while (*str != '\0')
	{
		if (result > (INT_MAX - (*str - '0')) / 10)
		{
			if (sign == 1)
				return (INT_MAX);
			return (INT_MIN);
		}
		result = result * 10 + (*str - '0');
		str++;
	}
	return (int)(sign * result);
}
