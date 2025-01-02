/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 18:03:57 by aoropeza          #+#    #+#             */
/*   Updated: 2022/08/15 17:30:21 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	init_img(t_data *data)
{
	mlx_texture_t	*textura;

	textura = mlx_load_png("./assets/img/brick-wall-v2.png");
	data->img.wall = mlx_texture_to_image(data->mlx, textura);
	textura = mlx_load_png("./assets/img/ground.png");
	data->img.ground = mlx_texture_to_image(data->mlx, textura);
	textura = mlx_load_png("./assets/img/hooman1.png");
	data->img.player = mlx_texture_to_image(data->mlx, textura);
	textura = mlx_load_png("./assets/img/key.png");
	data->img.key = mlx_texture_to_image(data->mlx, textura);
	data->img.exit = malloc(2 * sizeof(mlx_image_t));
	textura = mlx_load_png("./assets/img/closed-portal.png");
	data->img.exit[0] = mlx_texture_to_image(data->mlx, textura);
	textura = mlx_load_png("./assets/img/open-portal.png");
	data->img.exit[1] = mlx_texture_to_image(data->mlx, textura);
	mlx_delete_texture(textura);
}

void	delete_img(t_data *data)
{
	mlx_delete_image(data->mlx, data->img.wall);
	mlx_delete_image(data->mlx, data->img.ground);
	mlx_delete_image(data->mlx, data->img.player);
	mlx_delete_image(data->mlx, data->img.key);
	mlx_delete_image(data->mlx, *data->img.exit);
}
