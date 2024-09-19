/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:25:02 by gpolo             #+#    #+#             */
/*   Updated: 2024/09/07 11:13:01 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_grass(t_mlx_data *data)
{
	open_img (data, &data->grass.img_1, "./textures/grass/grass.xpm");
	open_img (data, &data->grass.img_2, "./textures/grass/grass_d1.xpm");
	open_img (data, &data->grass.img_3, "./textures/grass/grass_d2.xpm");
	open_img (data, &data->grass.img_4, "./textures/grass/grass_d3.xpm");
}

void	open_fences(t_mlx_data *data)
{
	open_img (data, &data->fence.img_1, "./textures/fences/fence.xpm");
	open_img (data, &data->fence.img_2, "./textures/fences/ext_lat.xpm");
	open_img (data, &data->fence.img_3, "./textures/fences/ext_or.xpm");
}

void	open_portal(t_mlx_data *data)
{
	open_img (data, &data->portal.img_1, "./textures/exit/portal7.xpm");
	open_img (data, &data->portal.img_2, "./textures/exit/portal1.xpm");
	open_img (data, &data->portal.img_3, "./textures/exit/portal2.xpm");
	open_img (data, &data->portal.img_4, "./textures/exit/portal3.xpm");
	open_img (data, &data->portal.img_5, "./textures/exit/portal4.xpm");
	open_img (data, &data->portal.img_6, "./textures/exit/portal5.xpm");
	open_img (data, &data->portal.img_7, "./textures/exit/portal6.xpm");
}

void	open_objecives(t_mlx_data *data)
{
	open_img (data, &data->objectives.img_1,
		"./textures/objectives/carrot.xpm");
	open_img (data, &data->objectives.img_2,
		"./textures/objectives/red_flower.xpm");
	open_img (data, &data->objectives.img_3,
		"./textures/objectives/ye_flower.xpm");
}

void	open_caw(t_mlx_data *data)
{
	open_img (data, &data->caw.img_1, "textures/caw/caw1.xpm");
	open_img (data, &data->caw.img_2, "textures/caw/caw2.xpm");
	open_img (data, &data->caw.img_3, "textures/caw/caw3.xpm");
	open_img (data, &data->caw.img_4, "textures/caw/caw4.xpm");
	open_img (data, &data->caw.img_5, "textures/caw/caw5.xpm");
	open_img (data, &data->caw.img_6, "textures/caw/caw6.xpm");
	open_img (data, &data->caw.img_7, "textures/caw/caw7.xpm");
	open_img (data, &data->caw.img_8, "textures/caw/caw8.xpm");
}
