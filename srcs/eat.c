/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:15:01 by ctokoyod          #+#    #+#             */
/*   Updated: 2024/11/17 19:17:50 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

//  食事の実行を管理する関数
int eat(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->death_mutex);
    philo->last_meal_time = get_time();
    philo->eat_count++;

    print_status(philo, "is eating");
    precise_sleep_time(philo->data->time_to_eat);
    
    //必要な食事回数に達したかチェック
    if(philo->data->num_must_eat != -1 && philo->eat_count >= philo->data->num_must_eat)
        return 0;
    return 1;
}

