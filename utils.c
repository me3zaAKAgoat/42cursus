/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:40:49 by echoukri          #+#    #+#             */
/*   Updated: 2023/01/29 18:26:19 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
