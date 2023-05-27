/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 09:21:45 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/27 05:24:38 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	sem_clear(t_meta *meta)
{
	sem_close(meta->forks);
	sem_close(meta->death_lock);
	sem_close(meta->sync);
}

void	wait_children(t_meta *meta)
{
	int	state;
	int	i;
	int	all_finished;

	while (1)
	{
		i = 0;
		all_finished = 1;
		while (i < meta->nbr_philos)
		{
			if (waitpid(meta->philos[i].pid, &state, WNOHANG) == 0)
				all_finished = 0;
			if (WIFEXITED(state) && WEXITSTATUS(state) == DEATH_EXIT)
			{
				kill_children(meta);
				return ;
			}
			i++;
		}
		if (all_finished)
			return ;
	}
}

t_thread_args	*setup_args(t_meta *meta)
{
	t_thread_args	*args;

	args = malloc(meta->nbr_philos * sizeof(args));
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
	launch_children(&meta);
	wait_children(&meta);
	sem_clear(&meta);
	free(meta.philos);
	free(args);
	exit(0);
}
