/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 20:30:03 by ctokoyod          #+#    #+#             */
/*   Updated: 2024/12/11 20:39:24 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	input_valid(int argc, char **argv, t_table *table)
{
	table->num_of_philos = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_die = ft_atoi(argv[3]);
	table->time_to_die = ft_atoi(argv[4]);
	table->end_flag = false;
	table->num_of_finish = 0;
	if (argc == 6)
		table->num_of_must_eat = ft_atoi(argv[5]);
	else
		table->num_of_must_eat = -1;
}
