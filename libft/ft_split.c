/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:45:48 by echoukri          #+#    #+#             */
/*   Updated: 2022/10/22 21:00:25 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*malloc : 
-get the size of the whole initial string
-subsctract the number of occurences of the spliting character
-then add the number of null pointers added to the end of each word
-plus the final Null terminator of the resulting pointer to strings

algorithm : 
-look for non c character that marks the start of a word
-start counting till a c character is found which marks the end of a word
-knowing the starting and ending indexes we allocate enough space 
for the new word and add it to the array
-keep going till the end of the initial string
-null terminate the array*/
#include "libft.h"

static int	count(char const *s, char c)
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

static char	*make_word(char const *s, int end, char c)
{
	int		start;
	char	*word;

	start = end;
	while (s[end] && s[end] != c)
		end++;
	word = ft_substr(s, start, end - start + 1);
	word[end - start] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		index;
	char	**ptr;

	i = 0;
	index = 0;
	ptr = malloc((count(s, c) + 1) * sizeof(char *) + 1);
	if (!ptr)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			ptr[index] = make_word(s, i, c);
			i += ft_strlen(ptr[index]);
			index++;
		}
		else
			i++;
	}
	ptr[index] = NULL;
	return (ptr);
}
