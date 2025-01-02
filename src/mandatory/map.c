/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 18:07:35 by aoropeza          #+#    #+#             */
/*   Updated: 2022/08/15 17:30:40 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	get_map_height(char *path, t_data *data)
{
	int		fd;
	int		y;
	char	*line;

	y = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit_error(data, 6);
	else
	{
		line = get_next_line(fd);
		data->level.size_x = ft_strlen(line) - 1;
		while (line != NULL)
		{
			free(line);
			y++;
			line = get_next_line(fd);
		}
		close(fd);
	}
	return (y);
}

void	read_map(char *path, t_level *level, t_data *data)
{
	int		y;
	int		fd;
	size_t	len;

	y = 0;
	level->map = ft_calloc(level->size_y, level->size_x);
	len = level->size_x;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit_error(data, 6);
	else
	{
		level->map[y] = get_next_line(fd);
		while (level->map[y] != NULL)
		{
			if (len != ft_strlen(level->map[y]) - 1)
				exit_error(data, 2);
			y++;
			level->map[y] = get_next_line(fd);
		}
		close(fd);
	}
}

static void	load_content(t_data *data, int s, t_img img)
{
	int			x;
	int			y;

	y = 0;
	while (y < data->level.size_y)
	{
		x = -1;
		while (++x < data->level.size_x)
		{
			if (data->level.map[y][x] == 'C')
				mlx_image_to_window(data->mlx, img.key, x * s, y * s);
			if (data->level.map[y][x] == 'E')
			{
				mlx_image_to_window(data->mlx, img.exit[1], x * s, y * s);
				data->img.exit[1]->instances[0].enabled = false;
			}
			if (data->level.map[y][x] == 'P')
			{
				data->p_x = x;
				data->p_y = y;
			}
		}
		y++;
	}
	mlx_image_to_window(data->mlx, img.player, data->p_x * s, data->p_y * s);
}

void	create_map(t_data *data, int s, t_img img)
{
	int			x;
	int			y;

	y = 0;
	while (y < data->level.size_y)
	{
		x = 0;
		while (x < data->level.size_x)
		{
			if (ft_strchr("0CPE", data->level.map[y][x]))
				mlx_image_to_window(data->mlx, img.ground, x * s, y * s);
			else if (data->level.map[y][x] == '1')
				mlx_image_to_window(data->mlx, img.wall, x * s, y * s);
			else
				exit_error(data, 7);
			if (data->level.map[y][x] == 'E')
				mlx_image_to_window(data->mlx, img.exit[0], x * s, y * s);
			x++;
		}
		y++;
	}
	load_content(data, s, img);
}
