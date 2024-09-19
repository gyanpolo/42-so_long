/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:40:59 by gpolo             #+#    #+#             */
/*   Updated: 2024/09/17 12:55:28 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	cerrar_ventana(t_mlx_data *data)
{
	clean_all(data);
	exit(1);
}

int	handle_input(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
	{
		clean_all(data);
		exit (1);
	}
	else if (keysym == XK_w)
		move_up_caw(data);
	else if (keysym == XK_d)
		move_right_caw(data);
	else if (keysym == XK_s)
		move_down_caw(data);
	else if (keysym == XK_a)
		move_left_caw(data);
	else if (keysym == XK_q)
		atac_caw(data);
	return (0);
}

void	open_all(t_mlx_data *data)
{
	open_grass(data);
	open_fences(data);
	open_portal(data);
	open_objecives(data);
	open_caw(data);
	open_farmer(data);
}

int	main(int argc, char **argv)
{
	t_mlx_data	data;

	data.direction = 0;
	data.steps = 0;
	data.points = 0;
	if (argc != 2 || !(is_ber(argv[1])))
	{
		ned_doc();
		return (1);
	}
	if (!make_map(&data, argv[1]))
	{
		ft_printf("Error\nOpening File or Empty line\n");
		return (0);
	}
	put_steps(&data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, handle_input, &data);
	mlx_hook(data.win_ptr, 17, 0L, cerrar_ventana, &data);
	mlx_loop (data.mlx_ptr);
	return (0);
}
