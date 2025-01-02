/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:00:41 by ctokoyod          #+#    #+#             */
/*   Updated: 2025/01/02 15:38:39 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

// TODO :　初期化中にエラーが失敗した場合の哲学者の個人ロックを破棄する
bool	destory_mutex_philo_lock(t_table *table, int i)
{
	t_philo	*philo;

	i = i - 1;
	while (i > 0)
	{
		philo = &(table->philos[i]);
		pthread_mutex_destroy(&philo->lock);
		i--;
	}
	return (false);
}

void	set_fork(t_philo *philo, pthread_mutex_t *fork, int pos)
{
	int	philo_num;

	philo_num = philo->table->num_of_philos;
	philo->left_fork = &fork[pos];
	philo->right_fork = &fork[(pos + 1) % philo_num];
}

int	init_philo_threads(t_table *table)
{
	int		i;
	long	time;

	i = 0;
	while (i < table->num_of_philos)
	{
		if (pthread_create(&table->philos[i].thread_id, NULL, &start_philos,
				(void *)&table->philos[i]) != 0)
			return (cleanup_threads(table, i));
		i++;
	}
	time = get_current_time_ms();
	while (table->start_time > time)
	{
		usleep(10);
		time = get_current_time_ms();
	}
	return (0);
}

bool	init_philo(t_table *table)
{
	t_philo	*philo;
	int		i;

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
