/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:25:42 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/26 17:16:29 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_msecond	timestamp(t_meta	*meta)
{
	return (get_time() - meta->program_start);
}

t_msecond	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

void	msleep(t_msecond wait_time)
{
	t_msecond	start;

	start = get_time();
	usleep(wait_time * 1000 * 0.95);
	while (get_time() - start < wait_time)
		usleep(85);
}

void	inform_state(t_meta	*meta, t_state state, int philo_id)
{
	pthread_mutex_lock(&meta->death_lock);
	if (state == TAKING_FORK)
		printf("%llu: %d has taken fork\n", timestamp(meta), philo_id + 1);
	if (state == EATING)
		printf("%llu: %d is eating\n", timestamp(meta), philo_id + 1);
	if (state == SLEEPING)
		printf("%llu: %d is sleeping\n", timestamp(meta), philo_id + 1);
	if (state == THINKING)
		printf("%llu: %d is thinking\n", timestamp(meta), philo_id + 1);
	if (state == FINISHED)
		printf("%llu: %d is finished\n", timestamp(meta), philo_id + 1);
	if (state == DIED)
		printf("%llu: %d has died\n", timestamp(meta), philo_id + 1);
	pthread_mutex_unlock(&meta->death_lock);
}

int	msg_quit(char *str)
{
	write(2, str, ft_strlen(str));
	return (1);
}
