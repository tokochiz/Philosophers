/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 21:10:05 by ctokoyod          #+#    #+#             */
/*   Updated: 2024/12/08 13:35:22 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	take_fork(t_philo *philo, t_data *data)
{
	printf("test**take fork**** philosophers: %d\n",
		data->number_of_philosophers);
	pthread_mutex_lock(&data->fork[philo->left_fork].mutex);
	printf("has taken a left fork %d\n", data->number_of_philosophers);
	
	pthread_mutex_lock(&data->fork[philo->right_fork].mutex);
	printf("has taken a right fork %d\n", data->number_of_philosophers);
	
	return (0);
}
int	release_fork(t_philo *philo, t_data *data)
{
	printf("test**release fork****\n");
	pthread_mutex_unlock(&data->fork[philo->left_fork].mutex);
	printf("has taken a left fork");
	pthread_mutex_unlock(&data->fork[philo->right_fork].mutex);
	printf("has taken a right fork");
	return (0);
}
