/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabid <mabid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:59:37 by mabid             #+#    #+#             */
/*   Updated: 2023/01/13 19:22:38 by mabid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	init_display(t_data *data)
{
	data->tx.img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!data->tx.img)
		exit_opt(data, "Error\nInit display\n");
	data->tx.addr = mlx_get_data_addr(data->tx.img, &data->tx.bpp,
			&data->tx.line, &data->tx.endian);
	if (!data->tx.addr)
		exit_opt(data, "Error\nInit display\n");
}
