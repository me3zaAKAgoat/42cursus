/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:47:38 by echoukri          #+#    #+#             */
/*   Updated: 2022/10/22 21:36:25 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*srcp;
	unsigned char		*dstp;
	unsigned char		*tempp;
	unsigned int		index;

	srcp = (const unsigned char *)src;
	dstp = (unsigned char *)dst;
	tempp = malloc(sizeof(unsigned char) * len);
	if (tempp == NULL)
		return (NULL);
	else
	{
		index = 0;
		while (index < len)
		{
			*(tempp + index) = *(srcp + index);
			index++;
		}
		printf("how many allocated :%d\nlen: %zu\n", index, len);
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

// #include "libft.h"

// void	*ft_memmove(void *dst, const void *src, size_t len)
// {
// 	unsigned char		*tempp;
// 	unsigned int		index;

// 	tempp = malloc(sizeof(unsigned char) * len);
// 	if (tempp == NULL)
// 		return (NULL);
// 	else
// 	{
// 		index = 0;
// 		while (index < len)
// 		{
// 			*(tempp + index) = *((const unsigned char *)src + index);
// 			index++;
// 		}
// 		index = 0;
// 		while (index < len)
// 		{
// 			*((unsigned char *)dst + index) = *((unsigned char *)dst + index);
// 			index++;
// 		}
// 		free(tempp);
// 	}
// 	return (dst);
// }

int main()
{
	char src[60] = "vayneisbetterthanjhin";
	char *dst = src +17;
	int index = 0;

	ft_memmove(dst, src, ft_strlen(src));
	while (index < 30)
	{
		printf("%c", dst[index]);
		index++;
	}
	puts("\n");
	return 0;
}
