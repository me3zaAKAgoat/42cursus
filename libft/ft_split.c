/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:45:48 by echoukri          #+#    #+#             */
/*   Updated: 2022/10/19 19:38:10 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
char	**ft_split(char const *s, char c)
{
	int		iterators[3] = {0};
	int		index;
	char	**ptr;
	char	*word;

	index = 0;
	ptr = malloc((count(s, c) + 1) * sizeof(char *) + 1);
	if (!ptr)
		return (NULL);
	while (s[iterators[0]])
	{
		if (s[iterators[0]] != c)
		{
			iterators[1] = iterators[0];
			iterators[2] = iterators[0];
			while (s[iterators[1]] && s[iterators[1]] != c)
				iterators[1]++;
			word = malloc((iterators[1] - iterators[2]) * sizeof(char) + 1);
			ft_strlcpy(word, (s + iterators[2]),
			(iterators[1] - iterators[2]) + 1);
			ptr[index] = word;
			index++;
			iterators[0] = iterators[1];
		}
		else
			iterators[0]++;
	}
	ptr[index] = NULL;
	return (ptr);
}
