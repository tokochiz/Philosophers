/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:15:01 by ctokoyod          #+#    #+#             */
/*   Updated: 2024/11/30 20:46:16 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

//  食事の実行を管理する関数
int	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->death_mutex);
	philo->last_meal_time = get_time();
	philo->eat_count++;
	print_status(philo, "is eating");
	precise_sleep_time(philo->data->time_to_eat);
	//必要な食事回数に達したかチェック
	if (philo->data->must_eat_times != -1
		&& philo->eat_count >= philo->data->must_eat_times)
	{
		
		pthread_mutex_unlock(&philo->data->death_mutex);
        return (0);
	}
	return (1);
}

// 食事回数チェック　　
static int	all_philosophers_ate_enough(t_data *data)
{
	int i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		if (data->philo[i].eat_count < data->must_eat_times)
			return (0);
		i++;
	}
	return (1);
}
