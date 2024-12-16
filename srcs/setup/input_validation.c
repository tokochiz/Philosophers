/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 20:51:57 by ctokoyod          #+#    #+#             */
/*   Updated: 2024/12/16 21:26:42 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

bool	validate_input_parameters(t_table *table)
{
	if (table->num_of_philos == -1 || table->time_to_die == -1
		|| table->time_to_eat == -1 || table->time_to_sleep == -1)
		return (false);
	else if (table->num_of_philos == 0 || table->time_to_die == 0
		|| table->time_to_eat == 0 || table->time_to_sleep == 0)
		return (false);
	else if (table->num_of_must_eat > 200)
		return (false);
	return (true);
}

void	input_validation(int argc, char **argv, t_table *table)
{
	table->num_of_philos = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	table->end_flag = false;
	table->num_of_finish = 0;
	if (argc == 6)
		table->num_of_must_eat = ft_atoi(argv[5]);
	else
		table->num_of_must_eat = -1;
}
