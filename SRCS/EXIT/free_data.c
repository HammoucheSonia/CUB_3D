/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabid <mabid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:48:52 by mabid             #+#    #+#             */
/*   Updated: 2023/01/13 19:31:47 by mabid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"
#include "../../mlx/mlx.h"

void	free_data(t_data *data)
{
	if (data->fd)
		close (data->fd);
	if (data->map)
	{
		free_map(data);
		data->map = NULL;
	}
	if (data->map3)
	{
		free_map3(data);
		data->map3 = NULL;
	}
}

void	free_img(t_data *data)
{
	if (data->north.img != NULL)
	{
		mlx_destroy_image(data->mlx, data->north.img);
		data->north.img = NULL;
	}
	if (data->south.img != NULL)
	{
		mlx_destroy_image(data->mlx, data->south.img);
		data->south.img = NULL;
	}
	if (data->west.img != NULL)
	{
		mlx_destroy_image(data->mlx, data->west.img);
		data->west.img = NULL;
	}
	if (data->east.img != NULL)
	{
		mlx_destroy_image(data->mlx, data->east.img);
		data->east.img = NULL;
	}
	if (data->tx.img != NULL)
	{
		mlx_destroy_image(data->mlx, data->tx.img);
		data->tx.img = NULL;
	}
}
