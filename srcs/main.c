/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 20:39:45 by ctokoyod          #+#    #+#             */
/*   Updated: 2024/12/21 14:55:55 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	join_all_threads(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->num_of_philos)
	{
		pthread_join(table->philos[i].thread_id, NULL);
		i++;
	}
	pthread_join(table->monitor, NULL);
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (!check_arg(argc, argv))
		return (printf("Error\n"));
	if (!init_data(argc, argv, &table))
		return (printf("Error\n"));
	start_table(&table);
	if (table.num_of_philos != 1)
		join_all_threads(&table);
	end_table(&table);
	return (0);
}
