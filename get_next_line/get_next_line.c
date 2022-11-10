/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:30:23 by echoukri          #+#    #+#             */
/*   Updated: 2022/11/10 21:09:25 by echoukri         ###   ########.fr       */
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

char	*gnl_join(char	**ptr_to_staticS, char read_str[BUFFER_SIZE],
			int bytes_read)
{
	char	*ptr;
	int		i;
	int		j;

	if (!*ptr_to_staticS && !bytes_read)
		return (NULL);
	ptr = malloc(gnl_strlen(*ptr_to_staticS) + bytes_read + 1);
	if (!ptr)
		return (clear_leaks(ptr_to_staticS));
	i = 0;
	j = 0;
	if (*ptr_to_staticS)
	{
		while (*(*ptr_to_staticS + i))
		{
			ptr[i++] = *(*ptr_to_staticS + j++);
		}
		free(*ptr_to_staticS);
	}
	j = 0;
	if (bytes_read)
		while (j < bytes_read)
			ptr[i++] = read_str[j++];
	ptr[i] = '\0';
	*ptr_to_staticS = ptr;
	return (*ptr_to_staticS);
}

char	*look_for_newline(char	**ptr_to_staticS, int	*ptr_to_eof)
{
	int		iterator_on_str;
	char	*return_str;

	iterator_on_str = 0;
	// printf("static str after joins '%c'", **ptr_to_staticS);
	while (*(*ptr_to_staticS + iterator_on_str))
	{
		if (*(*ptr_to_staticS + iterator_on_str) == '\n')
		{
			return_str = ft_substr(*ptr_to_staticS, 0, iterator_on_str + 1);
			*ptr_to_staticS = ft_substr(*ptr_to_staticS, iterator_on_str + 1,
					gnl_strlen(*ptr_to_staticS) - iterator_on_str);
			if (!*ptr_to_staticS || !return_str)
				return (clear_leaks(ptr_to_staticS));
			return (return_str);
		}
		iterator_on_str++;
	}
	*ptr_to_eof = 1;
	return (*ptr_to_staticS);
}

int	read_file(int fd, char	**ptr_to_staticS)
{
	char	read_str[BUFFER_SIZE];
	int		bytes_read;

	bytes_read = -2;
	while (bytes_read)
	{
		bytes_read = read(fd, read_str, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(*ptr_to_staticS);
			return (-1);
		}
		if (!gnl_join(ptr_to_staticS, read_str, bytes_read))
			return (-1);
	}
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char	*static_str;
	static int	eof;
	int			read_result;

	if (eof)
	{
		free(static_str);
		static_str = NULL;
		return (NULL);
	}
	read_result = read_file(fd, &static_str);
	if (read_result == -1)
		return (NULL);
	return (look_for_newline(&static_str, &eof));
}

// int main()
// {
// 	int	f;
// 	int i = 0;

// 	f = open("xdd.c", O_RDONLY);
// 	while (i < 3)
// 	{
// 		printf("LINE %d %s", i + 1, get_next_line(f));
// 		i++;
// 	}
// 	return (0);
// }
