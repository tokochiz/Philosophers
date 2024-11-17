/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:40:51 by ctokoyod          #+#    #+#             */
/*   Updated: 2024/11/17 19:53:20 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *monitor_philos(void *arg)
{
    t_data *data;
    
}

int start_monitoring(t_data *data)
{
    pthread_t monitor_thread;
    if(pthread_create(&monitor_thread, NULL, monitor_philos, data))
    return 1;

    pthread_detach(monitor_thread);
    return 0;
}