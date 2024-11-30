/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 21:10:05 by ctokoyod          #+#    #+#             */
/*   Updated: 2024/11/30 21:44:18 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	take_fork(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&data->fork[philo->left_fork].mutex);
	printf("has taken a left fork");
	pthread_mutex_lock(&data->fork[philo->right_fork].mutex);
	printf("has taken a right fork");
	return (0);
}
