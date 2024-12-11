/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 20:39:45 by ctokoyod          #+#    #+#             */
/*   Updated: 2024/12/11 20:03:59 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// TODO : 全てのスレッドの終了を待機する関数作成　例外的に、哲学者が1人の場合は特別な処理

int	main(int argc, char **argv)
{
	t_table	table;

	if (!check_arg(argc, argv))
		return (printf("Error\n"));
	if (!init_data(argc, argv, &table))
		return (printf("Error\n"));
	start_table(&table);
	if (table.num_of_philos != 1)
		join_threads(&table);
	return (0);
}
