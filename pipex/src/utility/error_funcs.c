/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 18:25:02 by echoukri          #+#    #+#             */
/*   Updated: 2023/01/28 18:50:48 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
this function is used to quit and send an error msg when an error at 
the init_struct fucntion occurs
*/

void	perr_exit(char *msg)
{
	perror(msg);
	exit(1);
}
