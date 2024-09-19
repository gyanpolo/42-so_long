/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:04:27 by gpolo             #+#    #+#             */
/*   Updated: 2024/09/06 16:28:00 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fences(t_mlx_data *data, char **map, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, \
		data->win_ptr, data->fence.img_1.img_ptr, x * 64, y * 64);
	if (map[y][x - 1] == 1 + '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
			data->fence.img_2.img_ptr, (x - 1) * 64 + 54, y * 64 + 21);
	if ((y != 0) && (map[y - 1][x] == 1 + '0'))
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
			data->fence.img_3.img_ptr, x * 64 + 20, (y - 1) * 64 + 34);
}

void	grasp(t_mlx_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->grass.img_1.img_ptr, x * 64, y * 64);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->grass.img_2.img_ptr, x * 64 + 10, y * 64 + 20);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->grass.img_3.img_ptr, x * 64 + 40, y * 64 + 8);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->grass.img_3.img_ptr, x * 64 + 15, y * 64 + 40);
}

void	objectives(t_mlx_data *data, int x, int y)
{
	grasp(data, x, y);
	data->points++;
	if ((x + y) % 2 == 0)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
			data->objectives.img_1.img_ptr, x * 64 + 12, y * 64 + 8);
	else if ((x + y) % 3 == 0)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
			data->objectives.img_2.img_ptr, x * 64 + 12, y * 64 + 8);
	else
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
			data->objectives.img_3.img_ptr, x * 64 + 12, y * 64 + 8);
}

void	chek(t_mlx_data *data, char **map, int x, int y)
{
	if (map[y][x] == 1 + '0')
		fences(data, map, x, y);
	else if (map[y][x] == 0 + '0')
		grasp(data, x, y);
	else if (map[y][x] == 'C')
		objectives(data, x, y);
	else if (map[y][x] == 'E')
		portal(data, x, y);
	else if (map[y][x] == 'P')
		caw(data, x, y);
	else if (map[y][x] == '2')
		farmer(data, x, y);
}

void	fill_map(t_mlx_data *data, char **map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			chek(data, map, x, y);
			x++;
		}
		y++;
		x = 0;
	}
}
