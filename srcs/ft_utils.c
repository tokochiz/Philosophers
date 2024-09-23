/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 21:02:25 by ctokoyod          #+#    #+#             */
/*   Updated: 2024/09/23 14:53:47 by ctokoyod         ###   ########.fr       */
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

int	ft_atoi(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 0;
	while (ft_isspaces(*str))
		str++;
	while (*str == '-')
		sign = -1;
	while (*str == '-' || *str == '+')
	{
		str++;
	}
	while (*str != '\0')
	{
		result = result * 10 + (*str - '0');
		if (result > INT_MAX)
		{
			if (sign == 1)
				return (INT_MAX);
			return (INT_MIN);
		}
		str++;
	}
	return (int)(sign * result);
}
