/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_wasd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabid <mabid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:42:27 by mabid             #+#    #+#             */
/*   Updated: 2023/01/13 19:42:28 by mabid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "move.h"

/**
 * @brief Les mouvements sont fait a travers les position, les murs et
 * 		la vitesse des mouvements
 * 		Raycaster_flat 208 a 239
 * 
 * @param data 
 * @param player 
 */
void	move_w(t_data *data, t_play *player)
{
	if (data->map3[(int)(player->pos.x + player->dir.x * \
	SPEED)][(int)(player->pos.y)] == '0' || \
	data->map3[(int)(player->pos.x + player->dir.x * \
	SPEED)][(int)(player->pos.y)] == data->player.dir_pers)
		player->pos.x += player->dir.x * SPEED;
	if (data->map3[(int)(player->pos.x)][(int)(player->pos.y + player->dir.y * \
	SPEED)] == '0' || data->map3[(int)(player->pos.x)][(int)(player->pos.y + \
	player->dir.y * SPEED)] == data->player.dir_pers)
		player->pos.y += player->dir.y * SPEED;
}

void	move_s(t_data *data, t_play *player)
{
	if (data->map3[(int)(player->pos.x - player->dir.x * \
	SPEED)][(int)(player->pos.y)] == '0' || \
	data->map3[(int)(player->pos.x - \
	player->dir.x * SPEED)][(int)(player->pos.y)] == data->player.dir_pers)
		player->pos.x -= player->dir.x * SPEED;
	if (data->map3[(int)(player->pos.x)][(int)(player->pos.y - player->dir.y * \
	SPEED)] == '0' || data->map3[(int)(player->pos.x)][(int)(player->pos.y - \
	player->dir.y * SPEED)] == data->player.dir_pers)
		player->pos.y -= player->dir.y * SPEED;
}

void	move_d(t_data *data, t_play *player)
{
	if (data->map3[(int)(player->pos.x + player->plane.x * \
	SPEED)][(int)(player->pos.y)] == '0' || data->map3[(int)(player->pos.x + \
	player->plane.x * SPEED)][(int)(player->pos.y)] == data->player.dir_pers)
		player->pos.x += player->plane.x * SPEED;
	if (data->map3[(int)(player->pos.x)][(int)(player->pos.y + \
	player->plane.y * SPEED)] == '0' || \
	data->map3[(int)(player->pos.x)][(int)(player->pos.y + \
	player->plane.y * SPEED)] == data->player.dir_pers)
		player->pos.y += player->plane.y * SPEED;
}

void	move_a(t_data *data, t_play *player)
{
	if (data->map3[(int)(player->pos.x - player->plane.x * \
	SPEED)][(int)(player->pos.y)] == '0' || data->map3[(int)(player->pos.x - \
	player->plane.x * SPEED)][(int)(player->pos.y)] == data->player.dir_pers)
		player->pos.x += -(player->plane.x * SPEED);
	if (data->map3[(int)(player->pos.x)][(int)(player->pos.y - \
	player->plane.y * SPEED)] == '0' || \
	data->map3[(int)(player->pos.x)][(int)(player->pos.y - \
	player->plane.y * SPEED)] == data->player.dir_pers)
		player->pos.y += -(player->plane.y * SPEED);
}

int	key_hook(t_data *data)
{
	if (data->key_w == 1)
		move_w(data, &data->player);
	if (data->key_s == 1)
		move_s(data, &data->player);
	if (data->key_d == 1)
		move_d(data, &data->player);
	if (data->key_a == 1)
		move_a(data, &data->player);
	if (data->key_r == 1)
		rot_right(data);
	if (data->key_l == 1)
		rot_left(data);
	if (data->key_w == 0 && data->key_s == 0
		&& data->key_l == 0 && data->key_r == 0
		&& data->key_a == 0 && data->key_d == 0)
		return (0);
	return (1);
}
