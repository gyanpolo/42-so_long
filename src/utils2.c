/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:32:11 by gpolo             #+#    #+#             */
/*   Updated: 2024/09/17 13:32:37 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_x(char **map)
{
	int	i;

	i = 0;
	while (map[0][i])
		i++;
	return (i);
}

int	count_y(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	init_count_map(char *file)
{
	int		count;
	int		fd;
	char	caracter;

	count = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	while (read(fd, &caracter, 1) == 1)
	{
		count++;
	}
	close(fd);
	return (count);
}

char	*init_tmp_map(char *file)
{
	char	*map;
	char	caracter;
	int		fd;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	map = (char *)malloc(sizeof(char) * (init_count_map(file) + 1));
	if (!map)
		return (NULL);
	while (read(fd, &caracter, 1) == 1)
	{
		map[i++] = caracter;
	}
	map [i] = '\0';
	close(fd);
	if (!chek_nl(map))
	{
		free(map);
		return (0);
	}
	return (map);
}

int	make_map(t_mlx_data *data, char *str)
{
	int		x;
	int		y;
	char	*t_map;

	y = 0;
	t_map = init_tmp_map(str);
	if (!t_map)
		return (0);
	data->map = ft_split(t_map, '\n');
	free (t_map);
	x = count_x(data->map);
	y = count_y(data->map);
	data->win_x = x;
	data->win_y = y;
	if ((test_map(data, x, y)) == 1)
		map_pos(data, x, y);
	else
	{
		ft_printf("Error\nImpsoible Map\n");
		free_all(data->map);
		exit(1);
	}
	return (1);
}
