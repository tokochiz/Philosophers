/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:54:30 by ctokoyod          #+#    #+#             */
/*   Updated: 2024/11/17 20:36:19 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philo *philo)
{
	long long	current_time;

	// 最後の食事時間の保護
	pthread_mutex_lock(&philo->last_meal_mutex);
	// 現在時刻を取得して死亡判定に使用
	current_time = get_time();
	// 最後の食事から経過した時間が死亡時間を超えているか確認
	if (current_time - philo->last_meal_time > philo->data->time_to_die)
	{
		// current_time - last_meal_timeがtime_to_dieより大きければ死亡
		// シミュレーション終了フラグへのアクセスを保護
		pthread_mutex_lock(&philo->data->simu_end_mutex);
		// 既に終了していない場合のみ処理を継続
		if (!philo->data->simu_end)
		{
			philo->data->simu_end = 1;
			pthread_mutex_unlock(&philo->data->simu_end_mutex);
			pthread_mutex_lock(&philo->data->print_mutex);
			printf("%lld %d died\n", current_time - philo->data->start_time,
				philo->id);
			//死亡時：print_mutex → last_meal_mutex の順で解除
			pthread_mutex_unlock(&philo->data->print_mutex);
			pthread_mutex_unlock(&philo->last_meal_mutex);
			//死亡検出時は即座に1を返して終了
			return (1);
		}
		pthread_mutex_unlock(&philo->data->simu_end_mutex);
	}
	pthread_mutex_unlock(&philo->last_meal_mutex);
	return (0);
}
