/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:21:23 by aoropeza          #+#    #+#             */
/*   Updated: 2022/09/07 17:58:34 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

/*********************/
/* 		MAIN		 */
/*********************/

static void	timer(void *param)
{
	t_data		*data;

	data = param;
	data->timer++;
	data->enemy_t++;
	data->key_t++;
	data->portal_t++;
	if (data->enemy_t >= 30)
		enemy_movement(data, &data->level);
	if (data->portal < 2 && data->portal_t >= 30)
		portal_close(data);
	else if (data->portal >= 2 && data->portal_t >= 30)
		portal_open(data);
}

static void	animation(void *param)
{
	t_data	*data;
	int		i;

	data = param;
	i = -1;
	if (data->img.player[2]->instances->enabled == true
		|| data->img.player[3]->instances->enabled == true
		|| data->img.player[6]->instances->enabled == true
		|| data->img.player[7]->instances->enabled == true)
	{
		if (data->timer < 40)
			return ;
		while (++i < 8)
			data->img.player[i]->instances->enabled = false;
		if (data->dir == 1)
			data->img.player[0]->instances->enabled = true;
		else if (data->dir == 0)
			data->img.player[4]->instances->enabled = true;
		data->timer = 0;
	}
	if (data->dir == 1)
		iddle_right(data);
	if (data->dir == 0)
		iddle_left(data);
}

void	exit_error(t_data *data, int error)
{
	if (error == 1)
		ft_printf("\e[31mError\nMap extension is not valid\e[0m\n");
	if (error == 2)
		ft_printf("\e[31mError\nMap is not rectangular\e[0m\n");
	if (error == 3)
		ft_printf("\e[31mError\nMap is not surronded by walls\e[0m\n");
	if (error == 4)
		ft_printf("\e[31mError\nMissing elements on the map\e[0m\n");
	if (error == 5)
		ft_printf("\e[31mError\nThere can only be one player on the map\e[0m\n");
	if (error == 6)
		ft_printf("\e[31mError\nFailed to open file\e[0m\n");
	if (error == 7)
		ft_printf("\e[31mError\nUnknown character in map\e[0m\n");
	close_game(data, error);
}

void	close_game(t_data *data, int error)
{
	if (error != 0)
		exit(EXIT_FAILURE);
	delete_img(data);
	mlx_terminate(data->mlx);
	exit(EXIT_SUCCESS);
}

int32_t	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2)
	{
		ft_bzero(&data, sizeof(t_data));
		init(&data, argv[1]);
		mlx_key_hook(data.mlx, &movement, &data);
		mlx_loop_hook(data.mlx, &timer, &data);
		mlx_loop_hook(data.mlx, &animation, &data);
		mlx_loop_hook(data.mlx, &key_animation, &data);
		mlx_loop(data.mlx);
		delete_img(&data);
		mlx_terminate(data.mlx);
	}
	else if (argc < 2)
		ft_printf("\e[31mError\nArguments missing\e[0m\n");
	else if (argc > 2)
		ft_printf("\e[31mError\nOne ore more arguments are left over\e[0m\n");
	return (EXIT_SUCCESS);
}
