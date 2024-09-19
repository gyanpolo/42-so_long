/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 15:20:30 by gpolo             #+#    #+#             */
/*   Updated: 2024/07/08 10:24:48 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_puthexnbr(unsigned long num, int *len)
{
	char	*hex_digits;
	char	hex_representation[20];
	int		i;

	i = 0;
	hex_digits = "0123456789abcdef";
	if (num == 0)
	{
		ft_putchar('0', len);
		return ;
	}
	while (num > 0)
	{
		hex_representation[i++] = (hex_digits[num % 16]);
		num = (num / 16);
	}
	while (i--)
		ft_putchar(hex_representation[i], len);
}

void	ft_puthex(void *str, int *len)
{
	unsigned long	i;

	if (!str)
	{
		ft_putstr("(nil)", len);
		return ;
	}
	i = (unsigned long)str;
	ft_putchar('0', len);
	ft_putchar('x', len);
	ft_puthexnbr(i, len);
}
