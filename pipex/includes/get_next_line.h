/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 21:16:21 by echoukri          #+#    #+#             */
/*   Updated: 2023/01/17 18:23:25 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 300
# endif
# include <unistd.h>
# include <stdlib.h>

extern	size_t	gnl_strlen(const char *s);
extern	char		*gnl_substr(char const *s, unsigned int start, size_t len);
extern	char		*get_next_line(int fd);

#endif