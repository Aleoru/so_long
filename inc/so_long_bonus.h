/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:51:25 by aoropeza          #+#    #+#             */
/*   Updated: 2022/08/15 17:37:31 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/inc/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

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

typedef struct level
{
	int			size_x;
	int			size_y;
	int			p_count;
	int			c_count;
	int			e_count;
	int			v_count;
	int			*v_posx;
	int			*v_posy;
	t_pos		*v_pos;
	char		*path;
	char		**map;
	t_vector	e_pos;
}	t_level;

typedef struct img
{
	mlx_image_t	**player;
	mlx_image_t	*ground;
	mlx_image_t	*wall;
	mlx_image_t	*key;
	mlx_image_t	**exit;
	mlx_image_t	**enemy;
	mlx_image_t	*text;
}	t_img;

typedef struct data
{
	mlx_t		*mlx;
	int			img_size;
	int			p_x;
	int			p_y;
	int			points;
	int			steps;
	int			error;
	int			timer;
	int			enemy_t;
	int			key_t;
	int			blink;
	int			walk;
	int			init;
	int			dir;
	int			s_key;
	int			p_key;
	int			portal;
	int			portal_t;
	t_img		img;
	t_level		level;
	t_vector	vector;
	t_pos		text_pos;
}	t_data;

/* INIT */
void	init(t_data *data, char *str);

/* MAIN */
void	exit_error(t_data *data, int error);
void	close_game(t_data *data, int error);

/* IMAGES */

void	init_img(t_data *data);
void	init_sprite(t_data *data);
void	init_player_sprite(t_data *data);
void	delete_img(t_data *data);

/* MAP VALIDATION & CREATION */

void	init_map(t_data *data, t_level *level, char *str);
void	read_map(char *path, t_level *level, t_data *data);
void	load_exit(t_data *data, int index, int x, int y);
void	create_map(t_data *data, int s, t_img img);

/* ANIMATIONS */
void	iddle_right(t_data *data);
void	iddle_left(t_data *data);
void	walk_right(t_data *data);
void	walk_left(t_data *data);
void	key_animation(void *param);
void	portal_close(t_data *data);
void	portal_open(t_data *data);

/* GAME MECHANICS */

void	collect_key(t_data *data, t_img img);
void	enemy_hit(t_data *data, int newx, int newy);

/* GAME TEXT */
void	print_text(t_data *data, char *str);
void	win(t_data *data);

/* GAME MOVEMENTS */

void	init_vector(t_data *data, t_vector *vector);
void	move(t_data *data, t_pos *pos);
void	movement(mlx_key_data_t keydata, void *param);
void	enemy_movement(t_data *data, t_level *lvl);

#endif
