/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 01:08:56 by echoukri          #+#    #+#             */
/*   Updated: 2022/11/07 19:42:14 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
the idea of get next line is to keep have an elongated string that gets returned lines cut off from it 
and keeps newly read input as a suffix that will be cut off in the next iterations if a new line is found
*/
#include "get_next_line.h"

int	gnl_join(char **pointer_to_ss, char *read_str, int bytes_read)
{
	char	*ptr;
	int		i;
	int		j;

	ptr = malloc(gnl_strlen(*pointer_to_ss) + bytes_read + 1);
	if (!ptr)
		return (-1);
	i = 0;
	if ((*pointer_to_ss))
	{
		while (*(*pointer_to_ss + i))
		{
			ptr[i] = *(*pointer_to_ss + i);
			i++;
		}
		free(*pointer_to_ss);
	}
	j = 0;
	if (read_str)
		while (j < bytes_read)
			ptr[i++] = read_str[j++];
	ptr[i] = '\0';
	*pointer_to_ss = ptr;
	return (0);
}

char	*gnl_cut(char	**static_str, int iterator_on_str, int *bytes_left)
{
	char	*return_str;

	return_str = ft_substr(*static_str, 0, iterator_on_str + 1);
	*static_str = ft_substr(*static_str, iterator_on_str + 1,
			gnl_strlen(*static_str) - iterator_on_str);
	*bytes_left -= iterator_on_str;
	return (return_str);
}

char	*get_next_line(int fd)
{
	static char		*static_str;
	static int		bytes_left;
	char			read_str[BUFFER_SIZE];
	int				iterator_on_str;
	int				bytes_read;

	bytes_read = read(fd, read_str, BUFFER_SIZE);
	bytes_left += bytes_read;
	if ((!bytes_read && !bytes_left) || bytes_read == -1)
		return (NULL);
	if (gnl_join(&static_str, read_str, bytes_read) == -1)
		return ("failed xdd");
	iterator_on_str = 0;
	while (*(static_str + iterator_on_str))
	{
		if (*(static_str + iterator_on_str) == '\n')
		{
			return (gnl_cut(&static_str, iterator_on_str, &bytes_left));
		}
		iterator_on_str++;
	}
	return (get_next_line(fd));
}

// int main()
// {
// 	int	f;
// 	int i = 0;

// 	f = open("xd", O_RDONLY);
// 	while (i < 94)
// 	{
// 		printf("LINE %s", get_next_line(f));
// 		i++;
// 	}
// 	return (0);
// }
