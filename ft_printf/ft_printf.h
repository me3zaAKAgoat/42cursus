/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:18:51 by echoukri          #+#    #+#             */
/*   Updated: 2022/11/16 14:23:53 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

void	ft_putulong(unsigned long nb, char *str);
void	ft_putdecimal(long nb, char *str);
void	convert_char(char arg);
void	convert_str(char *arg);
void	convert_ptr(void	*arg);
void	convert_decimal(int arg);
void	convert_udecimal(unsigned int arg);

#endif
