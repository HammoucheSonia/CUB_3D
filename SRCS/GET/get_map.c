/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabid <mabid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:12:13 by mabid             #+#    #+#             */
/*   Updated: 2023/01/23 18:06:21 by mabid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get.h"

/**
 * @brief Initialise et verifie si la map est bien recuperable (si le fichier 
 * existe, les droits ect...)
 * 
 * @param data 
 * @param av 
 * @return int 
 */
int	check_init_get_map(t_data *data, char **av)
{
	init_data(data);
	init_win(data);
	init_img(data);
	data->fd = check_fd(av[1]);
	if (data->fd == -1)
		exit_opt(data, NULL);
	data->line = ft_strdup("");
	if (!data->line)
		return (0);
	return (1);
}

/**
 * @brief Va verifier si la derniere ligne est bien que des 1
 * 		Si il n'y a pas de doublous joueur et si les taille sont conformes 
 * 		Pour bien fermer
 * 
 * @param data 
 * @return int 
 */
int	end_get_map(t_data *data)
{
	close(data->fd);
	data->map = ft_split(data->line, '\n');
	if (data->line)
	{
		free(data->line);
		data->line = NULL;
	}
	if (!data->map)
		return (0);
	data->width = size_width(data);
	data->lenght = size_lenght(data);
	if (!check_letter(data) || \
	!check_duplicate_position(data) || \
	ft_stronly("1", data->map[data->lenght - 1]) == 0)
	{
		printf("Error\n");
		free_map(data);
		exit_opt(data, NULL);
	}
	return (1);
}

/**
 * @brief Verifie la map par la chaine de charactere tmp
 * 
 * @param tmp 
 * @param data 
 * @param res 
 * @return char* 
 */

char	*check_tmp_in_get_map(char *tmp, t_data *data, int *res)
{
	int	nb;

	(void) res;
	nb = 0;
	if (data->status == 0 && (check_temp(tmp) == 1))
		free_tmp(tmp);
	else if (check_temp(tmp) == 0 || data->status == 1)
	{
		tmp = ft_strjoinfree(tmp, "\n", 1);
		nb = count(tmp);
		if (nb > 2)
		{
			free(tmp);
			exit_opt(data, "Error\n texture");
		}
		*res = get_opt(data, tmp, 0);
		if (*res != 1)
		{
			data->line = ft_strjoinfree(data->line, tmp, 1);
			data->status = 1;
		}
		free_tmp(tmp);
	}
	return (tmp);
}
/**
 * @brief On recupere la map ilgne par ligne
 * 
 * @param data 
 * @param av 
 * @return int 
 */

int	get_map(t_data *data, char **av)
{
	int		res;
	char	*tmp;

	tmp = NULL;
	res = 0;
	data->status = 0;
	if (check_init_get_map(data, av) == 0)
		return (0);
	tmp = get_next_line(data->fd);
	while (tmp && res != -1)
	{
		tmp = check_tmp_in_get_map(tmp, data, &res);
		tmp = get_next_line(data->fd);
	}
	if (tmp)
	{
		free(tmp);
		tmp = NULL;
	}
	return (end_get_map(data));
}
