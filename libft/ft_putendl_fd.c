/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:49:07 by echoukri          #+#    #+#             */
/*   Updated: 2022/10/17 18:04:42 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putendl_fd(char *s, int fd)
{
    int slen = ft_strlen(s);
    char buf[slen+1];

    ft_strlcpy(buf, s, slen+1);
    buf[slen] = '\n';
    write(fd, buf, slen+1);
    return ;
}

// int main()
// {
//     ft_putendl_fd("lmfao",1);
//     return 0;
// }