/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:55:13 by gpolo             #+#    #+#             */
/*   Updated: 2024/09/12 15:59:27 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_memset(void *s, int c, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

void	*ft_calloc(int num, int size)
{
	void	*array;
	int		total_size;

	total_size = num * size;
	array = malloc(total_size);
	if (array == NULL)
		return (NULL);
	ft_memset(array, 0, total_size);
	return (array);
}

char	ft_leng(int n)
{
	int		leng;

	leng = 0;
	if (n == -2147483648)
	{
		leng += 2;
		n = 147483648;
	}
	if (n < 0)
	{
		leng++;
		n *= -1;
	}
	while (n >= 10)
	{
		leng++;
		n /= 10;
	}
	leng++;
	return (leng);
}

int	copm(char *itoa, int n)
{
	if (n == -2147483648)
	{
		itoa[0] = ('-');
		itoa[1] = ('2');
		n = 147483648;
	}
	if (n < 0)
	{
		itoa[0] = ('-');
		n *= -1;
	}
	return (n);
}

char	*ft_itoa(int n)
{
	char	*itoa;
	int		c;

	c = (ft_leng(n));
	itoa = (char *)ft_calloc((c + 1), sizeof(char));
	if (!itoa)
		return (0);
	n = copm(itoa, n);
	c--;
	while (n >= 10)
	{
		itoa[c--] = n % 10 + '0';
		n /= 10;
	}
	if (n >= 0)
		itoa[c] = n + '0';
	return (itoa);
}
