/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 18:52:25 by aoropeza          #+#    #+#             */
/*   Updated: 2022/09/07 17:59:23 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

void	print_text(t_data *data, char *str)
{
	int	x;
	int	y;

	x = data->text_pos.x + 21;
	y = data->text_pos.y + 21;
	mlx_delete_image(data->mlx, data->img.text);
	data->img.text = mlx_put_string(data->mlx, str, x, y);
}

void	win(t_data *data)
{
	ft_printf("\e[32;1mYOU WIN!\e[0m\n");
	close_game(data, data->error);
}
