/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:59:58 by ctokoyod          #+#    #+#             */
/*   Updated: 2024/09/23 19:50:18 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// todo :　デットロックの防止
// todo : 初期スリープ時間の計算　偶数、奇数の時
// todo : 哲学者の生命サイクルの実装
// a. 思考: usleepを使用して思考時間をシミュレートします。
// b. フォークを取る: pthread_mutex_lockを使用して左右のフォークをロックします。
// c. 食事: usleepを使用してtime_to_eatミリ秒間の食事をシミュレートします。
// d. フォークを置く: pthread_mutex_unlockを使用してフォークをアンロックします。
// e. 睡眠: usleepを使用してtime_to_sleepミリ秒間の睡眠をシミュレートします。
// f. ループ: 哲学者が必要な回数だけ食事をするか、死亡するまでこのサイクルを繰り返します。

static void	*action(void *arg)
{
	// スタートする時間を調整
	calc_start_action(data->)
	while (1)
	{
		// 繰り返す動作
	}
	return (NULL);
}

int	start_philos(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	data->start_time = get_time() + 1000;
	while (i < data->number_of_philosophers)
	{
		// todo : 哲学者文のスレッドを作成する
		if (pthread_create(&philo[i].thread, NULL, (void *)action, &philo[i]))
		{
			// error
			return (1);
		}
		i++;
	}
	// todo : 哲学者のモニタリング　死ぬか、シミュレートが終了するまでの間監視する
	monitor_philos(&data);
	i = 0;
	while (i < data->number_of_philosophers)
	{
		pthread_join(&philo[i].thread, NULL);
		i++;
	}
}
