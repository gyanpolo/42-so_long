/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:55:01 by gpolo             #+#    #+#             */
/*   Updated: 2024/09/12 16:01:44 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	step_up(t_mlx_data *data, int x, int y)
{
	data->steps++;
	data->map[y][x] = '0';
	data->map[y - 1][x] = 'P';
	grasp(data, x, y);
	caw(data, x, y - 1);
	put_steps(data);
}

void	try_to_scape(t_mlx_data *data)
{
	if (data->points == 0)
	{
		ft_printf("you winn\n");
		clean_all(data);
		exit(1);
	}
	else
	{
		ft_printf("you ned all colectionables\n");
		return ;
	}
}

void	death(t_mlx_data *data)
{
	ft_printf("you'r a BBQ\n");
	clean_all(data);
	exit(1);
}

void	eat(t_mlx_data *data)
{
	data->points--;
	if (data->points == 0)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->portal.img_2.img_ptr, data->portal.imgp_x * 64 + 14,
			data->portal.imgp_y * 64);
}

void	move_up_caw(t_mlx_data *data)
{
	int	x;
	int	y;

	x = data->caw.imgp_x;
	y = data->caw.imgp_y;
	if (data->map[y][x] == 'P')
	{
		if (data->map[y - 1][x] == '1')
			return ;
		else if (data->map[y - 1][x] == 'E')
			try_to_scape(data);
		else if (data->map[y - 1][x] == 'C')
		{
			step_up(data, x, y);
			eat(data);
		}
		else if (data->map[y - 1][x] == '2')
			death(data);
		else
			step_up(data, x, y);
	}
}
