/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 11:59:11 by gpolo             #+#    #+#             */
/*   Updated: 2024/07/06 16:34:44 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putstr(char *str, int *len)
{
	int	c;

	if (!str)
	{
		ft_putstr("(null)", len);
		return ;
	}
	c = 0;
	while (str[c] != '\0')
	{
		ft_putchar(str[c], len);
		c++;
	}
}
