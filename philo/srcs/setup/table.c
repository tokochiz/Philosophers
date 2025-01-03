/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:14:27 by ctokoyod          #+#    #+#             */
/*   Updated: 2025/01/03 16:16:34 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	cleanup_threads(t_table *table, int philo_count)
{
	int	i;

	pthread_mutex_lock(&table->table_lock);
	table->end_flag = true;
	pthread_mutex_unlock(&table->table_lock);
	usleep(10000);
	i = philo_count;
	while (--i >= 0)
	{
		pthread_mutex_destroy(&table->forks[i]);
		pthread_mutex_destroy(&table->philos[i].lock);
	}
	pthread_mutex_destroy(&table->table_lock);
	return (-1);
}

int	create_monitor_thread(t_table *table)
{
	int	ret;

	ret = pthread_create(&table->monitor, NULL, &monitor_all_philos,
			(void *)table);
	if (ret != 0)
		return (cleanup_threads(table, table->num_of_philos));
	return (0);
}

int	start_table(t_table *table)
{
	table->start_time = get_current_time_ms();
	if (table->num_of_philos == 1)
	{
		start_one_philo(table);
		return (0);
	}
	table->start_time += (long)500;
	if (init_philo_threads(table) != 0)
		return (-1);
	if (create_monitor_thread(table) != 0)
	{
		table->end_flag = true;
		cleanup_threads(table, table->num_of_philos);
		return (-1);
	}
	return (0);
}

int	end_table(t_table *table)
{
	int	i;
	int	ret;

	i = 0;
	while (i < table->num_of_philos)
	{
		ret = pthread_mutex_destroy(&table->forks[i]);
		if (ret != 0)
			return (-1);
		ret = pthread_mutex_destroy(&table->philos[i].lock);
		if (ret != 0)
			return (-1);
		i++;
	}
	ret = pthread_mutex_destroy(&table->table_lock);
	if (ret != 0)
		return (-1);
	return (0);
}
