/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:12:11 by echoukri          #+#    #+#             */
/*   Updated: 2022/10/14 11:12:11 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LIBFT_H
#define LIBFT_H

#include <stdlib.h>
extern void	ft_bzero(void *s, size_t n);
extern int	ft_toupper(int c);
extern int	ft_tolower(int c);
extern int	ft_strlen(const char *s);
extern void	ft_memset(void *b, int c, size_t len);
extern void	ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
extern void	ft_memmove(void *dst, const void *src, size_t len);
extern int	ft_isprint(int c);
extern int	ft_isdigit(int c);
extern int	ft_isascii(int c);
extern int	ft_isalpha(int c);
extern int	ft_isalnum(int c);
extern size_t ft_strlcpy(char * restrict dst, const char * restrict src, size_t dstsize);
extern int	ft_atoi(char *str);
extern size_t	ft_strlcat(char *dst, char *src, size_t size);

#endif