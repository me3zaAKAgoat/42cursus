/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:38:30 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/31 19:38:56 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	kill_children(t_meta *meta)
{
	int	i;

	i = 0;
	while (i < meta->nbr_philos)
		kill(meta->philos[i++].pid, SIGKILL);
}
