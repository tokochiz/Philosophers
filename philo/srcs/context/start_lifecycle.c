/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_lifecycle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:24:51 by ctokoyod          #+#    #+#             */
/*   Updated: 2025/01/02 17:07:24 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool	can_philo_continue(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->table_lock);
	if (philo->table->end_flag == true)
	{
		pthread_mutex_unlock(&philo->table->table_lock);
		return (false);
	}
	pthread_mutex_unlock(&philo->table->table_lock);
	return (true);
}

void	start_lifecycle(t_philo *philo)
{
	while (1)
	{
		if (can_philo_continue(philo) == false)
			return ;
		if (take_fork(philo) != 0)
			return ;
		if (can_philo_continue(philo) == false)
		{
			if (release_fork(philo) != 0)
				return ;
			return ;
		}
		eating(philo);
		if (can_philo_continue(philo) == false)
			return ;
		sleeping(philo);
		if (can_philo_continue(philo) == false)
			return ;
		print_thinking(philo);
	}
}
