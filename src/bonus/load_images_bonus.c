/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:53:57 by aoropeza          #+#    #+#             */
/*   Updated: 2022/09/07 17:58:14 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

void	load_exit(t_data *data, int index, int x, int y)
{
	int	j;
	int	s;

	s = data->img_size;
	j = -1;
	while (++j < 4)
	{
		mlx_image_to_window(data->mlx, data->img.exit[j], x * s, y * s);
		if (j > 0)
			data->img.exit[j]->instances[index].enabled = false;
	}
}
