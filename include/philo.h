/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:10:09 by ctokoyod          #+#    #+#             */
/*   Updated: 2024/09/22 19:14:33 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>

typedef enum
{
	THINKING,
	EATING,
	SLEEPING
}					t_state;

typedef struct s_philo
{
	int				id;
	t_state			state;// 哲学者の今の状態　
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
	t_fork *forks;               //フォークの配列
}					t_data;

#endif