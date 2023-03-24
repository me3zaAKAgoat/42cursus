/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:31:23 by echoukri          #+#    #+#             */
/*   Updated: 2023/03/23 19:48:16 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_key_press(int key, t_meta_data *fdf)
{	
	if (key == KEY_ESC)
		handle_close_window(fdf);
	return (0);
}
