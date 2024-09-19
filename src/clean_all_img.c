/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_all_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 13:22:07 by gpolo             #+#    #+#             */
/*   Updated: 2024/09/06 13:42:15 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_img(t_mlx_data *data, t_img *img)
{
	mlx_destroy_image(data->mlx_ptr, img->img_ptr);
}

void	close_grass(t_mlx_data *data)
{
	close_img (data, &data->grass.img_1);
	close_img (data, &data->grass.img_2);
	close_img (data, &data->grass.img_3);
	close_img (data, &data->grass.img_4);
}

void	close_fences(t_mlx_data *data)
{
	close_img (data, &data->fence.img_1);
	close_img (data, &data->fence.img_2);
	close_img (data, &data->fence.img_3);
}

void	close_portal(t_mlx_data *data)
{
	close_img (data, &data->portal.img_1);
	close_img (data, &data->portal.img_2);
	close_img (data, &data->portal.img_3);
	close_img (data, &data->portal.img_4);
	close_img (data, &data->portal.img_5);
	close_img (data, &data->portal.img_6);
	close_img (data, &data->portal.img_7);
}

void	close_objecives(t_mlx_data *data)
{
	close_img (data, &data->objectives.img_1);
	close_img (data, &data->objectives.img_2);
	close_img (data, &data->objectives.img_3);
}
