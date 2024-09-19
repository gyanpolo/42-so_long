/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstring_printf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 10:45:06 by gpolo             #+#    #+#             */
/*   Updated: 2024/07/16 13:45:08 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_identfication(char id, va_list va, int *len)
{
	if (id == 'c')
		ft_putchar(va_arg(va, int), len);
	if (id == 's')
		ft_putstr(va_arg(va, char *), len);
	if (id == 'p')
		ft_puthex(va_arg(va, void *), len);
	if (id == 'd')
		ft_putnbr(va_arg(va, int), len);
	if (id == 'i')
		ft_putnbr(va_arg(va, int), len);
	if (id == 'u')
		ft_putunbr(va_arg(va, unsigned int), len);
	if (id == 'x')
		ft_putxnbr(va_arg(va, unsigned int), len);
	if (id == 'X')
		ft_putxxnbr(va_arg(va, unsigned int), len);
	if (id == '%')
		ft_putchar('%', len);
}

void	ft_putstring_printf(char *str, va_list va, int *len)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_identfication(str[i], va, len);
		}
		else
		{
			ft_putchar(str[i], len);
		}
		i++;
	}
}
