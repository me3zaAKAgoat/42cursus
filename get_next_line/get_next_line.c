/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:30:23 by echoukri          #+#    #+#             */
/*   Updated: 2022/11/12 19:29:31 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
whenever get next line is entered the program shall check wether read 
returns 0 or more.
if read is -1 the function shall immediately free static str and 
return NULL.
if read returns 0 and static str is a null pointer the function 
shall return NULL.
if read returns 0 and static str is not a null pointer 
the function shall return static str.
if read isnt 0 the function should concatenate static str and 
and what was read and  then look for newline character to return 
the line found and cut static str using substr.
*/

char	*gnl_join(char	**pto_static_str, char read_str[BUFFER_SIZE])
{
	char	*ptr;
	int		i;
	int		j;

	ptr = malloc(gnl_strlen(*pto_static_str) + gnl_strlen(read_str) + 1);
	if (!ptr)
		return (clear_leaks(pto_static_str));
	i = 0;
	j = 0;
	if (*pto_static_str)
	{
		while (*(*pto_static_str + i))
		{
			ptr[i++] = *(*pto_static_str + j++);
		}
		free(*pto_static_str);
	}
	j = 0;
	if (read_str)
		while (read_str[j])
			ptr[i++] = read_str[j++];
	ptr[i] = '\0';
	*pto_static_str = ptr;
	return (*pto_static_str);
}

char	*look_for_newline(char	**pto_static_str)
{
	int		iterator_on_str;
	char	*return_str;
	char	*cut_str;

	iterator_on_str = 0;
	while (*(*pto_static_str + iterator_on_str))
	{
		if (*(*pto_static_str + iterator_on_str) == '\n')
		{
			return_str = gnl_substr(*pto_static_str, 0, iterator_on_str + 1);
			if (!return_str)
			{
				free(*pto_static_str);
				return (clear_leaks(&return_str));
			}
			cut_str = gnl_substr(*pto_static_str, iterator_on_str + 1,
					gnl_strlen(*pto_static_str) - iterator_on_str);
			if (!cut_str)
			{
				free(*pto_static_str);
				return (clear_leaks(&cut_str));
			}
			free(*pto_static_str);
			*pto_static_str = cut_str;
			return (return_str);
		}
		iterator_on_str++;
	}
	return_str = gnl_substr(*pto_static_str, 0, iterator_on_str + 1);
	if (!return_str)
	{
		free(*pto_static_str);
		return (clear_leaks(&return_str));
	}
	cut_str = gnl_substr(*pto_static_str, iterator_on_str + 1,
			gnl_strlen(*pto_static_str) - iterator_on_str);
	if (!cut_str)
	{
		free(*pto_static_str);
		return (clear_leaks(&cut_str));
	}
	free(*pto_static_str);
	*pto_static_str = cut_str;
	return (return_str);
}

int	read_file(int fd, char	**pto_static_str)
{
	char	read_str[BUFFER_SIZE + 1];
	int		bytes_read;

	bytes_read = -2;
	while (bytes_read)
	{
		bytes_read = read(fd, read_str, BUFFER_SIZE);
		if (bytes_read == 0)
			return (0);
		if (bytes_read == -1)
		{
			if (*pto_static_str)
				free(*pto_static_str);
			return (-1);
		}
		read_str[bytes_read] = 0;
		if (!gnl_join(pto_static_str, read_str))
			return (-1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*static_str;
	int			read_result;

	read_result = read_file(fd, &static_str);
	if (read_result == -1)
		return (NULL);
	if (!static_str)
		return (NULL);
	if (!gnl_strlen(static_str))
	{
		free(static_str);
		static_str = NULL;
		return (NULL);
	}
	return (look_for_newline(&static_str));
}

int main()
{
	int	f;
	int i = 0;

	f = open("xdd", O_RDONLY);
	while (i < 8)
	{
		printf("LINE %d '%s' \n", i + 1, get_next_line(f));
		i++;
	}
	return (0);
}
