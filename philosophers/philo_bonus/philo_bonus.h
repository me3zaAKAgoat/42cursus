/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 09:21:41 by echoukri          #+#    #+#             */
/*   Updated: 2023/06/05 16:10:01 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# include <pthread.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <semaphore.h>
# include <signal.h>

# define DEATH_EXIT 42

typedef long long	t_msecond;

typedef enum state {TAKING_FORK, EATING,\
		SLEEPING, THINKING, FINISHED, DIED}	t_state;

typedef struct s_philosopher
{
	int				philo_id;
	pthread_t		thread_id;
	pid_t			pid;
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
	sem_t			*forks;
	sem_t			*sync;
	sem_t			*death_lock;
}	t_meta;

typedef struct s_thread_args
{
	t_meta	*meta;
	int		philo_id;
}	t_thread_args;

extern int				is_alive(pid_t pid, int	*state_p);
extern int				ft_atoi(const char *str);
extern t_msecond		get_time(void);
extern t_msecond		timestamp(t_meta	*meta);
extern t_philosopher	*init_philos(t_meta *meta);
extern void				init_meta(t_meta *meta, int ac, char **av);
extern void				wrexit(char *str);
extern size_t			ft_strlen(const char *s);
extern void				msleep(t_msecond wait_time);
extern void				inform_state(t_meta	*meta, t_state state, int philo_id);
extern t_philosopher	*init_philos(t_meta *meta);
extern void				kill_children(t_meta *meta);
extern void				*routine(void *ptr);
extern void				setup_forks(t_meta *meta, t_thread_args *args);
extern void				launch_children(t_meta *meta);
extern void				init_sems(t_meta *meta);

#endif