/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 21:16:21 by echoukri          #+#    #+#             */
/*   Updated: 2022/11/13 20:05:53 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
// # define BUFFER_SIZE 600
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

char	*handle_null(int bytes_read, char	*static_str, char	*read_str);
size_t	gnl_strlen(const char *s);
char	*gnl_substr(char const *s, unsigned int start, size_t len);
char	*get_next_line(int fd);

#endif