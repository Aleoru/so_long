/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:51:25 by aoropeza          #+#    #+#             */
/*   Updated: 2022/08/15 17:31:36 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/inc/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct level
{
	int		size_x;
	int		size_y;
	int		p_count;
	int		c_count;
	int		e_count;
	char	*path;
	char	**map;
}	t_level;

typedef struct img
{
	mlx_image_t		*player;
	mlx_image_t		*ground;
	mlx_image_t		*wall;
	mlx_image_t		*key;
	mlx_image_t		**exit;
}	t_img;

typedef struct pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct vector
{
	t_pos	up;
	t_pos	down;
	t_pos	left;
	t_pos	right;
}	t_vector;

typedef struct data
{
	mlx_t		*mlx;
	int			img_size;
	int			p_x;
	int			p_y;
	int			points;
	int			steps;
	int			error;
	t_img		img;
	t_level		level;
	t_vector	vector;
}	t_data;

/* MAIN */
void	exit_error(t_data *data, int error);
void	close_game(t_data *data, int error);

/* IMAGES */

void	init_img(t_data *data);
void	delete_img(t_data *data);

/* MAP VALIDATION & CREATION */

void	init_map(t_data *data, t_level *level, char *str);
int		get_map_height(char *path, t_data *data);
void	read_map(char *path, t_level *level, t_data *data);
void	create_map(t_data *data, int s, t_img img);

/* GAME MECHANICS */

void	collect_key(t_data *data, t_img img);

/* GAME MOVEMENTS */

void	init_vector(t_vector *vector);
void	move(t_data *data, t_pos *pos);
void	movement(mlx_key_data_t keydata, void *param);

#endif
