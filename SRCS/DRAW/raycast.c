/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabid <mabid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:30:45 by mabid             #+#    #+#             */
/*   Updated: 2023/01/14 15:37:47 by mabid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

/**
 * @brief Calcul du mur au personnage
 * 		la distance est renvoyer par les coordonnées du joueur
 * 			et les coordonnées du mur
 * 		Raycasting
 * 
 * @param data 
 */
void	wall_dist(t_data *data)
{
	if (data->ray.side == WE || data->ray.side == EA)
		data->ray.wall_dist = (data->ray.mapx - data->player.pos.x
				+ (1 - data->ray.stepx) / 2) / data->ray.dir.x;
	else if (data->ray.side == NO || data->ray.side == SO)
		data->ray.wall_dist = (data->ray.mapy - data->player.pos.y
				+ (1 - data->ray.stepy) / 2) / data->ray.dir.y;
	data->ray.line_height = (int)(WIN_HEIGHT / data->ray.wall_dist);
	data->ray.wall_start = -data->ray.line_height / 2 + WIN_HEIGHT / 2;
	data->ray.wall_end = data->ray.line_height / 2 + WIN_HEIGHT / 2;
	if (data->ray.side == 2 || data->ray.side == 3)
		data->ray.wall_x = data->player.pos.y + data->ray.wall_dist
			* data->ray.dir.y;
	else
		data->ray.wall_x = data->player.pos.x + data->ray.wall_dist
			* data->ray.dir.x;
	data->ray.wall_x -= floor(data->ray.wall_x);
}

/**
 * @brief Calcul de la distance entre le joueur et le mur de case a case
 * 		A la fin on verifie si le mur est toucher
 * 		Raycasting_flat.cpp ligne 142 a 159
 * 
 * @param data 
 */
void	loop_hit(t_data *data)
{
	while (data->ray.hit == 0)
	{
		if (data->ray.side_dist.x < data->ray.side_dist.y)
		{
			data->ray.side_dist.x += data->ray.delta_dist.x;
			data->ray.mapx += data->ray.stepx;
			if (data->ray.dir.x > 0)
				data->ray.side = EA;
			else
				data->ray.side = WE;
		}
		else
		{
			data->ray.side_dist.y += data->ray.delta_dist.y;
			data->ray.mapy += data->ray.stepy;
			if (data->ray.dir.y > 0)
				data->ray.side = SO;
			else
				data->ray.side = NO;
		}
		if (data->map3[data->ray.mapx][data->ray.mapy] == '1')
			data->ray.hit = 1;
	}
}

/**
 * @brief Calcul de coordonner du rayon
 * 		En fonction de la position
 * 		Raycaster_flat.cpp ligne 121 a 140
 * 
 * @param data 
 */
void	calcul_raydis(t_data *data)
{
	if (data->ray.dir.x < 0)
	{
		data->ray.stepx = -1;
		data->ray.side_dist.x = (data->player.pos.x - data->ray.mapx)
			* data->ray.delta_dist.x;
	}
	else
	{
		data->ray.stepx = 1;
		data->ray.side_dist.x = (data->ray.mapx + 1.0 - data->player.pos.x)
			* data->ray.delta_dist.x;
	}
	if (data->ray.dir.y < 0)
	{
		data->ray.stepy = -1;
		data->ray.side_dist.y = (data->player.pos.y - data->ray.mapy)
			* data->ray.delta_dist.y;
	}
	else
	{
		data->ray.stepy = 1;
		data->ray.side_dist.y = (data->ray.mapy + 1.0 - data->player.pos.y)
			* data->ray.delta_dist.y;
	}
}

/**
 * @brief Va dessiner la carte avec le principe du raycasting
 * 		Raycasting_flat.cpp ligne 84 a 110
 * 
 * @param data 
 * @return int 
 */
int	draw(t_data *data)
{
	int	x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		data->ray.hit = 0;
		data->ray.cam.x = 2 * x / (double)WIN_WIDTH - 1;
		data->ray.dir.x = data->player.dir.x + data->player.plane.x
			* data->ray.cam.x;
		data->ray.dir.y = data->player.dir.y + data->player.plane.y
			* data->ray.cam.x;
		data->ray.hit = 0;
		data->ray.mapx = (int)data->player.pos.x;
		data->ray.mapy = (int)data->player.pos.y;
		data->ray.delta_dist.x = fabs(1 / data->ray.dir.x);
		data->ray.delta_dist.y = fabs(1 / data->ray.dir.y);
		calcul_raydis(data);
		loop_hit(data);
		wall_dist(data);
		put_in_display(data, x);
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->tx.img, 0, 0);
	return (1);
}
