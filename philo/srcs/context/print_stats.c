/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stats.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:45:04 by ctokoyod          #+#    #+#             */
/*   Updated: 2024/12/21 14:53:42 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	print_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->table_lock);
	if (philo->table->end_flag == false)
	{
		printf("%ld %d has taken a fork\n", get_current_time_ms()
			- philo->table->start_time, philo->id);
	}
	pthread_mutex_unlock(&philo->table->table_lock);
}

void	print_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->table_lock);
	if (philo->table->end_flag == false)
	{
		printf("%ld %d is eating\n", get_current_time_ms()
			- philo->table->start_time, philo->id);
	}
	pthread_mutex_unlock(&philo->table->table_lock);
}

void	print_sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->table_lock);
	if (philo->table->end_flag == false)
	{
		printf("%ld %d is sleeping\n", get_current_time_ms()
			- philo->table->start_time, philo->id);
	}
	pthread_mutex_unlock(&philo->table->table_lock);
}

void	print_thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->table_lock);
	if (philo->table->end_flag == false)
	{
		printf("%ld %d is thinking\n", get_current_time_ms()
			- philo->table->start_time, philo->id);
	}
	pthread_mutex_unlock(&philo->table->table_lock);
}

void	print_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->table_lock);
	if (philo->table->end_flag == false)
	{
		printf("%ld %d died\n", get_current_time_ms()
			- philo->table->start_time, philo->id);
	}
	pthread_mutex_unlock(&philo->table->table_lock);
}
