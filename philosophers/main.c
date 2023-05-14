/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 09:21:45 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/14 17:38:52 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_msecond	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

void	*routine(void	*ptr)
{
	int				philo_id;
	t_meta			*meta;

	meta = ((t_thread_args *) ptr)->meta;
	philo_id = ((t_thread_args *) ptr)->philo_id;
	if (philo_id % 2 == 0)
		usleep(meta->time_eat / 2);
	while (1)
	{
		pthread_mutex_lock(&meta->philosophers[philo_id].fork);
		printf("%lu: %d has taken fork\n", get_time() - meta->program_start, philo_id + 1);
		pthread_mutex_lock(&meta->philosophers[(philo_id + 1) % meta->nbr_philosophers].fork);
		printf("%lu: %d has taken fork\n", get_time() - meta->program_start, philo_id + 1);
		printf("%lu: %d is eating\n", get_time() - meta->program_start, philo_id + 1);
		usleep(meta->time_eat * 1000);
		meta->philosophers[philo_id].last_ate = get_time();
		meta->philosophers[philo_id].meals_count++;
		pthread_mutex_unlock(&meta->philosophers[philo_id].fork);
		pthread_mutex_unlock(&meta->philosophers[(philo_id + 1) % meta->nbr_philosophers].fork);
		if (meta->philosophers[philo_id].meals_count >= meta->meal_threshold)
			return (printf("%lu: %d is finished\n"), NULL),
		if (get_time() - meta->philosophers[philo_id].last_ate > meta->time_die)
			return (printf("%lu: %d has died\n"), NULL),
		printf("%lu: %d is sleeping\n", get_time() - meta->program_start, philo_id + 1);
		usleep(meta->time_sleep * 1000);
		printf("%lu: %d is thinking\n", get_time() - meta->program_start, philo_id + 1);
	}
	return (NULL);
}

/* check wether mutex init can fail*/
t_philosopher	*init_philosophers(t_meta *meta)
{
	int				i;
	t_philosopher	*philosophers;

	i = 0;
	philosophers = malloc(meta->nbr_philosophers * sizeof(t_philosopher));
	if (!philosophers)
		exit(1);
	while (i < meta->nbr_philosophers)
	{
		pthread_mutex_init(&philosophers[i].fork, NULL);
		philosophers[i].last_ate = get_time();
		philosophers[i].meals_count = 0;
		philosophers[i].philo_id = i;
		i++;
	}
	return (philosophers);
}

void	init_meta(t_meta *meta, char **av)
{
	meta->program_start = get_time();
	meta->nbr_philosophers = ft_atoi(av[1]);
	meta->time_die = ft_atoi(av[2]);
	meta->time_eat = ft_atoi(av[3]);
	meta->time_sleep = ft_atoi(av[4]);
	meta->meal_threshold = ft_atoi(av[5]);
	meta->philosophers = init_philosophers(meta);
}

/* need to handle optinal 5th argument*/
int	main(int ac, char **av)
{
	t_meta			meta;
	t_thread_args	thread_args;
	int				i;

	init_meta(&meta, av);
	i = 0;
	while (i < meta.nbr_philosophers)
	{
		thread_args.philo_id = i;
		thread_args.meta = &meta;
		pthread_create(&meta.philosophers[i].thread_id, NULL, routine, &thread_args);
		pthread_detach(meta.philosophers[i].thread_id);
		i++;
	}
	while (1) continue;
	exit(0);
}
