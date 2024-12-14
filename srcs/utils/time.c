/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:51:35 by ctokoyod          #+#    #+#             */
/*   Updated: 2024/12/14 20:58:52 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long get_current_time_ms(void)
{
	struct timeval	time;

	// 現在の時間を取得　NULL・・・タイムゾーン情報が不要
	if (gettimeofday(&time, NULL) == -1)
		return (-1);
	// 秒 (tv_sec) とマイクロ秒 (tv_usec) 　
	// 秒をミリ秒、マイクロ秒をミリ秒に変換してその合計を返す
	return ((long long)(time.tv_sec * 1000) + (time.tv_usec / 1000));
}
void	sleep_for_ms(int time)
{
	long int	start_time;

	printf("debag**sleep for ms\n");
	start_time = get_current_time_ms();
	while ((get_current_time_ms() - start_time) < time)
		usleep(100);
	return ;
}

