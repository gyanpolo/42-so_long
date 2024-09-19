/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 19:04:23 by gpolo             #+#    #+#             */
/*   Updated: 2024/07/08 10:25:30 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr(int nb, int *len)
{
	if (nb == -2147483648)
	{
		ft_putchar('-', len);
		ft_putchar('2', len);
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_putchar('-', len);
		nb *= -1;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, len);
	}
	ft_putchar((nb % 10) + '0', len);
}
