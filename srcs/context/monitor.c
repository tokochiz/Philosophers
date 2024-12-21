/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 21:00:52 by ctokoyod          #+#    #+#             */
/*   Updated: 2024/12/21 14:54:22 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static void	_handle_philo_death(t_philo *philo)
{
	print_dead(philo);
	pthread_mutex_lock(&philo->table->table_lock);
	philo->table->end_flag = 1;
	pthread_mutex_unlock(&philo->table->table_lock);
	pthread_mutex_unlock(&philo->lock);
	return ;
}

static bool	_check_philo_health(t_philo *philo)
{
	long	current_time;

	current_time = get_current_time_ms();
	pthread_mutex_lock(&philo->lock);
	if (philo->last_meal_time != -1 && current_time
		- philo->last_meal_time >= philo->time_to_die && philo->is_eating == 0)
	{
		_handle_philo_death(philo);
		return (true);
	}
	pthread_mutex_unlock(&philo->lock);
	return (false);
}

static bool	_check_philo_must_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->lock);
	if (!(philo->is_full) && philo->table->num_of_must_eat > 0
		&& philo->eat_count >= philo->table->num_of_finish)
	{
		philo->is_full = true;
		pthread_mutex_unlock(&philo->lock);
		pthread_mutex_lock(&philo->table->table_lock);
		philo->table->num_of_finish++;
		if (philo->table->num_of_finish >= philo->table->num_of_philos)
		{
			philo->table->end_flag = 1;
			pthread_mutex_unlock(&philo->table->table_lock);
			return (true);
		}
		pthread_mutex_unlock(&philo->table->table_lock);
	}
	else
	{
		pthread_mutex_unlock(&philo->lock);
	}
	return (false);
}

static bool	_can_stop_monitoring(t_philo *philo)
{
	if (_check_philo_health(philo))
		return (true);
	if (_check_philo_must_eat(philo))
		return (true);
	return (false);
}

void	*monitor_all_philos(void *arg)
{
	t_table	*table;
	t_philo	*philo;
	int		i;

	table = (t_table *)arg;
	i = 0;
	while (1)
	{
		pthread_mutex_lock(&table->table_lock);
		if (table->end_flag)
		{
			pthread_mutex_unlock(&table->table_lock);
			return (NULL);
		}
		pthread_mutex_unlock(&table->table_lock);
		philo = &table->philos[i];
		if (_can_stop_monitoring(philo))
			return (NULL);
		i = (i + 1) % table->num_of_philos;
		get_sleep_time_ms(1);
	}
	return (NULL);
}
