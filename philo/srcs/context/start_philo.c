/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:11:32 by ctokoyod          #+#    #+#             */
/*   Updated: 2025/01/02 15:16:28 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	adjust_routine_timing(t_philo *philo)
{
	int	philo_num;
	int	philo_id;
	int	time_to_eat;

	philo_num = philo->table->num_of_philos;
	philo_id = philo->id;
	time_to_eat = philo->table->time_to_eat;
	if (philo_num % 2 == 0)
	{
		if (philo_id % 2 == 0)
			sleep_for_ms(time_to_eat);
	}
	else
	{
		if (philo_id % 2 == 0)
			sleep_for_ms((((2 * philo_num - philo_id) * time_to_eat))
				/ (philo_num - 1));
		else
			sleep_for_ms(((philo_num - philo_id) * time_to_eat)
				/ (philo_num - 1));
	}
	return ;
}

void	*start_philos(void *philo_p)
{
	t_philo		*philo;
	long long	time;

	philo = (t_philo *)philo_p;
	time = get_current_time_ms();
	while (time < philo->table->start_time)
	{
		usleep(10);
		time = get_current_time_ms();
	}
	pthread_mutex_lock(&philo->lock);
	philo->last_meal_time = get_current_time_ms();
	pthread_mutex_unlock(&philo->lock);
	adjust_routine_timing(philo);
	start_lifecycle(philo);
	return (NULL);
}

void	start_one_philo(t_table *table)
{
	print_fork(&(table->philos[0]));
	sleep_for_ms(table->time_to_die);
	print_dead(&(table->philos[0]));
	return ;
}
