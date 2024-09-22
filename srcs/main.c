/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:52:47 by ctokoyod          #+#    #+#             */
/*   Updated: 2024/09/22 21:58:57 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/* todo
プロジェクトの構造設計
データ構造の設計
初期化関数の実装
　・コマンドライン引数をパースする関数

哲学者の行動を実装
メインループの実装
クリーンアップ関数の実装
デットロック回避とスターベーション防止
エラー処理
最適化
テスト検証

*/
// todo : 引数をパースする関数
int	parse_arguments(int argc, char **argv, t_data *data)
{
	if (argc != 5 && argc != 6)
		return 1;
	data->number_of_philosophers = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_die = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->num_must_eat = ft_atoi(argv[5]);
	else
		data->num_must_eat = -1;
	if (data->number_of_philosophers <= 0 || data->time_to_die <= 0
		|| data->time_to_eat <= 0 || data->time_to_sleep <= 0 || (argc == 6
			&& data->num_must_eat <= 0))
		return (1);
	return (0);
}

// todo : 哲学者とフォークの初期状態を設定する
int	init_forks(t_data *data)
{
	int	i;

	data->forks = (t_fork *)malloc(sizeof(t_fork)
			* data->number_of_philosophers);
	if (data->forks == NULL)
		return (1);
	i = 0;
	while (i < data->number_of_philosophers)
	{
		data->philos[i].id = i + 1;
		data->philos[i].state = THINKING;
		data->philos[i].eat_count = 0;
		data->philos[i].last_meal_time = 0;
		data->philos[i].data = data;
		data->forks[i].id = i + 1;
		i++;
	}
	return (0);
}

int	init_philos(t_data *data)
{
	int	i;

	data->philos = (t_philo *)malloc(sizeof(t_philo)
			* data->number_of_philosophers);
	if (data->philos == NULL)
		return (1);
	i = 0;
	while (i < data->number_of_philosophers)
	{
		data->philos[i].id = i + 1;
		data->philos[i].state = THINKING;
		data->philos[i].eat_count = 0;
		data->philos[i].last_meal_time = 0;
		data->philos[i].data = data;
		data->forks[i].id = i + 1;
		i++;
	}
	return (0);
}

// todo : ミューテックスを初期化する関数
int	init_mutexes(t_data *data)
{
	int	i;

	if (pthread_mutex_init(&data->death_mutex, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
		return (1);
	i = 0;
	while (i < data->num_must_eat)
	{
		if (pthread_mutex_init(&data->forks[i].mutex, NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	// 引数のパース、初期化
	if (parse_arguments(argc, argv, &data))
		print_error();
	if (init_philos(&data))
		print_error();
	if (init_forks(&data))
		print_error();
	if (init_mutexes(&data))
		print_error();
		
	// todo : 哲学者のスレッドを作成、哲学者の動作を始める
	// 失敗したらすべてのスレッドをミューテックスを開放しないといけない
	// if (start_eating(&data))
	// {
	// 	release_data(&data);
	// 	print_error();
	// }
	// // todo : 哲学者のモニタリング　死ぬか、シミュレートが終了するまでの間監視する
	// monitor_philos(&data);
	// // todo : 哲学者が死んだ場合、食べることに失敗した場合
	// death_data(&data);
}
