/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:01:39 by gpolo             #+#    #+#             */
/*   Updated: 2024/09/12 16:02:11 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	step_right(t_mlx_data *data, int x, int y)
{
	data->direction = 0;
	data->steps++;
	data->map[y][x] = '0';
	data->map[y][x + 1] = 'P';
	grasp(data, x, y);
	caw(data, x + 1, y);
	put_steps(data);
}

void	step_down(t_mlx_data *data, int x, int y)
{
	data->steps++;
	data->map[y][x] = '0';
	data->map[y + 1][x] = 'P';
	grasp(data, x, y);
	caw(data, x, y + 1);
	put_steps(data);
}

void	move_right_caw(t_mlx_data *data)
{
	int	x;
	int	y;

	x = data->caw.imgp_x;
	y = data->caw.imgp_y;
	if (data->map[y][x] == 'P')
	{
		if (data->map[y][x + 1] == '1')
			return ;
		else if (data->map[y][x + 1] == 'E')
			try_to_scape(data);
		else if (data->map[y][x + 1] == 'C')
		{
			step_right(data, x, y);
			eat(data);
		}
		else if (data->map[y][x + 1] == '2')
			death(data);
		else
			step_right(data, x, y);
	}
}

void	move_down_caw(t_mlx_data *data)
{
	int	x;
	int	y;

	x = data->caw.imgp_x;
	y = data->caw.imgp_y;
	if (data->map[y][x] == 'P')
	{
		if (data->map[y + 1][x] == '1')
			return ;
		else if (data->map[y + 1][x] == 'E')
			try_to_scape(data);
		else if (data->map[y + 1][x] == 'C')
		{
			step_down(data, x, y);
			eat(data);
		}
		else if (data->map[y + 1][x] == '2')
			death(data);
		else
			step_down(data, x, y);
	}
}
