/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:56:17 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/27 05:47:14 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	kill_children(t_meta *meta)
{
	int	i;

	i = 0;
	while (i < meta->nbr_philos)
		kill(meta->philos[i++].pid, SIGKILL);
}

void	monitor_thread(t_meta *meta, int philo_id)
{
	while (!meta->philos[philo_id].finished)
	{
		if (get_time() - meta->philos[philo_id].last_ate_at > meta->time_die)
		{
			inform_state(meta, DIED, philo_id);
			sem_wait(meta->death_lock);
			exit(DEATH_EXIT);
		}
	}
	exit(0);
}

void	setup_forks(t_meta *meta, t_thread_args *args)
{
	int	i;

	i = 0;
	while (i < meta->nbr_philos)
	{
		args[i].philo_id = i;
		args[i].meta = meta;
		meta->philos[i].pid = fork();
		if (!meta->philos[i].pid)
		{
			if (pthread_create(&meta->philos[i].thread_id,
					NULL, routine, args + i))
				wrexit("thread creation failed");
			if (pthread_detach(meta->philos[i].thread_id))
				wrexit("thread detachement failed");
			monitor_thread(meta, i);
			exit(0);
		}
		i++;
	}
}
