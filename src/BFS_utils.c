/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BFS_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 10:27:45 by gpolo             #+#    #+#             */
/*   Updated: 2024/09/17 10:54:24 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	**free_all_i(int **result, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (0);
}

void	bfs_new(char **map, int cols, int rows, t_bfs_u *bfs_ut)
{
	int	new_x;
	int	new_y;

	new_x = bfs_ut->current.x + bfs_ut->move_x[bfs_ut->i];
	new_y = bfs_ut->current.y + bfs_ut->move_y[bfs_ut->i];
	if (new_x >= 0 && new_x < cols && new_y >= 0 && new_y < rows
		&& map[new_y][new_x] != '1' && !bfs_ut->visited[new_y][new_x])
	{
		bfs_ut->visited[new_y][new_x] = 1;
		bfs_ut->new_point.x = new_x;
		bfs_ut->new_point.y = new_y;
		enqueue(&bfs_ut->q, bfs_ut->new_point);
	}
}

int	**create_visited(int rows, int cols)
{
	int	i;
	int	**visited;

	i = 0;
	visited = (int **)malloc((rows) * sizeof(int *));
	if (!visited)
	{
		free_all_i(visited, rows);
		return (0);
	}
	while (i < rows)
	{
		visited[i] = (int *)malloc((cols) * sizeof(int));
		if (!visited[i])
		{
			free_all_i(visited, rows);
			return (0);
		}
		i++;
	}
	return (visited);
}

void	move_x_y(int *move_x, int *move_y)
{
	move_x[0] = 0;
	move_x[1] = 0;
	move_x[2] = -1;
	move_x[3] = 1;
	move_y[0] = -1;
	move_y[1] = 1;
	move_y[2] = 0;
	move_y[3] = 0;
}

void	init_visited(int **visited, int rows, int cols)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			visited[i][j] = 0;
			j++;
		}
		i++;
	}
}
