/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:35:29 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/31 19:51:30 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	take_forks(t_meta *meta, int philo_id)
{
	sem_wait(meta->forks);
	inform_state(meta, TAKING_FORK, philo_id);
	sem_wait(meta->forks);
	inform_state(meta, TAKING_FORK, philo_id);
}

int	reached_meal_threshold(t_meta *meta, int philo_id)
{
	return (meta->meal_threshold != -1
		&& meta->philos[philo_id].meals_count >= meta->meal_threshold);
}

void	set_finished(t_meta *meta, int philo_id)
{
	sem_wait(meta->sync);
	meta->philos[philo_id].finished = 1;
	sem_post(meta->sync);
}

void	*routine(void *ptr)
{
	t_meta	*meta;
	int		philo_id;

	meta = ((t_thread_args *)ptr)->meta;
	philo_id = ((t_thread_args *)ptr)->philo_id;
	if (philo_id % 2 == 0)
		msleep(1);
	sem_wait(meta->sync);
	meta->philos[philo_id].last_ate_at = get_time();
	sem_post(meta->sync);
	while (1)
	{
		take_forks(meta, philo_id);
		inform_state(meta, EATING, philo_id);
		sem_wait(meta->sync);
		meta->philos[philo_id].last_ate_at = get_time();
		sem_post(meta->sync);
		msleep(meta->time_eat);
		meta->philos[philo_id].meals_count++;
		sem_post(meta->forks);
		sem_post(meta->forks);
		if (reached_meal_threshold(meta, philo_id))
			return (set_finished(meta, philo_id),
				inform_state(meta, FINISHED, philo_id), NULL);
		inform_state(meta, SLEEPING, philo_id);
		msleep(meta->time_sleep);
		inform_state(meta, THINKING, philo_id);
	}
	return (NULL);
}
