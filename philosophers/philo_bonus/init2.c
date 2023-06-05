/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:09:22 by echoukri          #+#    #+#             */
/*   Updated: 2023/06/05 16:09:34 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_sems(t_meta *meta)
{
	sem_unlink("/forks");
	sem_unlink("/death_lock");
	sem_unlink("/sync");
	meta->forks = sem_open("/forks", O_CREAT, 777, meta->nbr_philos);
	meta->death_lock = sem_open("/death_lock", O_CREAT, 777, 1);
	meta->sync = sem_open("/sync", O_CREAT, 777, 1);
}
