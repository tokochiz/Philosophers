/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:10:09 by ctokoyod          #+#    #+#             */
/*   Updated: 2024/09/23 19:47:43 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h> // `gettimeofday`
# include <unistd.h>

typedef enum
{
	THINKING,
	EATING,
	SLEEPING
}					t_state;

typedef struct s_philo
{
	int				id;
	t_state			state;
	int				eat_count;
	long long		last_meal_time;
	pthread_t		thread;
	struct s_data	*data;
}					t_philo;

typedef struct s_fork
{
	int				id;
	pthread_mutex_t	mutex;
}					t_fork;

typedef struct s_data
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_must_eat;
	long long		start_time;
	int someone_died;            // 誰かが死んだかどうか
	pthread_mutex_t death_mutex; //死んだかどうかの状態を更新するミューテックス
	pthread_mutex_t print_mutex; //出力を制御するミューテクス
	t_philo *philo;              //哲学者の配列
	t_fork *fork;                //フォークの配列
}					t_data;


// main.c
int					parse_arguments(int argc, char **argv, t_data *data);

// init.c

int					init_philos(t_data *data);
int					init_forks(t_data *data);
int					init_mutexes(t_data *data);
void				init_data(t_data *data);

// utils
int					print_error(void);
int					ft_atoi(const char *str);

// time
long long			get_time(void);

// start_philo.c
int					start_philos(t_data *data, t_philo *philo);

#endif