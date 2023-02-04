/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_close.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morikumo <morikumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:37:29 by mabid             #+#    #+#             */
/*   Updated: 2023/01/23 17:15:49 by shammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

int	first_lenght(t_data *data)
{
	int	i;

	i = 0;
	while (i <= data->lenght - 1)
	{
		if (data->map3[i][0] && (data->map3[i][0] != '1' && \
		data->map3[i][0] != '3'))
			return (0);
		i++;
	}
	return (1);
}

int	return_x(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	if_check_in_close(t_data *data, int i, int j)
{
	if ((data->map3[i][j] && (data->map3[i][j] == '0' || \
	data->map3[i][j] == 'W' || data->map3[i][j] == 'E' || \
	data->map3[i][j] == 'N' || data->map3[i][j] == 'S')) && \
	((data->map3[i][j + 1] && data->map3[i][j + 1] == '3') || \
	(data->map3[i][j - 1] && data->map3[i][j - 1] == '3') || \
	(data->map3[i + 1][j] && data->map3[i + 1][j] == '3') || \
	(data->map3[i - 1][j] && data->map3[i - 1][j] == '3')))
		return (0);
	else if (((data->map3[i][j] && (data->map3[i][j] == '0' || \
	data->map3[i][j] == 'W' || data->map3[i][j] == 'E' || \
	data->map3[i][j] == 'N' || data->map3[i][j] == 'S')) && \
	((!data->map3[i][j + 1]) || (!data->map3[i][j - 1]) || \
	(!data->map3[i + 1][j]) || (!data->map3[i - 1][j]))))
		return (0);
	return (1);
}

/**
 * @brief Verifie la premiere ligne si elle a bien des 1 ou des 3 
 * (3 es l'equivalent des espace qui est changer par strdup 3)
 * Puis verifie dans la carte si nous avons bien les element 0 et 1 et\ou 
 * si sur la ligne on a W, E, N, S qui designera le personnage
 * @param data 
 * @return int 
 */
int	check_ligne(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->width)
	{
		if (data->map3[0][i] != '3' && data->map3[0][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_if_is_close(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	if (!first_lenght(data) || !check_ligne(data))
		return (0);
	while (i <= data->lenght - 1)
	{
		j = 0;
		while (j <= data->width - 1)
		{
			if (!if_check_in_close(data, i, j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
