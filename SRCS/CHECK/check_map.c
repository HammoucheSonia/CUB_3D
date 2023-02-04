/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabid <mabid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:37:27 by mabid             #+#    #+#             */
/*   Updated: 2023/01/13 17:58:22 by mabid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

int	check_letter_error(t_data *data)
{
	free_map(data);
	exit_opt(data, "Error \n use of wrong character\n");
	return (0);
}

/**
 * @brief verifie si les caractere sur la map est bien un l'un des caractere 
 * 			Si dessous.
 * 
 * @param data 
 * @return int 
 */
int	check_letter(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	if (!data->map)
		return (0);
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] && (data->map[j][i] != '0' && \
			data->map[j][i] != '1' && data->map[j][i] != 'N' && \
			data->map[j][i] != 'S' && data->map[j][i] != 'E' && \
			data->map[j][i] != 'W' && data->map[j][i] != ' '))
				return (check_letter_error(data));
			i++;
		}
		j++;
	}
	return (1);
}

int	if_status0(int status)
{
	if (status == 0)
	{
		printf("%s\n", "Error \n It's missing a position point\n");
		return (0);
	}
	return (1);
}

int	if_status1(void)
{
	printf("%s\n", "Error \n multiple position point\n");
	return (0);
}

/**
 * @brief Verifie si l'on a bien un ou plusieurs N, S, E, W sur la map
 * 
 * @param data 
 * @return int 
 */
int	check_duplicate_position(t_data *data)
{
	int	i;
	int	j;
	int	status;

	j = 0;
	status = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] && (data->map[j][i] == 'N' || \
			data->map[j][i] == 'S' || data->map[j][i] == 'E' || \
			data->map[j][i] == 'W'))
			{
				if (status >= 1)
					return (if_status1());
				status++;
			}
			i++;
		}
		j++;
	}
	return (if_status0(status));
}
