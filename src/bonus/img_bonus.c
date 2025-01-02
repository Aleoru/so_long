/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 18:03:57 by aoropeza          #+#    #+#             */
/*   Updated: 2022/09/07 17:57:52 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

void	init_img(t_data *data)
{
	mlx_texture_t	*textura;

	textura = mlx_load_png("./assets/img/brick-wall-v2.png");
	data->img.wall = mlx_texture_to_image(data->mlx, textura);
	textura = mlx_load_png("./assets/img/ground.png");
	data->img.ground = mlx_texture_to_image(data->mlx, textura);
	textura = mlx_load_png("./assets/img/key.png");
	data->img.key = mlx_texture_to_image(data->mlx, textura);
	mlx_delete_texture(textura);
}

void	init_sprite(t_data *data)
{
	mlx_texture_t	*textura;

	data->img.exit = malloc(4 * sizeof(mlx_image_t));
	textura = mlx_load_png("./assets/img/closed-portal.png");
	data->img.exit[0] = mlx_texture_to_image(data->mlx, textura);
	textura = mlx_load_png("./assets/img/closed-portal1.png");
	data->img.exit[1] = mlx_texture_to_image(data->mlx, textura);
	textura = mlx_load_png("./assets/img/open-portal.png");
	data->img.exit[2] = mlx_texture_to_image(data->mlx, textura);
	textura = mlx_load_png("./assets/img/open-portal1.png");
	data->img.exit[3] = mlx_texture_to_image(data->mlx, textura);
	data->img.enemy = malloc(2 * sizeof(mlx_image_t));
	textura = mlx_load_png("./assets/img/shadow1.png");
	data->img.enemy[0] = mlx_texture_to_image(data->mlx, textura);
	textura = mlx_load_png("./assets/img/shadow2.png");
	data->img.enemy[1] = mlx_texture_to_image(data->mlx, textura);
	mlx_delete_texture(textura);
}

void	init_player_sprite(t_data *data)
{
	mlx_texture_t	*textura;

	data->img.player = malloc(8 * sizeof(mlx_image_t));
	textura = mlx_load_png("./assets/img/hooman1.png");
	data->img.player[0] = mlx_texture_to_image(data->mlx, textura);
	textura = mlx_load_png("./assets/img/hooman2.png");
	data->img.player[1] = mlx_texture_to_image(data->mlx, textura);
	textura = mlx_load_png("./assets/img/hooman3.png");
	data->img.player[2] = mlx_texture_to_image(data->mlx, textura);
	textura = mlx_load_png("./assets/img/hooman4.png");
	data->img.player[3] = mlx_texture_to_image(data->mlx, textura);
	textura = mlx_load_png("./assets/img/hooman5.png");
	data->img.player[4] = mlx_texture_to_image(data->mlx, textura);
	textura = mlx_load_png("./assets/img/hooman6.png");
	data->img.player[5] = mlx_texture_to_image(data->mlx, textura);
	textura = mlx_load_png("./assets/img/hooman7.png");
	data->img.player[6] = mlx_texture_to_image(data->mlx, textura);
	textura = mlx_load_png("./assets/img/hooman8.png");
	data->img.player[7] = mlx_texture_to_image(data->mlx, textura);
	mlx_delete_texture(textura);
}

void	delete_img(t_data *data)
{
	mlx_delete_image(data->mlx, data->img.wall);
	mlx_delete_image(data->mlx, data->img.ground);
	mlx_delete_image(data->mlx, data->img.player[0]);
	mlx_delete_image(data->mlx, data->img.player[1]);
	mlx_delete_image(data->mlx, data->img.player[2]);
	mlx_delete_image(data->mlx, data->img.player[3]);
	mlx_delete_image(data->mlx, data->img.player[4]);
	mlx_delete_image(data->mlx, data->img.player[5]);
	mlx_delete_image(data->mlx, data->img.player[6]);
	mlx_delete_image(data->mlx, data->img.player[7]);
	mlx_delete_image(data->mlx, data->img.key);
	mlx_delete_image(data->mlx, data->img.exit[0]);
	mlx_delete_image(data->mlx, data->img.exit[1]);
	mlx_delete_image(data->mlx, data->img.exit[2]);
	mlx_delete_image(data->mlx, data->img.exit[3]);
	mlx_delete_image(data->mlx, data->img.enemy[0]);
	mlx_delete_image(data->mlx, data->img.enemy[1]);
}
