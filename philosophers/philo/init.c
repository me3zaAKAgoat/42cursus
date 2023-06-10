/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 20:51:57 by echoukri          #+#    #+#             */
/*   Updated: 2023/06/09 14:34:44 by echoukri         ###   ########.fr       */
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
		return (NULL);
	while (i < meta->nbr_philos)
	{
		pthread_mutex_init(&philos[i].fork, NULL);
		pthread_mutex_init(&philos[i].finished_lock, NULL);
		pthread_mutex_init(&philos[i].last_ate_lock, NULL);
		philos[i].last_ate_at = get_time();
		philos[i].meals_count = 0;
		philos[i].philo_id = i;
		philos[i].finished = 0;
		i++;
	}
	return (philos);
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!(48 <= str[i] && str[i] <= 57))
			return (0);
		i++;
	}
	return (1);
}

void	set_values(t_meta *meta, char **av)
{
	meta->program_start = get_time();
	meta->nbr_philos = ft_atoi(av[1]);
	meta->time_die = ft_atoi(av[2]);
	meta->time_eat = ft_atoi(av[3]);
	meta->time_sleep = ft_atoi(av[4]);
}

int	invalid_values(t_meta *meta, int ac)
{
	if (ac == 6)
	{
		if (meta->nbr_philos <= 0 || meta->meal_threshold <= 0 || meta->time_die
			<= 0 || meta->time_sleep <= 0 || meta->time_eat <= 0)
			return (1);
	}
	else
	{
		if (meta->nbr_philos <= 0 || meta->time_die
			<= 0 || meta->time_sleep <= 0 || meta->time_eat <= 0)
			return (1);
	}
	return (0);
}

int	init_meta(t_meta *meta, int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (msg_quit("abnormal input was given!"), 1);
	if (!is_number(av[1]) || !is_number(av[2])
		|| !is_number(av[3]) || !is_number(av[4]))
		return (msg_quit("abnormal input was given!"), 1);
	set_values(meta, av);
	pthread_mutex_init(&meta->death_lock, NULL);
	if (ac == 6)
		meta->meal_threshold = ft_atoi(av[5]);
	else
		meta->meal_threshold = -1;
	if (invalid_values(meta, ac))
		return (msg_quit("abnormal input was given!"), 1);
	meta->philos = init_philos(meta);
	if (!meta->philos)
		return (msg_quit("was not able to allocate needed memory space!"), 1);
	return (0);
}
