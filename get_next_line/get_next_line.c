/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 01:08:56 by echoukri          #+#    #+#             */
/*   Updated: 2022/11/08 17:12:23 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*/
#include "get_next_line.h"

char	*leak_protector(char *static_str)
{
	free(static_str);
	return (NULL);
}

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

char	*gnl_cut(char	**pointer_to_ss, int iterator_on_str)
{
	char	*return_str;

	return_str = ft_substr(*pointer_to_ss, 0, iterator_on_str + 1);
	if (!return_str)
		return (leak_protector(*pointer_to_ss));
	*pointer_to_ss = ft_substr(*pointer_to_ss, iterator_on_str + 1,
			gnl_strlen(*pointer_to_ss) - iterator_on_str);
	if (!*pointer_to_ss)
		return (leak_protector(*pointer_to_ss));
	return (return_str);
}


char	*get_next_line(int fd)
{
	static char		*static_str;
	static int		shouldnt_read;
	char			read_str[BUFFER_SIZE];
	int				iterator_on_str;
	int				bytes_read;

	bytes_read = 0;
	if (!shouldnt_read)
		bytes_read = read(fd, read_str, BUFFER_SIZE);
	if (!bytes_read && gnl_strlen(static_str))
		return (static_str);
	if (bytes_read == -1 || gnl_join(&static_str, read_str, bytes_read) == -1
		|| (!bytes_read && !gnl_strlen(static_str)))
		return (leak_protector(static_str));
	iterator_on_str = 0;
	while (*(static_str + iterator_on_str))
	{
		if (*(static_str + iterator_on_str) == '\n')
		{
			shouldnt_read = 1;
			return (gnl_cut(&static_str, iterator_on_str));
		}
		iterator_on_str++;
	}
	shouldnt_read = 0;
	return (get_next_line(fd));
}

// int main()
// {
// 	int	f;
// 	int i = 0;

// 	f = open("get_next_line.c", O_RDONLY);
// 	while (i < 94)
// 	{
// 		printf("LINE %s", get_next_line(f));
// 		i++;
// 	}
// 	return (0);
// }