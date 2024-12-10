/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:18:42 by ctokoyod          #+#    #+#             */
/*   Updated: 2024/11/30 21:46:30 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long long	get_time(void)
{
	struct timeval	time;

	// 現在の時間を取得　NULL・・・タイムゾーン情報が不要
	if (gettimeofday(&time, NULL) == -1)
		return (-1);
	// 秒 (tv_sec) とマイクロ秒 (tv_usec) 　
	// 秒をミリ秒、マイクロ秒をミリ秒に変換してその合計を返す
	return ((long long)(time.tv_sec * 1000) + (time.tv_usec / 1000));
}
// precise_sleep_timeの実装も確認
// precise_sleep_timeの改善版
void precise_sleep_time(long long target_time)
{
    long long current_time;
    long long wait_time;
    
    current_time = get_time();
    if (target_time <= current_time)
        return;
        
    wait_time = target_time - current_time;

    usleep(wait_time * 1000);  // マイクロ秒に変換
}
