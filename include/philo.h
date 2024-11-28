/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:10:09 by ctokoyod          #+#    #+#             */
/*   Updated: 2024/11/28 21:46:46 by ctokoyod         ###   ########.fr       */
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
	pthread_mutex_t last_meal_mutex; //最後の食事時間保護用
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
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	long long		num_must_eat;
	long long		start_time;
	int someone_died;               // 誰かが死んだかどうか
	pthread_mutex_t death_mutex;    //死んだかどうかの状態を更新するミューテックス
	pthread_mutex_t print_mutex;    //出力を制御するミューテクス
	pthread_mutex_t simu_end_mutex; // 終了フラグ保護用
	int				simu_end;
	t_philo *philo; //哲学者の配列
	t_fork *fork;   //フォークの配列
	int				error;
}					t_data;

// main.c
int					parse_arguments(int argc, char **argv, t_data *data);

// init.c
int					init_mutexes(t_data *data);
int					init_philos(t_data *data);
int					init_forks(t_data *data);
void				init_data(t_data *data);

// utils
int					print_error(void);
int					ft_atoi(const char *str);

// time
long long			get_time(void);
void	precise_sleep_time(long long duration_ms);

// start_philo.c
int					start_philos(t_data *data);
void				precise_sleep_time(long long duration_ms);

// eat
int					eat(t_philo *philo);

// death
int					check_death(t_philo *philo);


// monitor
int	start_monitoring(t_data *data);
void	*monitor_philos(void *arg);

#endif