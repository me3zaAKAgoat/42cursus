/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 09:21:45 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/27 05:46:02 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		pthread_mutex_destroy(&meta->philos[i++].fork);
	pthread_mutex_destroy(&meta->death_lock);
}

t_thread_args	*setup_args(t_meta *meta)
{
	t_thread_args	*thread_args;

	thread_args = malloc(meta->nbr_philos * sizeof(t_thread_args));
	if (!thread_args)
		free(meta->philos);
	return (thread_args);
}

int	setup_threads(t_meta *meta, t_thread_args *args)
{
	int	i;

	i = 0;
	while (i < meta->nbr_philos)
	{
		args[i].philo_id = i;
		args[i].meta = meta;
		if (pthread_create(&meta->philos[i].thread_id,
				NULL, routine, args + i))
			msg_quit("creation of a thread failed");
		if (pthread_detach(meta->philos[i].thread_id))
			msg_quit("detachement of a thread failed");
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_meta			meta;
	t_thread_args	*args;

	if (init_meta(&meta, ac, av))
		return (1);
	args = setup_args(&meta);
	if (!args)
		msg_quit("was not able to allocate needed memory space!");
	if (setup_threads(&meta, args))
		return (1);
	monitor_threads(&meta);
	free(args);
	mutex_clear(&meta);
	free(meta.philos);
	return (0);
}
