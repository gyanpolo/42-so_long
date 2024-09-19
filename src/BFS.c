/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BFS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:48:47 by gpolo             #+#    #+#             */
/*   Updated: 2024/09/17 10:53:55 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enqueue(t_queue *q, t_point p)
{
	q->points[q->rear++] = p;
}

t_point	dequeue(t_queue *q)
{
	return (q->points[q->front++]);
}

int	is_empty(t_queue *q)
{
	return (q->front == q->rear);
}

int	do_bfs(char **map, int cols, int rows, t_bfs_u bfs_ut)
{
	while (!is_empty(&bfs_ut.q))
	{
		bfs_ut.current = dequeue(&bfs_ut.q);
		if (map[bfs_ut.current.y][bfs_ut.current.x] == 'C')
		{
			bfs_ut.collected++;
			if (bfs_ut.collected == bfs_ut.total_collectibles)
				return (1);
		}
		bfs_ut.i = 0;
		while (bfs_ut.i < 4)
		{
			bfs_new(map, cols, rows, &bfs_ut);
			bfs_ut.i++;
		}
	}
	return (0);
}

int	bfs(char **map, int rows, int cols, t_bfs_u bfs_ut)
{
	bfs_ut.visited = create_visited(rows, cols);
	move_x_y(bfs_ut.move_x, bfs_ut.move_y);
	bfs_ut.collected = 0;
	bfs_ut.q.front = 0;
	bfs_ut.q.rear = 0;
	init_visited(bfs_ut.visited, rows, cols);
	enqueue(&bfs_ut.q, bfs_ut.player_pos);
	bfs_ut.visited[bfs_ut.player_pos.y][bfs_ut.player_pos.x] = 1;
	if (do_bfs(map, cols, rows, bfs_ut) == 1)
	{
		free_all_i (bfs_ut.visited, rows);
		return (1);
	}
	free_all_i (bfs_ut.visited, rows);
	return (0);
}
