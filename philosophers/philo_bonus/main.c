/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 09:21:45 by echoukri          #+#    #+#             */
/*   Updated: 2023/06/05 09:17:55 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	clean_up(t_meta *meta, t_thread_args *args)
{
	sem_close(meta->forks);
	sem_close(meta->death_lock);
	sem_close(meta->sync);
	free(meta->philos);
	free(args);
}

void	wait_children(t_meta *meta)
{
	int	state;
	int	i;
	int	all_finished;

	all_finished = 0;
	while (!all_finished)
	{
		i = 0;
		all_finished = 1;
		while (i < meta->nbr_philos)
		{
			if (is_alive(meta->philos[i].pid, &state))
				all_finished = 0;
			if (WIFEXITED(state) && WEXITSTATUS(state) == DEATH_EXIT)
				return (kill_children(meta));
			i++;
		}
	}
}

t_thread_args	*setup_args(t_meta *meta)
{
	t_thread_args	*args;

	args = malloc(meta->nbr_philos * sizeof(t_thread_args));
	if (!args)
	{
		free(meta->philos);
		wrexit("was not able to allocate needed memory space!");
	}
	return (args);
}

int	main(int ac, char **av)
{
	t_meta			meta;
	t_thread_args	*args;

	init_meta(&meta, ac, av);
	args = setup_args(&meta);
	setup_forks(&meta, args);
	wait_children(&meta);
	clean_up(&meta, args);
	exit(0);
}
