/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 20:39:45 by ctokoyod          #+#    #+#             */
/*   Updated: 2024/12/10 21:04:57 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	data;

	if (!check_arg(argc, argv))
		return (printf("Error\n"));
	if (!init_data(argc, argv, &data))
		return (printf("Error\n"));
	start_table(&data);
	if (data.num_of_philos != 1)
		join_threads(&data); //全てのスレッドの終了を待機
        //例外的に、哲学者が1人の場合は特別な処理
	return (0);
}
