/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabid <mabid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:41:55 by mabid             #+#    #+#             */
/*   Updated: 2023/01/13 19:42:09 by mabid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "move.h"

/**
 * @brief Calcul en utilisant le raycasting pour la fleche de droite et 
 * permettera de tourner ver la droite
 * 	ici les calcul de sinus et cosinus vont nous aider a deplacer la camera a 
 * une certaine vitesse
 * 
 * @param data 
 */
void	rot_right(t_data *data)
{
	double		old_dirx;
	double		old_planex;

	old_dirx = data->player.dir.x;
	old_planex = data->player.plane.x;
	data->player.dir.x = data->player.dir.x * cos(-ROT_SPEED)
		- data->player.dir.y * sin(-ROT_SPEED);
	data->player.dir.y = old_dirx * sin(-ROT_SPEED)
		+ data->player.dir.y * cos(-ROT_SPEED);
	data->player.plane.x = data->player.plane.x * cos(ROT_SPEED)
		- data->player.plane.y * sin(-ROT_SPEED);
	data->player.plane.y = old_planex * sin(-ROT_SPEED)
		+ data->player.plane.y * cos(-ROT_SPEED);
}

/**
 * @brief Calcul en utilisant le raycasting pour la fleche de gauche et 
 * permettera de tourner ver la gauche
 * 
 * @param data 
 */
void	rot_left(t_data *data)
{
	double		old_dirx;
	double		old_planex;

	old_dirx = data->player.dir.x;
	old_planex = data->player.plane.x;
	data->player.dir.x = data->player.dir.x * cos(ROT_SPEED)
		- data->player.dir.y * sin(ROT_SPEED);
	data->player.dir.y = old_dirx * sin(ROT_SPEED)
		+ data->player.dir.y * cos(ROT_SPEED);
	data->player.plane.x = data->player.plane.x * cos(ROT_SPEED)
		- data->player.plane.y * sin(ROT_SPEED);
	data->player.plane.y = old_planex * sin(ROT_SPEED)
		+ data->player.plane.y * cos(ROT_SPEED);
}
