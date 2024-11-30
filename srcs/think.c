/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:10:44 by ctokoyod          #+#    #+#             */
/*   Updated: 2024/11/30 21:03:23 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


// 	think_time = calc_think_time(philo);
// 		// 思考状態
// 		print_status(philo, "is thinking");
// 		//precise_sleep_time(philo->data->);
		

// long long calc_think_time(t_philo *philo)
// {
//     long long aberage_cycle;
    
// }

void think(t_philo *philo)
{
    long long think_time = calc_think_time(philo);
    print_status(philo, "is thinking");
    precise_sleep_time(think_time);
}
