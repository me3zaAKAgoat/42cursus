/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:48:13 by echoukri          #+#    #+#             */
/*   Updated: 2023/01/17 15:48:27 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	here_doc(char *eof)
{
	int		fd;
	char	*buf;

	fd = open(".tmp.txt", O_TRUNC | O_CREAT | O_RDWR, 0000644);
	while (1)
	{
		write(1, "heredoc>", ft_strlen("heredoc>"));
		buf = get_next_line(0);
		if (ft_strnstr(buf, eof, ft_strlen(eof)) > 0)
			return ;
		write(fd, buf, ft_strlen(buf));
	}
}
