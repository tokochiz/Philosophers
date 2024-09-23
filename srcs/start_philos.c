/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:59:58 by ctokoyod          #+#    #+#             */
/*   Updated: 2024/09/23 20:36:39 by ctokoyod         ###   ########.fr       */
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

static int	calc_start_meal_time(t_data *data)
{
	int	p;
	int	i;
	int	e;
	int	t;

	p = data->number_of_philosophers;
	i = data->philo->id;
	e = data->time_to_eat;
	t = 0;
	if (p == 1)
		return (data->start_time);
	if (p % 2 == 0)
	{
		if (i % 2 == 0)
			t = e;
		else
			t = 0;
	}
	else
	{
		if (i % 2 == 0)
			t = ((2 * p - i) * e) / (p - 1);
		else
			t = ((p - i) * e) / (p - 1);
	}
	return (data->start_time + t);
}

static void	*action(void *arg)
{
	t_philo	*philo;
	int		first_meal_time;

	philo = arg;
	// スタートする時間を調整を計算する
	first_meal_time = calc_start_meal_time(philo);
	
	// 指定された時刻までに正確に待機をする関数
	
	while (1)
	{
		// 繰り返す動作　死ぬまで繰り返す
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
