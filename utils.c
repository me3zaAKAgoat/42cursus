/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:40:49 by echoukri          #+#    #+#             */
/*   Updated: 2023/02/27 13:46:31 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <string.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	int		index;
	char	ci;

	ci = (char)c;
	index = 0;
	if (s[index] == ci)
		return ((char *)(s) + index);
	while (s[index])
	{
		if (s[index + 1] == ci)
			return ((char *)(s) + index + 1);
		index++;
	}
	return (NULL);
}

void	perr_exit(char *msg)
{
	perror(msg);
	exit(1);
}

int	count_words(char const *s, char c)
{
	int	count_of_c;
	int	index;

	count_of_c = 1;
	index = 0;
	while (s[index])
	{	
		if (s[index] != c)
		{
			while (s[index] != c && s[index])
				index++;
			count_of_c++;
		}
		else
			index++;
	}
	return (count_of_c);
}

char *ft_dtoa(double num, int precision) {
    char *str = malloc(50 * sizeof(char));
    if (num < 0) {
        num = -num;
        strcpy(str, "-");
    } else {
        strcpy(str, "");
    }
    int whole = (int) num;
    double fraction = num - whole;
    int i = ft_strlen(str);
    if (whole == 0) {
        str[i++] = '0';
    } else {
        while (whole > 0) {
            str[i++] = (whole % 10) + '0';
            whole /= 10;
        }
    }
    str[i++] = '.';
    while (precision-- > 0) {
        fraction *= 10;
        int digit = (int) fraction;
        str[i++] = digit + '0';
        fraction -= digit;
    }
    str[i] = '\0';
    return str;
}