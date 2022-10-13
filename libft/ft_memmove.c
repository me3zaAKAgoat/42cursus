/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:47:38 by echoukri          #+#    #+#             */
/*   Updated: 2022/10/12 18:26:54 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdlib.h>
// #include <stdio.h>
// #include <string.h>

void *ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char *srcp;
	unsigned char *dstp;
	unsigned char *tempp;
	unsigned int index;

	srcp = (const unsigned char *)src;
	dstp = (unsigned char *)dst;
	tempp = (unsigned char *)malloc(sizeof(unsigned char) * len);
	if (tempp == NULL)
		return NULL;
	else
	{
		index = 0;
		while (index < len)
		{
			*(tempp + index) = *(srcp + index);
			index++;
		}
		index = 0;
		while (index < len)
		{
			*(dstp + index) = *(tempp + index);
			index++;
		}
		free(tempp);
	}
	return (dstp);
}

// int main()
// {
//     char src[] = "lmfao";
//     char dst[5];

// 	dst[4]='\0';
//     printf("\n%s\n%s", dst, src);
// 	printf("\n%s", ft_memmove(dst, src, 4));
//     exit(0);
// }