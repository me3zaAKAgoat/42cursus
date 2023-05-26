/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 09:21:45 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/26 20:14:08 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	cheesy_void(void)
{
	return ;
}

void	monitor_threads(t_meta *meta)
{
	int	i;
	int	all_finished;

	i = 0;
	printf("WE STARTED BOYS : %lld\n", timestamp(meta));
	while (i < meta->nbr_philos)
		sem_post(meta->sync);
	printf("gg\n");
	while (1)
	{
		i = 0;
		all_finished = 1;
		while (i < meta->nbr_philos)
		{
			if (!waitpid(meta->philos[i].pid, NULL, WNOHANG)
				&& get_time() - meta->philos[i].last_ate_at > meta->time_die)
			{
				inform_state(meta, DIED, i);
				sem_wait(meta->death_lock);
				kill_children(meta);
				return ;
			}
			if (!waitpid(meta->philos[i].pid, NULL, WNOHANG))
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
	sem_close(meta->sync);
}

int	main(int ac, char **av)
{
	t_meta			meta;
	int				i;

	init_meta(&meta, ac, av);
	i = 0;
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
	monitor_threads(&meta);
	sem_clear(&meta);
	free(meta.philos);
	exit(0);
}
