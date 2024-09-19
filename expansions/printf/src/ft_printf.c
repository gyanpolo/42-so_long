/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 09:54:17 by gpolo             #+#    #+#             */
/*   Updated: 2024/07/08 10:21:42 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>

int	ft_printf(char const *str, ...)
{
	va_list	va;
	int		len;

	len = 0;
	va_start (va, str);
	ft_putstring_printf((char *)str, va, &len);
	va_end(va);
	return (len);
}
