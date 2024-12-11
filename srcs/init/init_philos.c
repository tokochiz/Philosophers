/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:00:41 by ctokoyod          #+#    #+#             */
/*   Updated: 2024/12/11 21:10:54 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

// TODO :　set_fork関数を作る　各哲学者に左右のフォークを割り当てる
// TODO :　初期化中にエラーが失敗した場合の哲学者の個人ロックを破棄する

bool	init_philo(t_table *table)
{
	t_philo *philo;
	int i;
	i = 0;
	while (i < table->num_of_philos)
	{
		philo = &(table->philos[i]);
		philo->id = i + 1;
		philo->is_dead = false;
		philo->is_full = false;
		philo->is_eating = 0;
		philo->last_meal_time = -1;
		philo->time_to_die = table->time_to_die;
		philo->time_to_eat = table->time_to_eat;
		philo->time_to_sleep = table->time_to_sleep;
		if (pthread_mutex_init(&philo->lock, NULL) != 0)
			return (destory_mutex_philo_lock(table, i));
		philo->table = table;
		set_fork(philo, table->forks, i);
		i++;
	}
	return (true);
}
