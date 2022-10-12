/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:14:56 by echoukri          #+#    #+#             */
/*   Updated: 2022/10/12 12:35:56 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void    ft_bzero(void *s, size_t n)
{
    unsigned int index;
    char *ptr;

    ptr=(char *)s;
    index = 0;
    while (index<n)
    {
        *(ptr+index)='\0';
        index++;
    }
}

int main()
{
    char *s1 = "lmfao";
    char *s2 = "ahaha";

    ft_bzero(s1, 5);
    bzero(s2, 5);
    int index = 0;
    while (index<5)
    {
        printf("%c\n%c",s1+index, s2+index);
        index++;
    }
    exit(0);
}