/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 09:21:45 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/18 02:20:42 by echoukri         ###   ########.fr       */
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
		usleep((meta->time_eat / 2) * 1000);
	while (1)
	{
		pthread_mutex_lock(&meta->philosophers[philo_id].fork);
		printf("%llu: %d has taken fork\n", timestamp(meta), philo_id + 1);
		pthread_mutex_lock(&meta->philosophers[(philo_id + 1) % meta->nbr_philosophers].fork);
		printf("%llu: %d has taken fork\n", timestamp(meta), philo_id + 1);
		printf("%llu: %d is eating\n", timestamp(meta), philo_id + 1);
		usleep(meta->time_eat * 1000);
		meta->philosophers[philo_id].last_ate = get_time();
		meta->philosophers[philo_id].meals_count++;
		pthread_mutex_unlock(&meta->philosophers[philo_id].fork);
		pthread_mutex_unlock(&meta->philosophers[(philo_id + 1) % meta->nbr_philosophers].fork);
		if (meta->meal_threshold != -1 && meta->philosophers[philo_id].meals_count >= meta->meal_threshold)
			return (meta->philosophers[philo_id].finished = 1, printf("%llu: %d is finished\n", timestamp(meta), philo_id + 1), NULL);
		printf("%llu: %d is sleeping\n", timestamp(meta), philo_id + 1);
		usleep(meta->time_sleep * 1000);
		printf("%llu: %d is thinking\n", timestamp(meta), philo_id + 1);
	}
	return (NULL);
}

/* wait_philosophers wether mutex init can fail*/
t_philosopher	*init_philosophers(t_meta *meta)
{
	int				i;
	t_philosopher	*philosophers;

	i = 0;
	philosophers = malloc(meta->nbr_philosophers * sizeof(t_philosopher));
	if (!philosophers)
		wrexit("was not able to allocated needed memory space!");
	while (i < meta->nbr_philosophers)
	{
		pthread_mutex_init(&philosophers[i].fork, NULL);
		philosophers[i].last_ate = get_time();
		philosophers[i].meals_count = 0;
		philosophers[i].philo_id = i;
		philosophers[i].finished = 0;
		i++;
	}
	return (philosophers);
}

void	init_meta(t_meta *meta, int ac, char **av)
{
	meta->program_start = get_time();
	meta->nbr_philosophers = ft_atoi(av[1]);
	meta->time_die = ft_atoi(av[2]);
	meta->time_eat = ft_atoi(av[3]);
	meta->time_sleep = ft_atoi(av[4]);
	if (ac == 6)
	{
		meta->meal_threshold = ft_atoi(av[5]);
		if (meta->nbr_philosophers * meta->time_die * meta->meal_threshold < 0)
			wrexit("abnormal input was given!");
	}
	else
	{
		meta->meal_threshold = -1;
		if (meta->nbr_philosophers * meta->time_die < 0)
			wrexit("abnormal input was given!");
	}
	meta->philosophers = init_philosophers(meta);
}

void	wait_philosophers(t_meta *meta)
{
	int	i;
	int	all_finished;

	while (1)
	{
		i = 0;
		all_finished = 1;
		while (i < meta->nbr_philosophers)
		{
			if (!meta->philosophers[i].finished
				&& get_time() - meta->philosophers[i].last_ate > meta->time_die)
			{
				printf("%llu: %d died\n", timestamp(meta), i + 1);
				return ;
			}
			if (!meta->philosophers[i].finished)
				all_finished = 0;
			i++;
		}
		if (all_finished)
			return ;
	}
}

int	main(int ac, char **av)
{
	t_meta			meta;
	t_thread_args	*thread_args;
	int				i;

	init_meta(&meta, ac, av);
	thread_args = malloc(meta.nbr_philosophers * sizeof(thread_args));
	if (!thread_args)
	{
		free(meta.philosophers);
		wrexit("was not able to allocate needed memory space!");
	}
	i = 0;
	while (i < meta.nbr_philosophers)
	{
		thread_args[i].philo_id = i;
		thread_args[i].meta = &meta;
		pthread_create(&meta.philosophers[i].thread_id,
			NULL, routine, thread_args + i);
		pthread_detach(meta.philosophers[i].thread_id);
		i++;
	}
	free(thread_args);
	wait_philosophers(&meta);
	while (i--)
		pthread_mutex_destroy(&meta.philosophers[i].fork);
	free(meta.philosophers);
	exit(0);
}
