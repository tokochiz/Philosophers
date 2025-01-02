/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:51:35 by ctokoyod          #+#    #+#             */
/*   Updated: 2024/12/30 16:15:17 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long	get_current_time_ms(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (-1);
	return ((long long)(time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	sleep_for_ms(int time)
{
	long int	start_time;

	start_time = get_current_time_ms();
	while ((get_current_time_ms() - start_time) < time)
		usleep(100);
	return ;
}
