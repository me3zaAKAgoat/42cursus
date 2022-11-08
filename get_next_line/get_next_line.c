/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:30:23 by echoukri          #+#    #+#             */
/*   Updated: 2022/11/08 21:17:28 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
-2 means no reads were done **intentionally**
*/
int	gnl_join(char	**ptr_to_staticS, char read_str[BUFFER_SIZE],
			int bytes_read)
{
	char	*ptr;
	int		i;
	int		j;

	ptr = malloc(gnl_strlen(*ptr_to_staticS) + bytes_read + 1);
	if (!ptr)
		return (-1);
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
	return (0);
}

char	*look_for_newline(int fd, char	**ptr_to_staticS, int *ptr_to_nread)
{
	int		iterator_on_str;
	char	*return_str;

	iterator_on_str = 0;
	while (*(*ptr_to_staticS + iterator_on_str))
	{
		if (*(*ptr_to_staticS + iterator_on_str) == '\n')
		{
			return_str = ft_substr(*ptr_to_staticS, 0, iterator_on_str + 1);
			*ptr_to_staticS = ft_substr(*ptr_to_staticS, iterator_on_str + 1,
					gnl_strlen(*ptr_to_staticS) - iterator_on_str);
			if (!*ptr_to_staticS || !return_str)
			{
				free(*ptr_to_staticS);
				return (NULL);
			}
			return (return_str);
		}
		iterator_on_str++;
	}
	*ptr_to_nread = 0;
	return (get_next_line(fd));
}

int	read_file(int fd, char ptr_to_readS[BUFFER_SIZE], int *ptr_to_nread)
{
	int			read_status;

	read_status = 0;
	if (!*ptr_to_nread)
		read_status = read(fd, ptr_to_readS, BUFFER_SIZE);
	return (read_status);
}

char	*flush_last_line(char	**ptr_to_staticS)
{
	char		*last_str;
	int			i;

	last_str = malloc(gnl_strlen(*ptr_to_staticS) + 1);
	if (!last_str)
		return (NULL);
	i = 0;
	while (*(*ptr_to_staticS + i))
	{
		last_str[i] = *(*ptr_to_staticS + i);
		i++;
	}
	last_str[i] = '\0';
	free(*ptr_to_staticS);
	*ptr_to_staticS = NULL;
	return (last_str);
}

char	*get_next_line(int fd)
{
	static char	*static_str;
	static int	shouldnt_read;
	char		read_str[BUFFER_SIZE];
	int			bytes_read;

	bytes_read = read_file(fd, read_str, &shouldnt_read);
	if (bytes_read == -1)
		return (NULL);
	if (!bytes_read && !shouldnt_read && !gnl_strlen(static_str))
		return (NULL);
	if (!bytes_read && !shouldnt_read && gnl_strlen(static_str))
		return (flush_last_line(&static_str));
	if (!shouldnt_read)
		if (gnl_join(&static_str, read_str, bytes_read) == -1)
			return (NULL);
	shouldnt_read = 1;
	return (look_for_newline(fd, &static_str, &shouldnt_read));
}

// int main()
// {
// 	int	f;
// 	int i = 0;

// 	f = open("xdd.c", O_RDONLY);
// 	while (i < 119)
// 	{
// 		printf("LINE %d %s", i + 1, get_next_line(f));
// 		i++;
// 	}
// 	return (0);
// }
