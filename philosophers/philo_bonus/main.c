/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 09:21:45 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/25 22:19:45 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void cheesy_void(void)
{
	return ;
}

void	routine(int philo_id, t_meta *meta)
{
	if (philo_id % 2 == 0)
		msleep(50);
	while (1)
	{
		sem_wait(meta->forks);
		inform_state(meta, TAKING_FORK, philo_id);
		sem_wait(meta->forks);
		inform_state(meta, TAKING_FORK, philo_id);
		inform_state(meta, EATING, philo_id);
		msleep(meta->time_eat);
		meta->philos[philo_id].last_ate_at = get_time();
		meta->philos[philo_id].meals_count++;
		sem_post(meta->forks);
		sem_post(meta->forks);
		if (meta->meal_threshold != -1 && meta->philos[philo_id].meals_count >= meta->meal_threshold)
			return (meta->philos[philo_id].finished = 1, inform_state(meta, FINISHED, philo_id), cheesy_void());
		inform_state(meta, SLEEPING, philo_id);
		msleep(meta->time_sleep);
		inform_state(meta, THINKING, philo_id);
	}
}

void	monitor_threads(t_meta *meta)
{
	int	i;
	int	all_finished;

	while (1)
	{
		i = 0;
		all_finished = 1;
		while (i < meta->nbr_philos)
		{
			if (!meta->philos[i].finished
				&& get_time() - meta->philos[i].last_ate_at > meta->time_die)
			{
				inform_state(meta, DIED, i);
				sem_wait(meta->death_lock);
				return ;	
			}
			if (!meta->philos[i].finished)
				all_finished = 0;
			i++;
		}
		if (all_finished)
			return ;
	}
}

void	sem_clear(t_meta *meta)
{
	sem_close(meta->forks);
	sem_close(meta->death_lock);
}

int	main(int ac, char **av)
{
	t_meta			meta;
	int				i;
	int				monitor_pid;

	init_meta(&meta, ac, av);
	i = 0;
	monitor_pid = fork();
	if (!monitor_pid)
	{		
		monitor_threads(&meta);
		exit(0);
	}
	while (i < meta.nbr_philos)
	{
		meta.philos[i].pid = fork();
		if (!meta.philos[i].pid)
		{
			routine(i, &meta);
			exit(0);
		}
		i++;
	}
	waitpid(monitor_pid, NULL, WNOHANG);
	sem_clear(&meta);
	free(meta.philos);
	exit(0);
}
