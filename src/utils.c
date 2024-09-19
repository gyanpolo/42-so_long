/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:56:34 by gpolo             #+#    #+#             */
/*   Updated: 2024/09/07 11:17:23 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_all(t_mlx_data *data)
{
	close_grass(data);
	close_fences(data);
	close_portal(data);
	close_objecives(data);
	close_caw(data);
	close_farmer(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free_all(data->map);
	exit(1);
}

void	open_img(t_mlx_data *data, t_img *img, char *str)
{
	img->img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, str,
			&img->img_x, &img->img_y);
	if (img->img_ptr == NULL)
	{
		ft_printf("Error: No se pudo cargar la imagen %s\n", str);
		mlx_destroy_window (data->mlx_ptr, data->win_ptr);
		mlx_destroy_display (data->mlx_ptr);
		free (data->mlx_ptr);
		exit (1);
	}
}

void	open_win(t_mlx_data *data, int x, int y)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		exit(1);
	data->win_ptr = mlx_new_window (data->mlx_ptr, x, y, "so_long");
	if (data->win_ptr == NULL)
	{
		mlx_destroy_display (data->mlx_ptr);
		free (data->mlx_ptr);
		exit (1);
	}
}

void	open_farmer(t_mlx_data *data)
{
	open_img (data, &data->farmer.img_1, "textures/farmer/farmer1.xpm");
	open_img (data, &data->farmer.img_2, "textures/farmer/farmer2.xpm");
	open_img (data, &data->farmer.img_3, "textures/farmer/farmer3.xpm");
	open_img (data, &data->farmer.img_4, "textures/farmer/farmer4.xpm");
	open_img (data, &data->farmer.img_5, "textures/farmer/farmer5.xpm");
	open_img (data, &data->farmer.img_6, "textures/farmer/farmer6.xpm");
	open_img (data, &data->farmer.img_7, "textures/farmer/farmer7.xpm");
	open_img (data, &data->farmer.img_8, "textures/farmer/farmer8.xpm");
	open_img (data, &data->farmer.img_9, "textures/farmer/farmer9.xpm");
	open_img (data, &data->farmer.img_10, "textures/farmer/farmer10.xpm");
	open_img (data, &data->farmer.img_11, "textures/farmer/farmer11.xpm");
	open_img (data, &data->farmer.img_12, "textures/farmer/farmer12.xpm");
}

void	ned_doc(void)
{
	ft_printf("falta arxivo .ber ex:\n");
	ft_printf("1111111111111\n10010000200C1\n1000011111001\n");
	ft_printf("1P0011E002001\n1111111111111\n");
	ft_printf("0: para un espacio vacío\n");
	ft_printf("1: para un muro\n");
	ft_printf("2: para un enemigo\n");
	ft_printf("C: para un coleccionable\n");
	ft_printf("E: para salir del mapa\n");
	ft_printf("P: para la posición inicial del jugador\n");
}
