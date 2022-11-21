/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:18:51 by echoukri          #+#    #+#             */
/*   Updated: 2022/11/21 15:07:20 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

void	convert_char(int c, int *pto_count);
void	ft_putulong(unsigned long nb, char *base_s, int *pto_count);
void	ft_putslong(long nb, char *base_s, int *pto_count);
void	convert_str(const char *arg, int *pto_count);
int		ft_printf(const char *s, ...);

#endif
