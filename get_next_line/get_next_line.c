/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:30:23 by echoukri          #+#    #+#             */
/*   Updated: 2022/11/16 19:05:57 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* concatenates static and last read if one dosen't exist 
it isn't acccounted for in the concatenation */
static char	*gnl_join(char	*static_str, char *read_str)
{
	char	*ptr;
	int		i;
	int		j;

	ptr = malloc(gnl_strlen(static_str) + gnl_strlen(read_str) + 1);
	if (!ptr)
		return (NULL);
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

/* look for newline in the last read string/ return 0 if not found 
return index if newline if found */
int	look_for_newline(char	*str)
{
	int	index;

	if (!str)
		return (-1);
	index = 0;
	while (str[index])
	{
		if (str[index] == '\n')
			return (index);
		index++;
	}
	return (-1);
}

/* moves to the newline then makes a cut and returns the first part 
and saves the second part in the static str
if no newline is found a cut is made to return the whole string
and render static as empty string*/
static char	*cut_and_return(char **pto_static_str)
{
	int		index;
	char	*tmp_str;
	char	*return_str;

	index = 0;
	while (*(*pto_static_str + index))
	{
		if (*(*pto_static_str + index) == '\n')
			break ;
		index++;
	}
	return_str = gnl_substr(*pto_static_str, 0, index + 1);
	tmp_str = gnl_substr(*pto_static_str, index + 1,
			gnl_strlen(*pto_static_str) - index);
	if (!tmp_str || !return_str)
		return (free(return_str), free(tmp_str),
			free(*pto_static_str), NULL);
	return (free(*pto_static_str), *pto_static_str = tmp_str, return_str);
}

/*
-loop, read and concatente into static until a new line character 
is found in the most recent read portion
-inside the loop return the whole static if read returned 0
-inside the loop return NULL if read returned 0 and simultaneously 
static str length is 0
or static str dosent exist
-if a newline character is found exit the loop and cede control to
cut and return */
char	*get_next_line(int fd)
{
	static char	*static_str;
	char		*read_str;
	int			bytes_read;

	read_str = malloc(BUFFER_SIZE + 1);
	if (!read_str)
		return (free(static_str), free(read_str), NULL);
	while (look_for_newline(static_str) == -1)
	{
		bytes_read = read(fd, read_str, BUFFER_SIZE);
		if (bytes_read == 0 && gnl_strlen(static_str))
			break ;
		if (bytes_read == 0 && !gnl_strlen(static_str))
			return (free(read_str), free(static_str), static_str = NULL, NULL);
		if (bytes_read == -1)
			return (free(read_str), NULL);
		read_str[bytes_read] = 0;
		static_str = gnl_join(static_str, read_str);
		if (!static_str)
			return (free(static_str), free(read_str), NULL);
	}
	return (free(read_str), cut_and_return(&static_str));
}

// # include <fcntl.h>
// int main()
// {
// 	int	fd;
// 	int i = 0;

// 	fd = open("xdd", O_RDONLY);
// 	while (i < 8)
// 	{
// 		printf("LINE %d '%s' \n", i + 1, get_next_line(fd));
// 		i++;
// 	}
// 	return (0);
// }
