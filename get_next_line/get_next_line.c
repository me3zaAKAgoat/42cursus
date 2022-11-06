/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 01:08:56 by echoukri          #+#    #+#             */
/*   Updated: 2022/11/06 20:55:35 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
-have one string that gets stuff concatenated to it and cut from it
-loop after each read until we find
*/

#include "get_next_line.h"

char	*gnl_join(char *static_str, char *read_str, int bytes_left,
				int bytes_read)
{
	char	*ptr;
	int		i;
	int		j;
	int		x=0;
	printf("bytes left: %d, bytes read: %d\n", bytes_left, bytes_read);
	if (!static_str && !read_str)
		return (NULL);
	ptr = malloc(bytes_left + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	if (static_str != NULL)
	{
		while (i < (bytes_left - bytes_read))
		{
			ptr[i] = static_str[i];
			i++;
		}
	}
	free(static_str);
	j = 0;
	if (read_str != NULL)
		while (j < bytes_read)
			ptr[i++] = read_str[j++];
	puts("xddopen");
	while (x<bytes_left)
		printf("%c", ptr[x++]);
	puts("\nxddclose");
	ptr[i] = '\0';
	return (ptr);
}

char	*cut_returned_string(char	**static_str, int *bytes_left,
		int iterator_on_str)
{
	char	*str;

	str = ft_substr(*static_str, 0, iterator_on_str + 1);
	*static_str = ft_substr(*static_str, iterator_on_str + 1,
			*bytes_left - iterator_on_str + 1);
	*bytes_left -= iterator_on_str;
	return (str);
}

char	*get_next_line(int fd)
{
	static int		bytes_left;
	static char		*static_str;
	char			read_str[BUFFER_SIZE];
	int				iterator_on_str;
	int				bytes_read;

	bytes_read = read(fd, read_str, BUFFER_SIZE);
	bytes_left += bytes_read;
	static_str = gnl_join(static_str, read_str, bytes_left, bytes_read);
	iterator_on_str = 0;
	printf("%s\n", static_str);
	while (iterator_on_str < bytes_left)
	{
		printf("%d\n", iterator_on_str);
		if (static_str[iterator_on_str]
			== '\n')
			return (cut_returned_string(&static_str, &bytes_left,
					iterator_on_str));
		iterator_on_str++;
	}
	return (get_next_line(fd));
}

int main()
{
	int	f;
	int i = 0;
	f = open("get_next_line.c", O_RDONLY);

	while (i < 4)
	{
		get_next_line(f);
		i++;
	}
	return (0);
}
