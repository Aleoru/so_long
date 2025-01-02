/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 19:18:38 by aoropeza          #+#    #+#             */
/*   Updated: 2022/09/07 17:58:04 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

void	init(t_data *data, char *str)
{
	init_map(data, &data->level, str);
	data->img_size = 64;
	data->mlx = mlx_init(data->img_size * data->level.size_x, data->img_size
			* data->level.size_y + data->img_size, "SO_LONG", true);
	if (!data->mlx)
		exit(EXIT_FAILURE);
	init_vector(data, &data->vector);
	init_img(data);
	init_sprite(data);
	init_player_sprite(data);
	data->text_pos.x = 0;
	data->text_pos.y = data->level.size_y * data->img_size;
	create_map(data, data->img_size, data->img);
	print_text(data, "0");
}
