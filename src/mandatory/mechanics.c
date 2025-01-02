/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mechanics.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 18:09:36 by aoropeza          #+#    #+#             */
/*   Updated: 2022/08/15 17:31:08 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

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
		y = img.key->instances[index].y / size;
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
