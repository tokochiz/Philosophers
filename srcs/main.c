/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:52:47 by ctokoyod          #+#    #+#             */
/*   Updated: 2024/09/26 22:11:41 by ctokoyod         ###   ########.fr       */
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
		return (1);
	data->number_of_philosophers = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	printf("***argv debag %d %d %d %d\n", data->number_of_philosophers,
		data->time_to_die, data->time_to_eat, data->time_to_sleep);
	if (argc == 6)
		data->num_must_eat = atoi(argv[5]);
	else
		data->num_must_eat = -1;
	if (data->number_of_philosophers <= 0 || data->time_to_die <= 0
		|| data->time_to_eat <= 0 || data->time_to_sleep <= 0 || (argc == 6
			&& data->num_must_eat <= 0))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (parse_arguments(argc, argv, &data))
		print_error();
	init_data(&data);
	// 引数のパース、初期化
	printf("test2\n");
	//	todo : 哲学者のスレッドを作成、哲学者の動作を始める
	//	失敗したらすべてのスレッドをミューテックスを開放しないといけない
	if (start_philos(&data, data.philo))
	{
		// release_data(&data);
		print_error();
	}
	// todo : 哲学者が死んだ場合、食べることに失敗した場合
	//death_data(&data);
	return (0);
}
