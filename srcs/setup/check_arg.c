/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 21:01:26 by ctokoyod          #+#    #+#             */
/*   Updated: 2024/12/14 13:00:00 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// TODO : is_valid_input関数を書く

// TODO : intput check ... true or false

bool	check_arg(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc != 5 && argc != 6)
		return (false);
	(void)argv;
	// while (i < argc)
	// {
	// 	if (!input_(argv[i]))
	// 		return (false);
	// 	i++;
	// }
	return (true);
}
