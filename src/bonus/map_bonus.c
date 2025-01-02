/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 18:07:35 by aoropeza          #+#    #+#             */
/*   Updated: 2022/09/07 17:58:44 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

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

static void	load_sprites(t_data *data, int s, mlx_image_t **player)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		mlx_image_to_window(data->mlx, player[i], data->p_x * s, data->p_y * s);
		if (i > 0)
			player[i]->instances[0].enabled = false;
		i++;
	}
}

static void	load_enemy(t_data *data, int s, mlx_image_t **enemy)
{
	int	index;
	int	x;
	int	y;

	index = -1;
	y = 0;
	data->level.v_posx = malloc(data->level.v_count * sizeof(int));
	data->level.v_posy = malloc(data->level.v_count * sizeof(int));
	while (y < data->level.size_y)
	{
		x = -1;
		while (++x < data->level.size_x)
		{
			if (data->level.map[y][x] == 'V' && ++index != data->level.v_count)
			{
				mlx_image_to_window(data->mlx, enemy[0], x * s, y * s);
				mlx_image_to_window(data->mlx, enemy[1], x * s, y * s);
				data->level.v_posx[index] = x;
				data->level.v_posy[index] = y;
				enemy[1]->instances[index].enabled = false;
			}
		}
		y++;
	}
	load_sprites(data, s, data->img.player);
}

static void	load_content(t_data *data, int s, t_img img)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->level.size_y)
	{
		x = -1;
		while (++x < data->level.size_x)
		{
			if (data->level.map[y][x] == 'V')
				data->level.v_count++;
			if (data->level.map[y][x] == 'P')
			{
				data->p_x = x;
				data->p_y = y;
			}
		}
		y++;
	}
	load_enemy(data, s, img.enemy);
}

void	create_map(t_data *data, int s, t_img img)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	i = -1;
	while (y < data->level.size_y)
	{
		x = -1;
		while (++x < data->level.size_x)
		{
			if (ft_strchr("0CPEV", data->level.map[y][x]))
				mlx_image_to_window(data->mlx, img.ground, x * s, y * s);
			else if (data->level.map[y][x] == '1')
				mlx_image_to_window(data->mlx, img.wall, x * s, y * s);
			else
				exit_error(data, 7);
			if (data->level.map[y][x] == 'C')
				mlx_image_to_window(data->mlx, img.key, x * s, y * s + 1);
			if (data->level.map[y][x] == 'E')
				load_exit(data, ++i, x, y);
		}
		y++;
	}
	load_content(data, s, img);
}
