/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 12:15:24 by gpolo             #+#    #+#             */
/*   Updated: 2024/07/16 13:45:48 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>

int		ft_printf(char const *str, ...);
void	ft_putchar(int c, int *len);
void	ft_putstr(char *str, int *len);
void	ft_puthex(void *str, int *len);
void	ft_putstring_printf(char *str, va_list va, int *len);
void	ft_putnbr(int nb, int *len);
void	ft_putunbr(unsigned int nb, int *len);
void	ft_putxnbr(unsigned int num, int *len);
void	ft_putxxnbr(unsigned int num, int *len);

#endif
