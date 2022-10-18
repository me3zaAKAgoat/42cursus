/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:39:25 by echoukri          #+#    #+#             */
/*   Updated: 2022/10/18 16:16:34 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	ft_putnbr(int nb, int pos, char *ptr)
{
	char	*str;

	str = "0123456789";
	if (nb == -2147483648)
	{
		ft_putnbr(nb / 10, pos - 1, ptr);
		ft_putnbr(-(nb % 10), pos, ptr);
	}
	if (0 <= nb && nb < 10)
		ptr[pos - 1] = nb + '0';
	else if (nb >= 10)
	{
		ft_putnbr(nb / 10, pos - 1, ptr);
		ft_putnbr(nb % 10, pos, ptr);
	}
	else if (nb < 0)
	{
		ptr[0] = '-';
		ft_putnbr(-nb, pos + 1, ptr);
	}
}

char	*ft_itoa(int n)
{
	int		n2;
	int		n_digits;
	char	*ptr;

	n_digits = 0;
	n2 = n;
	ptr = NULL;
	while (n2 != 0)
	{
		n2 = n2 / 10;
		n_digits += 1;
	}
	if (n < 0)
	{
		ptr = malloc((n_digits + 2) * sizeof(char));
		ft_putnbr(n, n_digits, ptr);
		ptr[n_digits + 1] = '\0';
	}
	else
	{
		ptr = malloc((n_digits + 1) * sizeof(char));
		ft_putnbr(n, n_digits, ptr);
		ptr[n_digits] = '\0';
	}
	return (ptr);
}

// int main()
// {
//     printf("%s\n", ft_itoa(-4321));
//     exit(0);
// }