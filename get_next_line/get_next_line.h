/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 21:16:21 by echoukri          #+#    #+#             */
/*   Updated: 2022/11/05 21:23:41 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 300
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif