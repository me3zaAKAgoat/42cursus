/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:24:56 by echoukri          #+#    #+#             */
/*   Updated: 2022/10/18 16:32:10 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	index;
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	index = 0;
	while (index < len)
	{
		*(ptr + index) = (unsigned char)c;
		index++;
	}
	return (ptr);
}

// int main()
// {
//     char ptrtostr1[6];
//     char ptrtostr2[6];

//     ptrtostr1[5]='\0';
//     ptrtostr2[5]='\0';

//     printf("memset: %s\n", memset(ptrtostr1, 'a', 5));

//     printf("ft_memset: %s\n", ft_memset(ptrtostr2, 'a', 5));

//     exit(0);
// }