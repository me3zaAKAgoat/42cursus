/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 09:21:41 by echoukri          #+#    #+#             */
/*   Updated: 2023/06/10 10:42:13 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>

typedef long long	t_msecond;

typedef enum state {TAKING_FORK, EATING,\
		SLEEPING, THINKING, DIED}	t_state;

typedef struct s_philosopher
{
	int				philo_id;
	pthread_t		thread_id;
	pthread_mutex_t	fork;
	pthread_mutex_t	last_ate_lock;
	pthread_mutex_t	finished_lock;
	t_msecond		last_ate_at;
	int				meals_count;
	int				finished;
}	t_philosopher;

typedef struct s_meta
{
	int				nbr_philos;
	t_msecond		time_eat;
	t_msecond		time_die;
	t_msecond		time_sleep;
	int				meal_threshold;
	t_msecond		program_start;
	t_philosopher	*philos;
	pthread_mutex_t	death_lock;
}	t_meta;

typedef struct s_thread_args
{
	t_meta	*meta;
	int		philo_id;
}	t_thread_args;

extern int				ft_atoi(const char *str);
extern t_msecond		get_time(void);
extern t_msecond		timestamp(t_meta	*meta);
extern void				*routine(void	*ptr);
extern t_philosopher	*init_philos(t_meta *meta);
extern int				init_meta(t_meta *meta, int ac, char **av);
extern int				msg_quit(char *str);
extern size_t			ft_strlen(const char *s);
extern void				msleep(t_msecond wait_time);
extern void				inform_state(t_meta	*meta, t_state state, int philo_id);
extern t_philosopher	*init_philos(t_meta *meta);
extern void				*routine(void	*ptr);
extern int				is_finished(t_meta *meta, int philo_id);
extern int				is_dead(t_meta *meta, int philo_id);

#endif