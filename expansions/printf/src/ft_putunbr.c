/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 19:46:30 by gpolo             #+#    #+#             */
/*   Updated: 2024/07/08 10:32:21 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putunbr(unsigned int nb, int *len)
{
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, len);
	}
	ft_putchar((nb % 10) + '0', len);
}
