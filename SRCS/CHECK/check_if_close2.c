/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_close2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morikumo <morikumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:00:26 by shammouc          #+#    #+#             */
/*   Updated: 2023/01/22 15:56:09 by morikumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

static int	verif_map2_0(t_data *data, int i, int j)
{
	int	y;

	y = data->width;
	if (j >= 1)
	{
		if (data->map3[i + 1][j] != '3' && data->map3[i + 1][j - 1] != '3')
		{
			if (data->map3[i + 1][j] == '0' || data->map3[i + 1][j - 1] == '0')
				return (0);
		}
	}
	if ((j + 1) < (y - 1))
	{
		if (data->map3[i + 1][j + 1] != '3')
		{
			if (data->map3[i + 1][j + 1] == '0')
				return (0);
		}
	}
	return (1);
}

static int	verif_map2_1(t_data *data, int i, int j)
{
	int	y;

	y = data->width;
	if ((data->map3[i - 1][j] != '3' && data->map3[i - 1][j - 1] != '3'))
	{
		if (data->map3[i - 1][j] == '0' || data->map3[i - 1][j - 1] == '0')
			return (0);
	}
	if ((j + 1) < (y - 1))
	{
		if (data->map3[i - 1][j + 1] != '3')
		{
			if (data->map3[i - 1][j + 1] == '0')
				return (0);
		}
	}
	return (1);
}

static int	verif_map2(t_data *data, int i, int j)
{
	int	x;

	x = data->lenght;
	if (i >= 1)
	{
		if (verif_map2_1(data, i, j) == 0)
			return (0);
	}
	if ((i + 1) < (x - 1))
	{
		if (verif_map2_0(data, i, j) == 0)
			return (0);
	}
	return (1);
}

static int	verif_map(t_data *data, int i, int j)
{
	if (j + 1 < data->lenght)
		if (data->map3[i][j + 1] != '3' && data->map3[i][j + 1] != '1')
			return (0);
	if (j - 1 >= 0)
		if (data->map3[i][j - 1] != '3' && data->map3[i][j - 1] != '1')
			return (0);
	return (1);
}

int	check_close(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->lenght)
	{
		while (data->map3[i][j])
		{
			if (data->map3[i][j] == '3')
				if (verif_map(data, i, j) == 0
					|| verif_map2(data, i, j) == 0)
					return (0);
			j++;
		}
		j = 0;
		i++;
	}
	i--;
	return (1);
}
