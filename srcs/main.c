/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:52:47 by ctokoyod          #+#    #+#             */
/*   Updated: 2024/09/22 19:24:41 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/* todo
プロジェクトの構造設計
データ構造の設計
初期化関数の実装
　・コマンドライン引数をパースする関数
　・哲学者とフォークの初期化状態を設定する
　・ミューテックスを初期化する関数
哲学者の行動を実装
メインループの実装
クリーンアップ関数の実装
デットロック回避とスターベーション防止
エラー処理
最適化
テスト検証

*/

int				cnt = 0;
pthread_mutex_t	mutex;

void	*routine(void *p)
{
	int	i;
    (void)p;
	i = 0;
	while (i < 10000)
	{
		//pthread_mutex_lock(&mutex);
		cnt++;
		//pthread_mutex_unlock(&mutex);
		i++;
	}
	return (NULL);
}

int	main(void)
{
	pthread_t p1, p2;
	pthread_mutex_init(&mutex, NULL);
	pthread_create(&p1, NULL, &routine, NULL);
	pthread_create(&p2, NULL, &routine, NULL);
	pthread_join(p1, NULL);
	pthread_join(p2, NULL);
	pthread_mutex_destroy(&mutex);
	printf("cnt -> %d\n", cnt);
}