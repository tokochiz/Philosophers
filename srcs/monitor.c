/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:40:51 by ctokoyod          #+#    #+#             */
/*   Updated: 2024/11/17 21:15:39 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int is_simulation_end(t_data *data)
{
    int end;
    
    pthread_mutex_lock(&data->sim_end_mutex);
    end = data->simulation_end;
    pthread_mutex_unlock(&data->sim_end_mutex);
    return (end);
}

// モニタリング関数 
移しただけなので、あとであっているかちゃんと理解するのと、ちゃんと自分で説明できるようにすること！
static void *monitor_philos(void *arg)
{
    t_data *data;
    int i;
    
    data = (t_data *)arg;
    while (!is_simulation_end(data))
    {
        i = 0;
        while (i < data->number_of_philosophers)
        {
            if (check_death(&data->philo[i]))
                return (NULL);
            if (data->must_eat != -1 && 
                all_philosophers_ate_enough(data))
            {
                set_simulation_end(data);
                return (NULL);
            }
            i++;
        }
        usleep(1000); // 1ms待機
    }
    return (NULL);
}

int start_monitoring(t_data *data)
{
    pthread_t monitor_thread;
    if(pthread_create(&monitor_thread, NULL, monitor_philos, data))
    return 1;

    pthread_detach(monitor_thread);
    return 0;
}