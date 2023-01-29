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
# include <fcntl.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>

# define EXEC_FAILURE 126
# define CMD_NOTFOUND 127
# define ARGC_PIPE_OFFSET 4
# define MINIMUM_ARGC 5
# define MINIMUM_ARGC_HEREDOC 6

extern size_t	ft_strlen(const char *s);
extern char		**ft_split(char const *s, char c);
extern char		*ft_substr(char const *s, unsigned int start, size_t len);
extern char		**get_pathenv(char	*envp[]);
extern char		*ft_strnstr(const char *haystack,
					const char *needle, size_t len);
extern char		*ft_strjoin(char const *s1, char const *s2);
extern void		*split_clear(char	**arr);
extern char		*get_cmdpath(char	**paths, char	*cmd);
extern void		*ft_memcpy(void *dst, const void *src, size_t n);
extern char		*get_next_line(int fd);

/*
if heredoc_offset > 0 the program
shall work as if the infile is a heredoc
*/
typedef struct pobj
{
	int		*pipes;
	char	**program_paths;
	int		ac;
	char	**argv;
	char	**envp;
	char	heredoc_offset;	
}	t_pipex_obj;

extern void		here_doc(char *eof);
extern void		setup_heredoc(t_pipex_obj *pipex_data, char **argv, int ac);
extern void		perr_exit(char *msg);
extern int		open_in(t_pipex_obj *pipex_data);
extern int		open_out(t_pipex_obj *pipex_data);
extern void		first_child_core(t_pipex_obj *pipex_data,
					char *cmd, int infile_d);
extern void		middle_child_core(t_pipex_obj *pipex_data,
					char *cmd, int arr_cursor);
extern void		last_child_core(t_pipex_obj *pipex_data, char *cmd,
					int arr_cursor, int outfile_d);
extern void		free_struct(t_pipex_obj	*pipex_data);

#endif