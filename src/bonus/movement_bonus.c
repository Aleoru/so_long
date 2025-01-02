/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 18:08:46 by aoropeza          #+#    #+#             */
/*   Updated: 2022/09/07 17:59:14 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

void	init_vector(t_data *data, t_vector *vector)
{
	vector->up.x = 0;
	vector->up.y = -1;
	vector->down.x = 0;
	vector->down.y = 1;
	vector->left.x = -1;
	vector->left.y = 0;
	vector->right.x = 1;
	vector->right.y = 0;
	data->walk = 2;
}

static void	move_sprite(t_data *data, t_pos *pos)
{
	int	index;

	index = 0;
	while (index < 8)
	{
		data->img.player[index]->instances[0].y += pos->y * data->img_size;
		data->img.player[index]->instances[0].x += pos->x * data->img_size;
		index++;
	}
	if (data->dir == 0)
	{
		if (data->walk == 0 || data->walk == 2 || data->walk == 3)
			data->walk = 6;
		walk_left(data);
	}
	else if (data->dir == 1)
	{
		if (data->walk == 0 || data->walk == 6 || data->walk == 7)
			data->walk = 2;
		walk_right(data);
	}
}

void	move(t_data *data, t_pos *pos)
{
	int	newx;
	int	newy;

	newx = data->p_x + pos->x;
	newy = data->p_y + pos->y;
	move_sprite(data, pos);
	data->steps++;
	if (data->level.map[data->p_y + pos->y][data->p_x + pos->x] == 'C')
	{
		data->p_x = data->img.player[0]->instances[0].x / 64;
		data->p_y = data->img.player[0]->instances[0].y / 64;
		collect_key(data, data->img);
	}
	if (data->points == data->level.c_count)
	{
		data->portal = 2;
		if (data->level.map[data->p_y + pos->y][data->p_x + pos->x] == 'E')
			win(data);
	}
	enemy_hit(data, newx, newy);
	print_text(data, ft_itoa(data->steps));
	ft_printf("pasos: %d, puntos: %d\n", data->steps, data->points);
}

void	movement(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = param;
	data->p_x = data->img.player[0]->instances[0].x / 64;
	data->p_y = data->img.player[0]->instances[0].y / 64;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		close_game(data, data->error);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS
		&& data->level.map[data->p_y - 1][data->p_x] != '1')
		move(data, &data->vector.up);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS
		&& data->level.map[data->p_y + 1][data->p_x] != '1')
		move(data, &data->vector.down);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS
		&& data->level.map[data->p_y][data->p_x - 1] != '1')
	{
		data->dir = 0;
		move(data, &data->vector.left);
	}
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS
		&& data->level.map[data->p_y][data->p_x + 1] != '1')
	{
		data->dir = 1;
		move(data, &data->vector.right);
	}
}
