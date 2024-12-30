/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 19:37:15 by ctokoyod          #+#    #+#             */
/*   Updated: 2024/12/30 16:15:07 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	eating(t_philo *philo)
{
	// pthread_mutex_lock(&philo->lock);
	philo->is_eating = 1;
	print_eating(philo);
	philo->last_meal_time = get_current_time_ms();
	// pthread_mutex_unlock(&philo->lock);
	sleep_for_ms(philo->table->time_to_eat);
	// pthread_mutex_lock(&philo->lock);
	philo->is_eating = 0;
	if (philo->eat_count != -1)
		philo->eat_count++;
	// pthread_mutex_unlock(&philo->lock);
	release_fork(philo);
}
