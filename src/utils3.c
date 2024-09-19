/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:21:02 by gpolo             #+#    #+#             */
/*   Updated: 2024/09/17 12:58:12 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	putbakgraud(t_mlx_data *data)
{
	int	y;
	int	x;
	int	i;

	x = data->win_x;
	y = data->win_y;
	i = 0;
	while (i < x)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
			data->grass.img_1.img_ptr, i * 64, y * 64);
		i++;
	}
}

void	map_pos(t_mlx_data *data, int x, int y)
{
	open_win(data, x * 64, (y + 1) * 64);
	open_all(data);
	fill_map(data, data->map);
}

int	chek_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			if (i == 0)
				return (0);
			if (str[i + 1] == '\n')
				return (0);
			else if (str[i + 1] == '\0')
				return (1);
		}
		i++;
	}
	return (1);
}

int	is_ber(char *str)
{
	int		i;
	int		j;
	char	*ber;

	ber = ".ber";
	j = 0;
	i = 0;
	while (str[i] != '\n')
	{
		if (str[i] == '.')
		{
			while (str[i + j] == ber[j])
			{
				if (j == 3)
					return (1);
				j++;
			}
			return (0);
		}
		j = 0;
		i++;
	}
	return (0);
}
