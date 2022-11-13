/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:30:23 by echoukri          #+#    #+#             */
/*   Updated: 2022/11/13 17:48:28 by echoukri         ###   ########.fr       */
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

char	*gnl_join(char	*static_str, char *read_str)
{
	char	*ptr;
	int		i;
	int		j;

	ptr = malloc(gnl_strlen(static_str) + gnl_strlen(read_str) + 1);
	if (!ptr)
		return (free(static_str), NULL);
	i = 0;
	j = 0;
	if (static_str)
	{
		while (*(static_str + i))
		{
			ptr[i++] = *(static_str + j++);
		}
		free(static_str);
	}
	j = 0;
	if (read_str)
		while (read_str[j])
			ptr[i++] = read_str[j++];
	ptr[i] = '\0';
	return (ptr);
}

// look for newline in the last read string/ return 0 if not found / return index if newline if found
int	look_for_newline(char	*str)
{
	int	index;
	
	if (!str)
		return (0);
	index = 0;
	while (str[index])
	{
		if (str[index] == '\n')
			return (index);
		index++;
	}
	return (0);
}

char	*cut_and_return(char **pto_static_str)
{
	int	index;
	char	*return_str;
	char	*tmp_str;

	index = 0;
	while (*(*pto_static_str + index))
	{
		if (*(*pto_static_str + index) == '\n')
		{
			return_str = gnl_substr(*pto_static_str, 0, index + 1);
			if (!return_str)
				return (free(*pto_static_str), NULL);
			tmp_str =  gnl_substr(*pto_static_str, index + 1, gnl_strlen(*pto_static_str) - index);
			if (!tmp_str)
				return (free(return_str), free(*pto_static_str), NULL);
			return (free(*pto_static_str), *pto_static_str = tmp_str, return_str);
		}
		index++;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*static_str;
	char		*read_str;
	int			bytes_read;

	read_str = malloc(BUFFER_SIZE + 1);
	while (look_for_newline(static_str) == 0)
	{
		bytes_read = read(fd, read_str, BUFFER_SIZE);
		read_str[bytes_read] = 0;
		// printf("%d\n", bytes_read);
		if (bytes_read == 0 && gnl_strlen(static_str))
			break;
		else if (bytes_read == 0)
		{
			if (!static_str)
				return (free(read_str), NULL);
			else if (!gnl_strlen(static_str))
				return (free(read_str), free(static_str), static_str = NULL, NULL);
		}
		static_str = gnl_join(static_str, read_str);
	}
	return (free(read_str), cut_and_return(&static_str));
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
