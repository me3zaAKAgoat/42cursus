/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 20:51:57 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/21 01:20:38 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philosopher	*init_philos(t_meta *meta)
{
	int				i;
	t_philosopher	*philos;

	i = 0;
	philos = malloc(meta->nbr_philos * sizeof(t_philosopher));
	if (!philos)
		wrexit("was not able to allocated needed memory space!");
	while (i < meta->nbr_philos)
	{
		pthread_mutex_init(&philos[i].fork, NULL);
		philos[i].last_ate_at = get_time();
		philos[i].meals_count = 0;
		philos[i].philo_id = i;
		philos[i].finished = 0;
		philos[i].dead = 0;
		i++;
	}
	return (philos);
}

void	init_meta(t_meta *meta, int ac, char **av)
{
	if (ac < 5 || ac > 6)
		wrexit("abnormal input was given!");
	meta->program_start = get_time();
	meta->nbr_philos = ft_atoi(av[1]);
	meta->time_die = ft_atoi(av[2]);
	meta->time_eat = ft_atoi(av[3]);
	meta->time_sleep = ft_atoi(av[4]);
	if (ac == 6)
	{
		meta->meal_threshold = ft_atoi(av[5]);
		if (meta->nbr_philos * meta->time_die * meta->meal_threshold < 0)
			wrexit("abnormal input was given!");
	}
	else
	{
		meta->meal_threshold = -1;
		if (meta->nbr_philos * meta->time_die < 0)
			wrexit("abnormal input was given!");
	}
	meta->philos = init_philos(meta);
}
