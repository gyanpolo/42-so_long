/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:20:22 by gpolo             #+#    #+#             */
/*   Updated: 2024/09/12 16:02:28 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_steps(t_mlx_data *data)
{
	int		x;
	int		y;
	char	*str;

	putbakgraud(data);
	str = ft_itoa(data->steps);
	x = 32;
	y = (data->win_y) * 64 + 32;
	mlx_string_put(data->mlx_ptr, data->win_ptr, x, y, 0x000000, "STEPS :");
	mlx_string_put(data->mlx_ptr, data->win_ptr, x + 64, y, 0x000000, str);
	free(str);
}

void	step_left(t_mlx_data *data, int x, int y)
{
	data->direction = 1;
	data->steps++;
	data->map[y][x] = '0';
	data->map[y][x - 1] = 'P';
	grasp(data, x, y);
	caw(data, x - 1, y);
	put_steps(data);
}

void	move_left_caw(t_mlx_data *data)
{
	int	x;
	int	y;

	x = data->caw.imgp_x;
	y = data->caw.imgp_y;
	if (data->map[y][x] == 'P')
	{
		if (data->map[y][x - 1] == '1')
			return ;
		else if (data->map[y][x - 1] == 'E')
			try_to_scape(data);
		else if (data->map[y][x - 1] == 'C')
		{
			step_left(data, x, y);
			eat(data);
		}
		else if (data->map[y][x - 1] == '2')
			death(data);
		else
			step_left(data, x, y);
	}
}

void	kill_enemy(t_mlx_data *data, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 3)
	{
		while (j < 2)
		{
			if (data->map[y + i][x + j] == '2')
			{
				data->map[y + i][x + j] = '0';
				grasp(data, x + j, y + i);
			}
			j++;
		}
		i++;
		j = 0;
	}
}

void	atac_caw(t_mlx_data *data)
{
	int	x;
	int	y;

	x = data->caw.imgp_x;
	y = data->caw.imgp_y;
	if (data->direction == 0)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
			data->caw.img_8.img_ptr, x * 64, y * 64);
		kill_enemy(data, x, y - 1);
	}
	else
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
			data->caw.img_7.img_ptr, x * 64, y * 64);
		kill_enemy(data, x - 1, y - 1);
	}
}
