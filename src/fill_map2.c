/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:56:00 by gpolo             #+#    #+#             */
/*   Updated: 2024/09/07 14:26:37 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	caw(t_mlx_data *data, int x, int y)
{
	grasp(data, x, y);
	if (data->direction == 0)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
			data->caw.img_4.img_ptr, x * 64, y * 64);
	}
	else
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
			data->caw.img_1.img_ptr, x * 64, y * 64);
	}
	data->caw.imgp_x = x;
	data->caw.imgp_y = y;
}

void	farmer(t_mlx_data *data, int x, int y)
{
	grasp(data, x, y);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->farmer.img_2.img_ptr, x * 64, y * 64);
	data->farmer.imgp_x = x;
	data->farmer.imgp_y = y;
}

void	portal(t_mlx_data *data, int x, int y)
{
	grasp(data, x, y);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->portal.img_1.img_ptr, x * 64 + 24, y * 64 + 24);
	data->portal.imgp_x = x;
	data->portal.imgp_y = y;
}
