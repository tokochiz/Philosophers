/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 20:39:16 by ctokoyod          #+#    #+#             */
/*   Updated: 2024/12/16 21:38:19 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

// TODO :　初期化中にエラーが発生した場合のフォークとテーブル全体のロックを破棄する
bool	destory_mutex_table(t_table *table, int i)
{
	i = i - 1;
	while (i >= 0)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i--;
	}
	pthread_mutex_destroy(&table->table_lock);
	return (false);
}

bool	init_data(int argc, char **argv, t_table *table)
{
	int	i;

	i = 0;
	input_validation(argc, argv, table);
	if (!validate_input_parameters(table))
		return (false);
	if (pthread_mutex_init(&table->table_lock, NULL) != 0)
		return (false);
	while (i < table->num_of_philos)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
			return (destory_mutex_table(table, i));
		i++;
	}

	if (init_philo(table) == false)
		return (destory_mutex_table(table, i));
	return (true);
}
