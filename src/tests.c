/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:31:40 by gpolo             #+#    #+#             */
/*   Updated: 2024/09/17 10:56:53 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	basic_test(t_mlx_data *data, int x, int y, t_test_values *tst_v)
{
	char	t;

	t = data->map[tst_v->i][tst_v->j];
	if (t != 'C' && t != 'E' && t != '0' && t != '1' && t != '2' && t != 'P')
		return (0);
	if ((tst_v->i == 0 || tst_v->j == 0 || tst_v->i == y - 1
			|| tst_v->j == x - 1) && (t != '1'))
		return (0);
	if (t == 'C')
		tst_v->obj++;
	if (t == 'E')
	{
		data->portal.imgp_x = tst_v->j;
		data->portal.imgp_y = tst_v->i;
		tst_v->ex++;
	}
	if (t == 'P')
	{
		data->caw.imgp_x = tst_v->j;
		data->caw.imgp_y = tst_v->i;
		tst_v->p++;
	}
	return (1);
}

int	reult_test(t_test_values *tst_v, t_mlx_data *data, int x, int y)
{
	t_bfs_u	bfs_ut;

	bfs_ut.total_collectibles = tst_v->obj;
	bfs_ut.player_pos.y = data->caw.imgp_y;
	bfs_ut.player_pos.x = data->caw.imgp_x;
	data->map[data->portal.imgp_y][data->portal.imgp_x] = '1';
	if (tst_v->obj == 0)
		return (0);
	if (tst_v->ex != 1)
		return (0);
	if (tst_v->p != 1)
		return (0);
	if (bfs(data->map, y, x, bfs_ut) == 0)
		return (0);
	data->map[data->portal.imgp_y][data->portal.imgp_x] = 'C';
	bfs_ut.total_collectibles++;
	if (bfs(data->map, y, x, bfs_ut) == 0)
		return (0);
	data->map[data->portal.imgp_y][data->portal.imgp_x] = 'E';
	return (1);
}

int	test_map(t_mlx_data *data, int x, int y)
{
	t_test_values	tst_v;

	tst_v.i = 0;
	tst_v.j = 0;
	tst_v.obj = 0;
	tst_v.ex = 0;
	tst_v.p = 0;
	while (data->map[tst_v.i])
	{
		while (data->map[tst_v.i][tst_v.j])
		{
			if (basic_test(data, x, y, &tst_v) == 0)
				return (0);
			tst_v.j++;
		}
		if (tst_v.j != x)
			return (0);
		tst_v.j = 0;
		tst_v.i++;
	}
	if (reult_test(&tst_v, data, x, y) == 0)
		return (0);
	return (1);
}
