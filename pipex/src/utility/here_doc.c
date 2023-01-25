/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:48:13 by echoukri          #+#    #+#             */
/*   Updated: 2023/01/25 17:52:59 by echoukri         ###   ########.fr       */
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
		if (ft_strlen(ft_strnstr(buf, eof, ft_strlen(eof))) > 0)
		{
			free(buf);
			return ;
		}
		write(fd, buf, ft_strlen(buf));
		free(buf);
	}
}

void	setup_heredoc(t_pipex_obj *pipex_data, char **argv)
{
	if (ft_strlen(ft_strnstr(argv[1], "here_doc", ft_strlen("here_doc"))) > 0)
	{
		pipex_data->heredoc_offset = 1;
		here_doc(argv[2]);
	}
	else
		pipex_data->heredoc_offset = 0;
}
