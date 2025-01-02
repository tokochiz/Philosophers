/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:44:11 by ctokoyod          #+#    #+#             */
/*   Updated: 2025/01/02 14:26:54 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	take_fork(t_philo *philo)
{
	if (pthread_mutex_lock(philo->left_fork) != 0)
		return (-1);
	if (pthread_mutex_lock(philo->right_fork) != 0)
	{
		pthread_mutex_unlock(philo->left_fork);
		return (-1);
	}
	return (0);
}

int	release_fork(t_philo *philo)
{
	if (pthread_mutex_unlock(philo->right_fork) != 0)
		return (-1);
	if (pthread_mutex_unlock(philo->left_fork) != 0)
		return (-1);
	return (0);
}
