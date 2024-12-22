/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 19:41:13 by ctokoyod          #+#    #+#             */
/*   Updated: 2024/12/16 20:48:58 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	sleeping(t_philo *philo)
{
	print_sleeping(philo);
	get_sleep_time_ms(philo->table->time_to_sleep);
}
