/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 01:08:56 by echoukri          #+#    #+#             */
/*   Updated: 2022/11/06 05:35:11 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
-have one string that gets stuff concatenated to it and cut from it
-loop after each read until we find
*/

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (s2);
	else if (!s2)
		return (s1);
	ptr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j])
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	return (ptr);
}

char	*cut_returned_string(char	**static_str, int *bytes_left,
		int iterator_on_str)
{
	char	*str;

	str = ft_substr(*static_str, 0, iterator_on_str + 1);
	*static_str = ft_substr(*static_str, iterator_on_str + 1,
			*bytes_left - iterator_on_str - 1);
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
	if (!bytes_read)
		return ("");
	bytes_left += bytes_read;
	static_str = ft_strjoin(static_str, read_str);
	iterator_on_str = 0;
	while (iterator_on_str < bytes_left)
	{
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

	f = open("get_next_line.c", O_RDONLY);
	printf("line 1:%s", get_next_line(f));
	printf("line 2:%s", get_next_line(f));
	printf("line 3:%s", get_next_line(f));
	printf("line 4:%s", get_next_line(f));
	printf("line 5:%s", get_next_line(f));
	printf("line 6:%s", get_next_line(f));
	printf("line 7:%s", get_next_line(f));
	printf("line 8:%s", get_next_line(f));
	printf("line 9:%s", get_next_line(f));
	printf("line 10:%s", get_next_line(f));
	return (0);
}
