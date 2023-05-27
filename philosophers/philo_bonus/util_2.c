/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 03:53:11 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/27 03:56:48 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	launch_children(t_meta *meta)
{
	int	i;

	i = 0;
	while (i++ < meta->nbr_philos)
		sem_post(meta->sync);
}
