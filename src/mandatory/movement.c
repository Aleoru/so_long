/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 18:08:46 by aoropeza          #+#    #+#             */
/*   Updated: 2022/08/15 17:31:17 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	init_vector(t_vector *vector)
{
	vector->up.x = 0;
	vector->up.y = -1;
	vector->down.x = 0;
	vector->down.y = 1;
	vector->left.x = -1;
	vector->left.y = 0;
	vector->right.x = 1;
	vector->right.y = 0;
}

void	move(t_data *data, t_pos *pos)
{
	data->img.player->instances[0].y += pos->y * data->img_size;
	data->img.player->instances[0].x += pos->x * data->img_size;
	data->steps++;
	if (data->level.map[data->p_y + pos->y][data->p_x + pos->x] == 'C')
	{
		data->p_x = data->img.player->instances[0].x / 64;
		data->p_y = data->img.player->instances[0].y / 64;
		collect_key(data, data->img);
	}
	if (data->points == data->level.c_count)
	{
		data->img.exit[0]->instances[0].enabled = false;
		data->img.exit[1]->instances[0].enabled = true;
		if (data->level.map[data->p_y + pos->y][data->p_x + pos->x] == 'E')
		{
			ft_printf("\e[32;1mYOU WIN!\e[0m\n");
			close_game(data, data->error);
		}
	}
	ft_printf("pasos: %d, puntos: %d\n", data->steps, data->points);
}

void	movement(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = param;
	data->p_x = data->img.player->instances[0].x / 64;
	data->p_y = data->img.player->instances[0].y / 64;
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
		move(data, &data->vector.left);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS
		&& data->level.map[data->p_y][data->p_x + 1] != '1')
		move(data, &data->vector.right);
}
