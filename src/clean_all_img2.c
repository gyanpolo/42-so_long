/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_all_img2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 13:32:08 by gpolo             #+#    #+#             */
/*   Updated: 2024/09/06 15:18:46 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_caw(t_mlx_data *data)
{
	close_img (data, &data->caw.img_1);
	close_img (data, &data->caw.img_2);
	close_img (data, &data->caw.img_3);
	close_img (data, &data->caw.img_4);
	close_img (data, &data->caw.img_5);
	close_img (data, &data->caw.img_6);
	close_img (data, &data->caw.img_7);
	close_img (data, &data->caw.img_8);
}

void	close_farmer(t_mlx_data *data)
{
	close_img (data, &data->farmer.img_1);
	close_img (data, &data->farmer.img_2);
	close_img (data, &data->farmer.img_3);
	close_img (data, &data->farmer.img_4);
	close_img (data, &data->farmer.img_5);
	close_img (data, &data->farmer.img_6);
	close_img (data, &data->farmer.img_7);
	close_img (data, &data->farmer.img_8);
	close_img (data, &data->farmer.img_9);
	close_img (data, &data->farmer.img_10);
	close_img (data, &data->farmer.img_11);
	close_img (data, &data->farmer.img_12);
}
