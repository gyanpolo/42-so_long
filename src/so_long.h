/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:01:15 by gpolo             #+#    #+#             */
/*   Updated: 2024/09/17 12:50:01 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "libftprintf.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_img
{
	void	*img_ptr;
	int		img_x;
	int		img_y;
}				t_img;

typedef struct s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct s_queue
{
	t_point	points[100000];
	int		front;
	int		rear;
}				t_queue;

typedef struct s_bfs_u
{
	int		i;
	int		collected;
	int		total_collectibles;
	int		**visited;
	int		move_x[4];
	int		move_y[4];
	t_queue	q;
	t_point	current;
	t_point	new_point;
	t_point	player_pos;
}				t_bfs_u;

typedef struct s_test_values
{
	int	i;
	int	j;
	int	obj;
	int	ex;
	int	p;
}				t_test_values;

typedef struct s_dif_img
{
	int		imgp_x;
	int		imgp_y;
	t_img	img_1;
	t_img	img_2;
	t_img	img_3;
	t_img	img_4;
	t_img	img_5;
	t_img	img_6;
	t_img	img_7;
	t_img	img_8;
	t_img	img_9;
	t_img	img_10;
	t_img	img_11;
	t_img	img_12;
}				t_dif_img;

typedef struct s_mlx_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		**map;
	int			fd;
	int			points;
	int			steps;
	int			direction;
	int			win_x;
	int			win_y;
	t_dif_img	grass;
	t_dif_img	fence;
	t_dif_img	objectives;
	t_dif_img	portal;
	t_dif_img	caw;
	t_dif_img	farmer;
}				t_mlx_data;

void	clean_all(t_mlx_data *data);
void	open_img(t_mlx_data*data, t_img *img, char *str);
void	open_win(t_mlx_data *data, int x, int y);
void	ned_doc(void);
char	**ft_split(char const *s, char c);
int		make_map(t_mlx_data *data, char *str);
char	**free_all(char **result);
void	fill_map(t_mlx_data *data, char **map);
void	open_all(t_mlx_data *data);
void	open_grass(t_mlx_data *data);
void	open_fences(t_mlx_data *data);
void	open_portal(t_mlx_data *data);
void	open_objecives(t_mlx_data *data);
void	open_caw(t_mlx_data *data);
void	open_farmer(t_mlx_data *data);
void	caw(t_mlx_data *data, int x, int y);
void	grasp(t_mlx_data *data, int x, int y);
void	farmer(t_mlx_data *data, int x, int y);
void	move_up_caw(t_mlx_data *data);
void	try_to_scape(t_mlx_data *data);
void	death(t_mlx_data *data);
void	move_right_caw(t_mlx_data *data);
void	putbakgraud(t_mlx_data *data);
void	move_down_caw(t_mlx_data *data);
void	eat(t_mlx_data *data);
void	step_down(t_mlx_data *data, int x, int y);
void	move_left_caw(t_mlx_data *data);
int		test_map(t_mlx_data *data, int x, int y);
int		bfs(char **map, int rows, int cols, t_bfs_u bfs_ut);
int		**free_all_i(int **result, int rows);
void	move_x_y(int *move_x, int *move_y);
void	init_visited(int **visited, int rows, int cols);
int		**create_visited(int rows, int cols);
void	close_img(t_mlx_data *data, t_img *img);
void	close_grass(t_mlx_data *data);
void	close_fences(t_mlx_data *data);
void	close_portal(t_mlx_data *data);
void	close_objecives(t_mlx_data *data);
void	close_caw(t_mlx_data *data);
void	close_farmer(t_mlx_data *data);
void	portal(t_mlx_data *data, int x, int y);
void	bfs_new(char **map, int cols, int rows, t_bfs_u *bfs_ut);
void	enqueue(t_queue *q, t_point p);
void	atac_caw(t_mlx_data *data);
char	*ft_itoa(int n);
void	put_steps(t_mlx_data *data);
void	map_pos(t_mlx_data *data, int x, int y);
int		is_ber(char *str);
int		chek_nl(char *str);

#endif
