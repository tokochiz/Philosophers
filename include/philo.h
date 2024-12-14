/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:10:09 by ctokoyod          #+#    #+#             */
/*   Updated: 2024/12/14 20:59:03 by ctokoyod         ###   ########.fr       */
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

typedef struct s_table	t_table;
typedef struct s_philo	t_philo;

typedef struct s_philo
{
	int					id;
	bool				is_dead;
	bool				is_full;
	int					is_eating;
	long long			eat_count;
	long long			time_to_die;
	long long			time_to_eat;
	long long			time_to_sleep;
	long long			last_meal_time;
	pthread_t			thread_id;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		lock;
	t_table				*table;
}						t_philo;

typedef struct s_table
{
	int					num_of_philos;
	long long			time_to_die;
	long long			time_to_eat;
	long long			time_to_sleep;
	int					num_of_must_eat;
	int					num_of_finish;
	bool				end_flag;
	long			start_time;
	int someone_died;               // 誰かが死んだかどうか
	pthread_mutex_t death_mutex;    //死んだかどうかの状態を更新するミューテックス
	pthread_mutex_t print_mutex;    //出力を制御するミューテクス
	pthread_mutex_t simu_end_mutex; // 終了フラグ保護用
	pthread_t			monitor;
	pthread_mutex_t		table_lock;
	pthread_mutex_t		forks[201];
	t_philo				philos[201];
}						t_table;

#endif

// init
// init -> input_validation
bool					validate_input_parameters(t_table *table);
void					input_validation(int argc, char **argv, t_table *table);

// init -> init_table
bool					destory_mutex_table(t_table *table, int i);
bool					init_data(int argc, char **argv, t_table *table);

// init -> init_philos
bool					destory_mutex_philo_lock(t_table *table, int i);
void					set_fork(t_philo *philo, pthread_mutex_t *fork,
							int pos);
bool					init_philo(t_table *table);

// init -> check_arg
bool					check_arg(int argc, char **argv);

// utils
int						ft_atoi(const char *str);
bool					ft_isspace(const char *str);

long				get_current_time_ms(void);
void					sleep_for_ms(int time);
void					sleeping_philo(t_philo *philo);

// context
// fork
int						take_fork(t_philo *philo);
void					release_fork(t_philo *philo);

bool					can_philo_continue(t_philo *philo);
void					start_lifecycle(t_philo *philo);

void					print_fork(t_philo *philo);
void					print_eating(t_philo *philo);
void					print_sleeping(t_philo *philo);
void					print_thinking(t_philo *philo);
void					print_dead(t_philo *philo);

void					eating(t_philo *philo);
void					sleeping(t_philo *philo);

// start_philo
void					adjust_routine_timing(t_philo *philo);
void					*start_philos(void *philo_p);
void					start_one_philo(t_table *table);

// start_table
void					start_table(t_table *table);
void					end_table(t_table *table);

// main
void					join_all_threads(t_table *table);
