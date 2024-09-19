/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putxnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 19:53:39 by gpolo             #+#    #+#             */
/*   Updated: 2024/07/09 16:10:15 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putxnbr(unsigned int num, int *len)
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
