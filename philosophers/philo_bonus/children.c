/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:56:17 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/31 19:44:55 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	is_alive(pid_t pid, int	*state_p)
{
	return (waitpid(pid, state_p, WNOHANG) == 0);
}

int	is_finished(t_meta *meta, int philo_id)
{
	sem_wait(meta->sync);
	if (meta->philos[philo_id].finished)
		return (sem_post(meta->sync), 1);
	return (sem_post(meta->sync), 0);
}

int	is_dead(t_meta *meta, int philo_id)
{
	sem_wait(meta->sync);
	if (get_time() - meta->philos[philo_id].last_ate_at > meta->time_die)
		return (sem_post(meta->sync), 1);
	return (sem_post(meta->sync), 0);
	
}

void	monitor_thread(t_meta *meta, int philo_id)
{
	while (!is_finished(meta, philo_id))
	{
		if (is_dead(meta, philo_id))
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
