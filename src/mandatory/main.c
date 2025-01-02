/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:21:23 by aoropeza          #+#    #+#             */
/*   Updated: 2022/08/15 17:30:30 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

/*********************/
/* 		MAIN		 */
/*********************/

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
		init_map(&data, &data.level, argv[1]);
		data.img_size = 64;
		data.mlx = mlx_init(data.img_size * data.level.size_x, data.img_size
				* data.level.size_y, "SO_LONG", true);
		if (!data.mlx)
			exit(EXIT_FAILURE);
		init_vector(&data.vector);
		init_img(&data);
		create_map(&data, data.img_size, data.img);
		mlx_key_hook(data.mlx, &movement, &data);
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
