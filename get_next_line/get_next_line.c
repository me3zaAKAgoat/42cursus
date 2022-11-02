/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 01:08:56 by echoukri          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/10/30 17:58:56 by echoukri         ###   ########.fr       */
=======
/*   Updated: 2022/10/31 12:24:40 by echoukri         ###   ########.fr       */
>>>>>>> 38ca8f4 (removed protections from segfaults in functions that would not cause memory leaks and brushed up the algorithm of GNL)
/*                                                                            */
/* ************************************************************************** */

/*
-read buffer size characters from the file descriptor and put it in 
string variable.
<<<<<<< HEAD
-check for a newline character or a nullbyte character.
-set a static variable that keeps the string.
-keep the read string as long as it's not fully exhausted
-only when the string is exhausted prompt another read command
- exhaustion? have a variable that keeps the count of characters that haven't been exhausted
=======
-set the bytes read static variable
-the static string variable should be thought of as a big chain that gets 
upcoming read strings glued to it and returned strings split from it
>>>>>>> 38ca8f4 (removed protections from segfaults in functions that would not cause memory leaks and brushed up the algorithm of GNL)
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
<<<<<<< HEAD
	static int	iterator_on_str;
	static char	str[BUFFER_SIZE];
	static int	bytes_left;
	char		*return_str;

	iterator_on_str = 0;
	if (bytes_left)
	{
		while (str[iterator_on_str])
		{
			if (str[iterator_on_str] == c || str[iterator_on_str] == '\0')
			{
				bytes_left -= iterator_on_str;
				return_str = ft_substr(str, 0, iterator_on_str);
				return (return_str);				
			}

		}
		return (ft_substr());
	}
	bytes_left = read(fd, str, BUFFER_SIZE);
	while (bytes_left)
	{

	}

}

int main()
{
	int	f;

=======
	char		str[BUFFER_SIZE];
	int			i;
	static char	**lines_arr;
	static int	list_index;
	static int	list_length;

	if (list_index >= list_length - 1)
	{
		read(fd, str, BUFFER_SIZE);
		while (str[i])
		{
			if (str[i] == '\n')
				list_length++;
			i++;
		}
		lines_arr = ft_split(str, '\n');
		list_index = 0;
		return (lines_arr[list_index]);
	}
	else
	{
		list_index++;
		return (lines_arr[list_index]);
	}
}

int main()
{
	int	f;

>>>>>>> 38ca8f4 (removed protections from segfaults in functions that would not cause memory leaks and brushed up the algorithm of GNL)
	f = open("get_next_line.c", O_RDONLY);
	printf("%s", get_next_line(f));
	printf("%s", get_next_line(f));
	printf("%s", get_next_line(f));
	printf("%s", get_next_line(f));
	printf("%s", get_next_line(f));
	return (0);
}
