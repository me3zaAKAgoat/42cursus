/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 09:21:45 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/23 02:52:33 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void	*ptr)
{
	int				philo_id;
	t_meta			*meta;

	meta = ((t_thread_args *) ptr)->meta;
	philo_id = ((t_thread_args *) ptr)->philo_id;
	if (philo_id % 2 == 0)
		msleep(meta->time_eat / 2);
	while (1)
	{
		pthread_mutex_lock(&meta->philos[philo_id].fork);
		inform_state(meta, TAKING_FORK, philo_id);
		pthread_mutex_lock(&meta->philos[(philo_id + 1) % meta->nbr_philos].fork);
		inform_state(meta, TAKING_FORK, philo_id);
		inform_state(meta, EATING, philo_id);
		msleep(meta->time_eat);
		meta->philos[philo_id].last_ate_at = get_time();
		meta->philos[philo_id].meals_count++;
		pthread_mutex_unlock(&meta->philos[philo_id].fork);
		pthread_mutex_unlock(&meta->philos[(philo_id + 1) % meta->nbr_philos].fork);
		if (meta->meal_threshold != -1 && meta->philos[philo_id].meals_count >= meta->meal_threshold)
			return (meta->philos[philo_id].finished = 1, inform_state(meta, FINISHED, philo_id), NULL);
		inform_state(meta, SLEEPING, philo_id);
		msleep(meta->time_sleep);
		inform_state(meta, THINKING, philo_id);
	}
	return (NULL);
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
				pthread_mutex_lock(&meta->death_lock);
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

void	mutex_clear(t_meta *meta)
{
	int	i;

	i = 0;
	while (i < meta->nbr_philos)
	{
		pthread_mutex_unlock(&meta->philos[i].fork);
		pthread_mutex_destroy(&meta->philos[i].fork);
		i++;
	}
	pthread_mutex_unlock(&meta->death_lock);
	pthread_mutex_destroy(&meta->death_lock);
}

t_thread_args	*setup_args(t_meta *meta, t_thread_args **thread_args_p)
{
	*thread_args_p = malloc(meta->nbr_philos * sizeof(*thread_args_p));
	if (!*thread_args_p)
	{
		free(meta->philos);
		wrexit("was not able to allocate needed memory space!");
	}
}

int	main(int ac, char **av)
{
	t_meta			meta;
	t_thread_args	*thread_args;
	int				i;

	init_meta(&meta, ac, av);
	setup_args(&meta, &thread_args);
	i = 0;
	while (i < meta.nbr_philos)
	{
		thread_args[i].philo_id = i;
		thread_args[i].meta = &meta;
		pthread_create(&meta.philos[i].thread_id,
			NULL, routine, thread_args + i);
		pthread_detach(meta.philos[i].thread_id);
		i++;
	}
	monitor_threads(&meta);
	free(thread_args);
	mutex_clear(&meta);
	free(meta.philos);
	exit(0);
}
