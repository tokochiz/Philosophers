/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:18:42 by ctokoyod          #+#    #+#             */
/*   Updated: 2024/09/23 18:21:47 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long long	get_time(void)
{
	struct timeval	tv;

	// 現在の時間を取得　NULL・・・タイムゾーン情報が不要
	if (gettimeofday(&tv, NULL) == -1)
		return (-1);
	// 秒 (tv_sec) とマイクロ秒 (tv_usec) 　
	// 秒をミリ秒、マイクロ秒をミリ秒に変換してその合計を返す
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
