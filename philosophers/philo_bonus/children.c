/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:56:17 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/26 18:09:18 by echoukri         ###   ########.fr       */
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
