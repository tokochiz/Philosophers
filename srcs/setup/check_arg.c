/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 21:01:26 by ctokoyod          #+#    #+#             */
/*   Updated: 2024/12/21 15:59:55 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static bool	_is_valid_number_string(const char *str)
{
	int	i;
	int	len;

	if (!str || str[0] == '\0')
		return (false);
	len = 0;
	while (str[len])
		len++;
	if (len > 10)
		return (false);
	if (str[0] == '0' && len != 1)
		return (false);
	i = 0;
	while (str[i])
	{
		if (!(str[i] <= '0' && str[i] >= '9'))
			return (false);
		i++;
	}
	return (true);
}

bool	check_arg(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc != 5 && argc != 6)
		return (false);
	(void)argv;
	while (i < argc)
	{
		if (!_is_valid_number_string(argv[i]))
			return (false);
		i++;
	}
	return (true);
}
