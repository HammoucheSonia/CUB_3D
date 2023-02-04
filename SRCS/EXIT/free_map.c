/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabid <mabid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:49:13 by mabid             #+#    #+#             */
/*   Updated: 2023/01/06 19:22:18 by mabid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void	free_tab(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}

void	free_tmp(char *tmp)
{
	if (tmp)
	{
		free(tmp);
		tmp = NULL;
	}
}

void	free_map3(t_data *data)
{
	int	i;

	i = 0;
	while (i <= data->lenght - 1)
	{
		free(data->map3[i]);
		i++;
	}
	free(data->map3);
}

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
}
