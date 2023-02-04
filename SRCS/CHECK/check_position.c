/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabid <mabid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:37:18 by mabid             #+#    #+#             */
/*   Updated: 2023/01/10 19:03:31 by mabid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

/**
 * @brief Defini la psotion du joueur sur la carte
 * 
 * @param data 
 */
void	get_first_position(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	if (!data->map3)
		return ;
	while (i <= data->lenght - 1)
	{
		j = 0;
		while (j <= data->width - 1)
		{
			if (data->map3[i][j] && (data->map3[i][j] == 'N' || \
			data->map3[i][j] == 'S' || data->map3[i][j] == 'E' || \
			data->map3[i][j] == 'W'))
			{
				data->player.pos_x = i;
				data->player.pos_y = j;
			}
			j++;
		}
		i++;
	}
}

/**
 * @brief Defini la direction du joueur
 * 
 * @param data 
 */
void	get_first_dir(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (j <= data->lenght - 1)
	{
		i = 0;
		while (i <= data->width - 1)
		{
			if (data->map3[j][i] && (data->map3[j][i] == 'N' || \
			data->map3[j][i] == 'S' || data->map3[j][i] == 'E' || \
			data->map3[j][i] == 'W'))
				data->player.dir_pers = data->map3[j][i];
			i++;
		}
		j++;
	}
}

void	init_pos_dir(t_data *data)
{
	get_first_position(data);
	get_first_dir(data);
	init_player(data, data->player.pos_x, data->player.pos_y, \
	data->player.dir_pers);
}
