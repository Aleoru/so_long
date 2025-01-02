/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 20:28:29 by aoropeza          #+#    #+#             */
/*   Updated: 2022/09/07 17:57:25 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

void	iddle_right(t_data *data)
{
	int	time;

	time = 60;
	if (data->blink > 0)
		time = 20;
	if (data->timer != time)
		return ;
	if (data->img.player[0]->instances->enabled == true)
	{
		data->img.player[0]->instances->enabled = false;
		data->img.player[1]->instances->enabled = true;
	}
	else if (data->img.player[1]->instances->enabled == true)
	{
		data->img.player[1]->instances->enabled = false;
		data->img.player[0]->instances->enabled = true;
	}
	data->timer = 0;
	data->blink++;
	if (data->blink > 3)
		data->blink = 0;
}

void	iddle_left(t_data *data)
{
	int	time;

	time = 60;
	if (data->blink > 0)
		time = 20;
	if (data->timer != time)
		return ;
	if (data->img.player[4]->instances->enabled == true)
	{
		data->img.player[4]->instances->enabled = false;
		data->img.player[5]->instances->enabled = true;
	}
	else if (data->img.player[5]->instances->enabled == true)
	{
		data->img.player[5]->instances->enabled = false;
		data->img.player[4]->instances->enabled = true;
	}
	data->timer = 0;
	data->blink++;
	if (data->blink > 3)
		data->blink = 0;
}

void	walk_right(t_data *data)
{
	int	i;

	i = -1;
	if (data->img.player[2]->instances->enabled == true || data->walk == 2)
	{
		while (++i < 8)
			data->img.player[i]->instances->enabled = false;
		data->img.player[3]->instances->enabled = true;
		data->walk = 3;
	}
	else if (data->img.player[3]->instances->enabled == true || data->walk == 3)
	{
		while (++i < 8)
			data->img.player[i]->instances->enabled = false;
		data->img.player[2]->instances->enabled = true;
		data->walk = 2;
	}
	data->blink = 0;
	data->timer = 0;
}

void	walk_left(t_data *data)
{
	int	i;

	i = -1;
	if (data->img.player[6]->instances->enabled == true || data->walk == 6)
	{
		while (++i < 8)
			data->img.player[i]->instances->enabled = false;
		data->img.player[7]->instances->enabled = true;
		data->walk = 7;
	}
	else if (data->img.player[7]->instances->enabled == true || data->walk == 7)
	{
		while (++i < 8)
			data->img.player[i]->instances->enabled = false;
		data->img.player[6]->instances->enabled = true;
		data->walk = 6;
	}
	data->blink = 0;
	data->timer = 0;
}
