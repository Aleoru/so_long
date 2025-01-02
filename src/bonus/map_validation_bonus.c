/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 18:19:50 by aoropeza          #+#    #+#             */
/*   Updated: 2022/09/07 17:58:54 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

static int	get_map_height(char *path, t_data *data)
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

static void	validate_map(t_data *data, char *path)
{
	char	*ext;

	if (ft_strrchr(path, '.'))
	{
		ext = ft_strrchr(path, '.');
		if (ft_strncmp(ext, ".ber", ft_strlen(ext)))
			exit_error(data, 1);
	}
}

static void	validate_map_structure(t_data *data, t_level *level, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (y < level->size_y)
	{
		x = 0;
		while (x < level->size_x)
		{
			if (y == 0 || y == level->size_y - 1)
			{
				if (map[y][x] != '1')
					exit_error(data, 3);
			}
			else if ((y > 0 && y < level->size_y)
				&& (x == 0 || x == level->size_x - 1))
			{
				if (map[y][x] != '1')
					exit_error(data, 3);
			}
			x++;
		}
		y++;
	}
}

static void	validate_map_content(t_data *data, t_level *level, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (y < level->size_y)
	{
		x = 0;
		while (x < level->size_x)
		{
			if (map[y][x] == 'C')
				level->c_count++;
			else if (map[y][x] == 'P')
				level->p_count++;
			else if (map[y][x] == 'E')
				level->e_count++;
			x++;
		}
		y++;
	}
	if (level->c_count < 1 || level->p_count < 1 || level->e_count < 1)
		exit_error(data, 4);
	if (level->p_count != 1)
		exit_error(data, 5);
}

void	init_map(t_data *data, t_level *level, char *str)
{
	level->path = ft_strjoin("assets/maps/", str);
	validate_map(data, level->path);
	level->size_y = get_map_height(level->path, data);
	read_map(level->path, level, data);
	validate_map_structure(data, level, level->map);
	validate_map_content(data, level, level->map);
}
