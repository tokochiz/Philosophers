/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:40:51 by ctokoyod          #+#    #+#             */
/*   Updated: 2024/11/30 20:34:27 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_simulation_end(t_data *data)
{
	int	end;

	pthread_mutex_lock(&data->simu_end_mutex);
	end = data->simu_end;
	pthread_mutex_unlock(&data->simu_end_mutex);
	return (end);
}

// モニタリング関数
void	*monitor_philos(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	while (!is_simulation_end(data))
	{
		i = 0;
		while (i < data->number_of_philosophers)
		{
			//  哲学者の死亡チェック
			if (check_death(&data->philo[i]))
				return (NULL);
			// //オプションの食事回数のチェック
			// if (data->must_eat_times != -1 && all_philosophers_ate_enough(data))
			// {
			// 	is_simulation_end(data);
			// 	return (NULL);
			// }
			i++;
		}
		usleep(1000); // 1ms待機　CPU負荷軽減のための短い待機
	}
	return (NULL);
}


// // モニタリング関数の実装
// static void	*monitor_philos(void *arg)
// {
// 	t_data	*data;
// 	int		i;

// 	data = (t_data *)arg;
// 	while (!data->simu_end)
// 	{
// 		i = 0;
// 		while (i < data->number_of_philosophers)
// 		{
// 			if (check_death(&data->philo[i]))
// 			{
// 				pthread_mutex_lock(&data->simu_end_mutex);
// 				data->simu_end = 1;
// 				pthread_mutex_unlock(&data->simu_end_mutex);
// 				return (NULL);
// 			}
// 			i++;
// 		}
// 		usleep(1000);
// 	}
// 	return (NULL);
// }

int	start_monitoring(t_data *data)
{
	pthread_t monitor_thread;
	// モニタリング用の新しいスレッド
	if (pthread_create(&monitor_thread, NULL, monitor_philos, data))
		return (1);

	// メインスレッドからの切り離す　スレッドが終了時に自動的にリソースを解放
	pthread_detach(monitor_thread);
	return (0);
}