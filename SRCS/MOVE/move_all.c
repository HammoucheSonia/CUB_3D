/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabid <mabid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:31:58 by mabid             #+#    #+#             */
/*   Updated: 2023/01/13 19:41:48 by mabid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "move.h"

/**
 * @brief Fonction pour lorsque l'on ferme la fenetre
 * 
 * @param data 
 * @return int 
 */
int	mouse_hook(t_data *data)
{
	if (data->map3)
		free_map3(data);
	if (data->map)
		free_map(data);
	exit_opt(data, "Done \n");
	return (0);
}

/**
 * @brief Processus pour lorsque j'appuie echap
 * 
 * @param data 
 */
void	esc(t_data *data)
{
	if (data->map3)
		free_map3(data);
	if (data->map)
		free_map(data);
	exit_opt(data, "Done \n");
}

/**
 * @brief Keypress pour actionner les commande lorsque j'appuie sur une touche
 * 
 * @param keycode 
 * @param data 
 * @return int 
 */
int	key_press(int keycode, t_data *data)
{
	if (keycode == ESC)
		esc(data);
	else if (keycode == W)
		data->key_w = 1;
	else if (keycode == S)
		data->key_s = 1;
	else if (keycode == D)
		data->key_d = 1;
	else if (keycode == A)
		data->key_a = 1;
	else if (keycode == RIGHT)
		data->key_r = 1;
	else if (keycode == LEFT)
		data->key_l = 1;
	return (0);
}

/**
 * @brief KeyRelease c'est lorsque l'on retire le doigt de la touche 
 * 
 * @param keycode 
 * @param data 
 * @return int 
 */
int	key_release(int keycode, t_data *data)
{
	if (keycode == W)
		data->key_w = 0;
	else if (keycode == S)
		data->key_s = 0;
	else if (keycode == D)
		data->key_d = 0;
	else if (keycode == A)
		data->key_a = 0;
	else if (keycode == RIGHT)
		data->key_r = 0;
	else if (keycode == LEFT)
		data->key_l = 0;
	return (0);
}
