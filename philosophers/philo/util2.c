/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:38:55 by echoukri          #+#    #+#             */
/*   Updated: 2023/06/09 14:55:19 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_finished(t_meta *meta, int philo_id)
{
	pthread_mutex_lock(&meta->philos[philo_id].finished_lock);
	if (meta->philos[philo_id].finished)
		return (pthread_mutex_unlock(&meta->philos[philo_id].finished_lock), 1);
	return (pthread_mutex_unlock(&meta->philos[philo_id].finished_lock), 0);
}

int	is_dead(t_meta *meta, int philo_id)
{
	pthread_mutex_lock(&meta->philos[philo_id].last_ate_lock);
	if (get_time() - meta->philos[philo_id].last_ate_at > meta->time_die)
		return (pthread_mutex_unlock(&meta->philos[philo_id].last_ate_lock), 1);
	return (pthread_mutex_unlock(&meta->philos[philo_id].last_ate_lock), 0);
}

