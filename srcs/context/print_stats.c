/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stats.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:45:04 by ctokoyod          #+#    #+#             */
/*   Updated: 2024/12/14 20:52:50 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

/*
• 哲学者の状態の変化は、以下のフォーマットで表示する:
◦ `timestamp_in_ms X has taken a fork`
◦ `timestamp_in_ms X is eating`
◦ `timestamp_in_ms X is sleeping`
◦ `timestamp_in_ms X is thinking`
◦ `timestamp_in_ms X died`
`timestamp_in_ms` には現在のタイムスタンプ（ミリ秒）を、X には哲学者の番号を置き換える。
*/

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
	//pthread_mutex_lock(&philo->table->table_lock);
	if (philo->table->end_flag == false)
	{
		printf("%ld %d died\n", get_current_time_ms()
			- philo->table->start_time, philo->id);
	}
	//pthread_mutex_unlock(&philo->table->table_lock);
}
