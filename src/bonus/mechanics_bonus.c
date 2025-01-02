/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mechanics_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 18:09:36 by aoropeza          #+#    #+#             */
/*   Updated: 2022/09/07 17:59:05 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

void	collect_key(t_data *data, t_img img)
{
	int	nkeys;
	int	index;
	int	size;
	int	x;
	int	y;

	nkeys = data->level.c_count;
	index = 0;
	size = data->img_size;
	while (index < nkeys)
	{
		x = img.key->instances[index].x / size;
		y = (img.key->instances[index].y / size) + 1;
		if (x == data->p_x && y == data->p_y
			&& img.key->instances[index].enabled == true)
		{
			img.key->instances[index].enabled = false;
			data->points++;
			data->level.map[data->p_y][data->p_x] = '0';
			return ;
		}
		index++;
	}
}

void	enemy_hit(t_data *data, int newx, int newy)
{
	int	i;

	i = 0;
	while (i < data->level.v_count)
	{
		if (newx == data->level.v_posx[i] && newy == data->level.v_posy[i])
		{
			ft_printf("\e[31mGAME OVER!\e[0m\n");
			close_game(data, data->error);
		}
		i++;
	}
}

/* The next function uses the rand function, to make the 
enemy movement randomised */

static t_pos	enemy_dir(t_data *data, int index)
{
	t_pos		pos;
	static int	rnd;

	rnd = rand() % 4;
	if (rnd == 0)
		pos = data->vector.up;
	if (rnd == 1)
		pos = data->vector.down;
	if (rnd == 2)
	{
		pos = data->vector.left;
		data->img.enemy[1]->instances[index].enabled = false;
		data->img.enemy[0]->instances[index].enabled = true;
	}
	if (rnd == 3)
	{
		pos = data->vector.right;
		data->img.enemy[0]->instances[index].enabled = false;
		data->img.enemy[1]->instances[index].enabled = true;
	}
	return (pos);
}

static void	enemy_move(t_data *data, t_level *lvl, int index, t_pos *e_pos)
{
	int	newx;
	int	newy;
	int	i;

	newx = lvl->v_posx[index] + e_pos[index].x;
	newy = lvl->v_posy[index] + e_pos[index].y;
	i = 0;
	if (data->level.map[newy][newx] != '1')
	{
		while (i < 2)
		{
			data->img.enemy[i]->instances[index].x += e_pos[index].x * 64;
			data->img.enemy[i]->instances[index].y += e_pos[index].y * 64;
			i++;
		}
		lvl->v_posx[index] = data->img.enemy[0]->instances[index].x / 64;
		lvl->v_posy[index] = data->img.enemy[0]->instances[index].y / 64;
		data->enemy_t = 0;
	}
	else
		e_pos[index] = enemy_dir(data, index);
}

void	enemy_movement(t_data *data, t_level *lvl)
{
	int				index;
	int				newx;
	int				newy;
	static t_pos	*e_pos;

	index = 0;
	if (data->init++ == 0)
		e_pos = ft_calloc(1, data->level.v_count * sizeof(t_pos));
	while (index < data->level.v_count)
	{
		if (e_pos[index].x == 0 && e_pos[index].y == 0)
			e_pos[index] = enemy_dir(data, index);
		newx = lvl->v_posx[index] + e_pos[index].x;
		newy = lvl->v_posy[index] + e_pos[index].y;
		if (newx == data->p_x && newy == data->p_y)
		{
			ft_printf("\e[31mGAME OVER!\e[0m\n");
			close_game(data, data->error);
		}
		enemy_move(data, lvl, index, e_pos);
		index++;
	}
}
