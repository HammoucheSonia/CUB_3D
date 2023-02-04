/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_play.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabid <mabid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:03:30 by mabid             #+#    #+#             */
/*   Updated: 2023/01/13 19:40:43 by mabid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_all.h"

/**
 * @brief Set the plane object
 * 			Va set la direction de la camera
 * 
 * @param data 
 * @param dx 
 * @param dy 
 */
void	set_plane(t_data *data, double dx, double dy)
{
	data->player.plane.x = dx;
	data->player.plane.y = dy;
}

/**
 * @brief Set the dir object
 *		Et va set la direction du personnage 
 * @param data 
 * @param x 
 * @param y 
 */
void	set_dir(t_data *data, double x, double y)
{
	data->player.dir.x = x;
	data->player.dir.y = y;
}

void	west_east(t_data *data, char dir)
{
	if (dir == 'E')
	{
		set_dir(data, 0, 1);
		set_plane(data, 0.66, 0);
	}
	else if (dir == 'W')
	{	
		set_dir(data, 0, -1);
		set_plane(data, -0.66, 0);
	}
}

void	init_player(t_data *data, int h, int w, char dir)
{
	if (dir == 'N')
	{
		set_dir(data, -1, 0);
		set_plane(data, 0, 0.66);
	}
	else if (dir == 'S')
	{
		set_dir(data, 1, 0);
		set_plane(data, 0, -0.66);
	}
	else if (dir == 'E' || dir == 'W')
		west_east(data, dir);
	data->player.pos.x = h + 0.5;
	data->player.pos.y = w + 0.5;
}
