/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:10:09 by ctokoyod          #+#    #+#             */
/*   Updated: 2024/12/11 20:55:55 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h> // `gettimeofday`
# include <unistd.h>

typedef struct s_philo
{
	int				id;
	bool			is_dead;
	bool			is_full;
	int				is_eating;
	long long		eat_count;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	long long		last_meal_time;
	pthread_t		thread_id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	lock;
	t_table			*table;
}					t_philo;

typedef struct s_table
{
	int				num_of_philos;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	long long		num_of_must_eat;
	long long		num_of_finish;
	bool			end_flag;
	long long		start_time;
	int someone_died;               // 誰かが死んだかどうか
	pthread_mutex_t death_mutex;    //死んだかどうかの状態を更新するミューテックス
	pthread_mutex_t print_mutex;    //出力を制御するミューテクス
	pthread_mutex_t simu_end_mutex; // 終了フラグ保護用
	pthread_t		monitor;
	pthread_mutex_t	table_lock;
	pthread_mutex_t	forks[200];
	t_philo			philos[200];
}					t_table;

#endif

// init
bool	validate_input_parameters(t_table *table);
void	input_validation(int argc, char **argv, t_table *table);
