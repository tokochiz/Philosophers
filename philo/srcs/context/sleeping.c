/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 19:41:13 by ctokoyod          #+#    #+#             */
/*   Updated: 2024/12/30 16:15:17 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	sleeping(t_philo *philo)
{
	print_sleeping(philo);
	sleep_for_ms(philo->table->time_to_sleep);
}
