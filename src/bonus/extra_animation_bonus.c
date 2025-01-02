/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_animation_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:06:40 by aoropeza          #+#    #+#             */
/*   Updated: 2022/09/07 17:57:39 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

void	key_animation(void *param)
{
	t_data		*data;
	static int	move;
	int			j;

	data = param;
	if (data->key_t <= 20)
		return ;
	j = -1;
	if (data->s_key++ == 0)
		move = 5;
	if (data->p_key >= 4)
	{
		move *= -1;
		data->p_key = 1;
	}
	while (++j < data->level.c_count)
	{
		if (data->p_key < 4)
			data->img.key->instances[j].y -= move;
	}
	data->p_key++;
	data->key_t = 0;
}

void	portal_close(t_data *data)
{
	int		i;
	int		j;

	i = -1;
	j = data->portal;
	while (++i < data->level.e_count)
	{
		if (data->img.exit[0]->instances[i].enabled == true || j == 0)
		{
			data->img.exit[0]->instances[i].enabled = false;
			data->img.exit[1]->instances[i].enabled = true;
			data->portal = 1;
		}
		else if (data->img.exit[1]->instances[i].enabled == true || j == 1)
		{
			data->img.exit[1]->instances[i].enabled = false;
			data->img.exit[0]->instances[i].enabled = true;
			data->portal = 0;
		}
	}
	data->portal_t = 0;
}

void	portal_open(t_data *data)
{
	int		i;
	int		j;

	i = -1;
	j = data->portal;
	data->img.exit[0]->instances[i].enabled = false;
	data->img.exit[1]->instances[i].enabled = false;
	while (++i < data->level.e_count)
	{
		if (data->img.exit[2]->instances[i].enabled == true || j == 2)
		{
			data->img.exit[2]->instances[i].enabled = false;
			data->img.exit[3]->instances[i].enabled = true;
			data->portal = 3;
		}
		else if (data->img.exit[3]->instances[i].enabled == true || j == 3)
		{
			data->img.exit[3]->instances[i].enabled = false;
			data->img.exit[2]->instances[i].enabled = true;
			data->portal = 2;
		}
	}
	data->portal_t = 0;
}
