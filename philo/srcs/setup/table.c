/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:14:27 by ctokoyod          #+#    #+#             */
/*   Updated: 2024/12/21 14:57:12 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	start_table(t_table *table)
{
	int		i;
	long	time;

	i = 0;
	table->start_time = get_current_time_ms();
	if (table->num_of_philos == 1)
	{
		start_one_philo(table);
		return ;
	}
	table->start_time += (long)500;
	while (i < table->num_of_philos)
	{
		pthread_create(&table->philos[i].thread_id, NULL, &start_philos,
			(void *)&table->philos[i]);
		i++;
	}
	time = get_current_time_ms();
	while (table->start_time > time)
	{
		usleep(10);
		time = get_current_time_ms();
	}
	pthread_create(&table->monitor, NULL, &monitor_all_philos, (void *)table);
}

void	end_table(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->num_of_philos)
	{
		pthread_mutex_destroy(&table->forks[i]);
		pthread_mutex_destroy(&table->philos[i].lock);
		i++;
	}
	pthread_mutex_destroy(&table->table_lock);
}
