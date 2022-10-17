/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:45:48 by echoukri          #+#    #+#             */
/*   Updated: 2022/10/17 17:16:36 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdlib.h>
// #include <stdio.h>

int	count(char const *s, char c)
{
	int	count_of_c;
	int	index;

	count_of_c = 0;
	index = 0;
	while (s[index])
	{
		if (s[index] == c)
			count_of_c += 1;
		index++;
	}
	return (count_of_c);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	int		index;
	char	**ptr;
	char	*word;

	index = 0;
	i = 0;
	//get the size of the whole initial string
	//subsctract the number of occurences of the spliting character
	//then add the number of null pointers added to the end of each word
	//plus the final Null terminator of the resulting pointer to strings
	ptr = malloc((count(s, c) + 1) * sizeof(char *) + 1);
	if (!ptr)
		return (NULL);
	//look for non c character that marks the start of a word
	//start counting till a c character is found which marks the end of a word
	//knowing the starting and ending indexes we allocate enough space for the new word and add it to the array
	//keep going till the end of the initial string
	//null terminate the array
	while (s[i])
	{
		if (s[i] != c)
		{
			j = i;
			k = i;
			while (s[j] && s[j] != c)
				j++;
			word = malloc((j - k) * sizeof(char) + 1);
			ft_strlcpy(word, (s + k), (j - k) + 1);
			ptr[index] = word;
			index++;
			i = j;
		}
		else
			i++;
	}
	ptr[index] = NULL;
	return (ptr);
}

// int main()
// {
//     int index;
//     char **ptr;
//     char *s = "wow this test example is so cool :DD";
//     ptr = ft_split(s, ' ');
//     index = 0;
//     while (ptr[index]!=NULL)
//     {
//         printf("%p %s\n", &ptr[index],ptr[index]);
//         index++;
//     }
//     exit(0);
// }