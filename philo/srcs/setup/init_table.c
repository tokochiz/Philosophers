/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 20:39:16 by ctokoyod          #+#    #+#             */
/*   Updated: 2025/01/03 16:31:02 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

bool	destory_mutex_table(t_table *table, int i)
{
	pthread_mutex_destroy(&table->death_mutex);
	pthread_mutex_destroy(&table->print_mutex);
	pthread_mutex_destroy(&table->simu_end_mutex);
	pthread_mutex_destroy(&table->table_lock);
	i = i - 1;
	while (i >= 0)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i--;
	}
	return (false);
}

bool	init_data(int argc, char **argv, t_table *table)
{
	int	i;

	i = 0;
	convert_input_to_table(argc, argv, table);
	if (!validate_input_parameters(table))
		return (false);
	if (pthread_mutex_init(&table->death_mutex, NULL) != 0
		|| pthread_mutex_init(&table->print_mutex, NULL) != 0
		|| pthread_mutex_init(&table->simu_end_mutex, NULL) != 0
		|| pthread_mutex_init(&table->table_lock, NULL) != 0)
	{
		destory_mutex_table(table, 0);
		return (false);
	}
	while (i < table->num_of_philos)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
			return (destory_mutex_table(table, i));
		i++;
	}
	if (init_philo(table) == false)
		return (destory_mutex_table(table, table->num_of_philos));
	return (true);
}
