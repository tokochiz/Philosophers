/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:59:58 by ctokoyod          #+#    #+#             */
/*   Updated: 2024/11/18 22:14:43 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// デバッグ用のマクロ
#define DEBUG_PRINT(fmt, ...) fprintf(stderr, "[DEBUG] " fmt "\n", ##__VA_ARGS__)

// todo :　デットロックの防止
// todo : 初期スリープ時間の計算　偶数、奇数の時
// todo : 哲学者の生命サイクルの実装
// a. 思考: usleepを使用して思考時間をシミュレートします。
// b. フォークを取る: pthread_mutex_lockを使用して左右のフォークをロックします。
// c. 食事: usleepを使用してtime_to_eatミリ秒間の食事をシミュレートします。
// d. フォークを置く: pthread_mutex_unlockを使用してフォークをアンロックします。
// e. 睡眠: usleepを使用してtime_to_sleepミリ秒間の睡眠をシミュレートします。
// f. ループ: 哲学者が必要な回数だけ食事をするか、死亡するまでこのサイクルを繰り返します。

static long long	calc_start_meal_time(t_philo *philo)
{
	int	p;
	int	i;
	int	e;
	int	t;

	p = philo->data->number_of_philosophers;
	i = philo->id;
	e = philo->data->time_to_eat;
	t = 0;
	if (p == 1)
		return (philo->data->start_time);
	if (p % 2 == 0)
	{
		if (i % 2 == 0)
		{
			t = e;
		}
		else
		{
			t = 0;
		}
	}
	else
	{
		if (i % 2 == 0)
		{
			t = ((2 * p - i) * e) / (p - 1);
			// printf("tt2-0 %d, n:%d\n", t, i);
		}
		else
		{
			t = ((p - i) * e) / (p - 1);
			// rintf("tt2-1 %d, n:%d\n", t, i);
		}
	}
	printf("calc_start_meal_time %lld\n",philo->data->start_time + t);
	return (philo->data->start_time + t);
}

static void	*action(void *arg)
{
	t_philo		*philo;
	long long	first_meal_time;
	 int          iteration = 0;  // デバッグ用のイテレーションカウンター
printf("action test1\n");
	philo = (t_philo *)arg;
	// スタートする時間を調整を計算する
	first_meal_time = calc_start_meal_time(philo);
	precise_sleep_time(first_meal_time);
	printf("action test1\n");
	DEBUG_PRINT("***Philosopher %d first meal time %lld ", philo->id, first_meal_time);
	// 指定された時刻までに正確に待機をする関数
	// 繰り返す動作　死ぬまで繰り返す
	while (1)
	{
		// 死亡確認
   // 各イテレーションの開始をログ
        DEBUG_PRINT("***Philosopher %d: iteration %d at time %lld", 
                    philo->id, iteration, get_time() - philo->data->start_time);

        // 死亡確認
        if (check_death(philo))
        {
            DEBUG_PRINT("***Philosopher %d died at iteration %d", philo->id, iteration);
            break;
        }
		        // テスト用の処理 =============================================
        pthread_mutex_lock(&philo->data->print_mutex);
        printf("%lld %d is thinking\n", 
               get_time() - philo->data->start_time, philo->id);
        pthread_mutex_unlock(&philo->data->print_mutex);

        // 意図的に食事をしない時間を作る（死亡判定のテスト用）
        if (iteration == 2)  // 3回目のイテレーションで意図的に待機
        {
            DEBUG_PRINT("***Philosopher %d: intentionally waiting longer", philo->id);
            usleep((philo->data->time_to_die + 100) * 1000);  // 死亡時間より少し長く待機
        }
        else
        {
            usleep(10000);  // 通常の待機時間
        }

        iteration++;
		
		// // 思考状態
		// // take_think(philo);
		// think_time = calc_think_time(philo);
		// print_status(philo, "is thinking");
		// precise_sleep_time(think_time);
		
		// // フォーク取る
		// if (!take_forks(philo))
		// 	break ;
			
		// //食事
		// if (!eat(philo))
		// {
		// 	put_forks(philo);
		// 	break ;
		// }

		// // フォーク置く
		// put_forks(philo);
		
		// // 睡眠
		// print_status(philo, "is sleeping");
		// precise_sleep_time(philo->data->time_to_sleep);
	}
	return (NULL);
}

int	start_philos(t_data *data)
{
	int	i;

	i = 0;
	printf("***start test1\n");
	// 遅延をあとで調整　遅延を入れて、スレッドの作成で同じ開始時間を持つようにする
	data->start_time = get_time() + 1000;
	DEBUG_PRINT("***Starting to create threads. Number of philosophers: %d",
		data->number_of_philosophers);
	DEBUG_PRINT("***Starting time: %lld", data->start_time);
	while (i < data->number_of_philosophers)
	{
		data->philo[i].id = i + 1;
		data->philo[i].data = data;
		data->philo[i].eat_count = 0;
		data->philo[i].last_meal_time = data->start_time;
		// todo : 哲学者文のスレッドを作成する
		if (pthread_create(&data->philo[i].thread, NULL, action,
				&data->philo[i]))
		{
			DEBUG_PRINT("***Failed to create thread for philosopher %d", i);
			// error
			return (1);
		}
		DEBUG_PRINT("***Successfully created thread for philosopher %d", i);
		i++;
	}
	//todo : 哲学者のモニタリング　死ぬか、シミュレートが終了するまでの間監視する
	//if(start_monitoring(data))
	//	return 1;
		
	i = 0;
	while (i < data->number_of_philosophers)
	{
		pthread_join(data->philo[i].thread, NULL);
		i++;
	}
	return (0);
}
