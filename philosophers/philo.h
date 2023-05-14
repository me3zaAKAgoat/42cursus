/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 09:21:41 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/14 20:23:44 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>

typedef unsigned long	t_msecond;

typedef enum state{ALIVE, DEAD, FINISHED}	t_state;

typedef struct s_philosopher
{
	int				philo_id;
	pthread_t		thread_id;
	pthread_mutex_t	fork;
	unsigned long	last_ate;
	int				meals_count;
	t_state			state;
}	t_philosopher;

typedef struct s_meta
{
	int				nbr_philosophers;
	t_msecond		time_eat;
	t_msecond		time_die;
	t_msecond		time_sleep;
	int				meal_threshold;
	t_msecond		program_start;
	t_philosopher	*philosophers;
}	t_meta;

typedef struct s_thread_args
{
	t_meta	*meta;
	int		philo_id;
}	t_thread_args;

extern int	ft_atoi(const char *str);

#endif