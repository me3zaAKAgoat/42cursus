/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:12:11 by echoukri          #+#    #+#             */
/*   Updated: 2022/10/14 11:12:11 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

extern size_t	ft_strlen(const char *s);
extern char		**ft_split(char const *s, char c);
extern char		*ft_substr(char const *s, unsigned int start, size_t len);
extern char		**get_paths(char	*envp[]);
extern char		*ft_strnstr(const char *haystack,
					const char *needle, size_t len);
extern char		*ft_strjoin(char const *s1, char const *s2);
extern void		*split_clear(char	**arr);
extern char		*get_cmd(char	**paths, char	*cmd);
extern void		*ft_memcpy(void *dst, const void *src, size_t n);


typedef struct pobj
{
	int		*pipes;
	char	**program_paths;
	int		ac;
}	t_pipex_obj;

extern void		cleanup_all(t_pipex_obj	*pipex_data, int pipe_count);

#endif