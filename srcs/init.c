/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:15:26 by ctokoyod          #+#    #+#             */
/*   Updated: 2024/09/26 22:09:51 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// todo : ミューテックスを初期化する関数
int	init_mutexes(t_data *data)
{
	int	i;
		printf("init test4\n");
	if (pthread_mutex_init(&data->death_mutex, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
		return (1);
	i = 0;
	while (i < data->num_must_eat)
	{
		if (pthread_mutex_init(&data->fork[i].mutex, NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}

// todo : 哲学者とフォークの初期状態を設定する
int	init_forks(t_data *data)
{
	int	i;
		printf("init test3\n");
	data->fork = (t_fork *)malloc(sizeof(t_fork)
			* data->number_of_philosophers);
	if (data->fork == NULL)
		return (1);
	i = 0;
	while (i < data->number_of_philosophers)
	{
		data->fork[i].id = i + 1;
		i++;
	}
	return (0);
}

int	init_philos(t_data *data)
{
	int	i;
		printf("init test2\n");
	data->philo = (t_philo *)malloc(sizeof(t_philo)* data->number_of_philosophers);
	if (data->philo == NULL)
		return (1);
	i = 1;
	while (i <= data->number_of_philosophers)
	{
		data->philo[i].id = i + 1;
		data->philo[i].state = THINKING;
		data->philo[i].eat_count = 0;
		data->philo[i].last_meal_time = 0;
		data->philo[i].data = data;
		i++;
	}
	return (0);
}

void	init_data(t_data *data)
{
		printf("init test1\n");
	data->error = 0; // エラーフラグを初期化
	if (init_philos(data))
	{
		fprintf(stderr, "Failed to initialize philosophers\n");
		data->error = 1;
		return ;
	}
	if (init_forks(data))
		return ;
	if (init_mutexes(data))
		return ;
}
