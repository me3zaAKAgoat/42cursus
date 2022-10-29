/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 01:08:56 by echoukri          #+#    #+#             */
/*   Updated: 2022/10/29 21:31:01 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
-read buffer size characters from the file descriptor then check for
a newline character or a nullbyte character
-set a static variable that keeps the file position
*/

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	index;

	if (!dst && !src)
		return (NULL);
	index = 0;
	while (index < n)
	{
		*((char *)dst + index) = *((const char *)src + index);
		index++;
	}
	return (dst);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t			srcl;

	srcl = ft_strlen(src);
	if (srcl < size)
		ft_memcpy(dst, src, srcl + 1);
	else if (size != 0)
	{
		ft_memcpy(dst, src, size - 1);
		dst[size - 1] = '\0';
	}
	return (srcl);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*ptr;
	size_t		slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
	{
		ptr = malloc(1);
		if (!ptr)
			return (NULL);
		*ptr = '\0';
	}
	else
	{
		ptr = malloc((len <= slen - start) * len
				+ (slen - start) * (slen - start < len) + 1);
		if (!ptr)
			return (NULL);
		else
			ft_strlcpy(ptr, s + start, (len <= slen - start) * len
				+ (slen - start) * (slen - start < len) + 1);
	}
	return (ptr);
}

char	*get_next_line(int fd)
{
	int		i;
	int		iterator_on_str;
	char	str[BUFFER_SIZE];

	i = read(fd, &str, BUFFER_SIZE);
	iterator_on_str = 0;
	if (i == 0)
		return (ft_substr(str, 0, iterator_on_str + 1)); // how to handle the case where teh end of file is reached
	while (str[iterator_on_str])
	{
		if (str[iterator_on_str] == '\n')
			return (ft_substr(str, 0, iterator_on_str + 1));
		str++;
	}
	return (ft_substr(str, 0, iterator_on_str + 1));
}

int main()
{
	printf("%s", get_next_line());
	return (0);
}