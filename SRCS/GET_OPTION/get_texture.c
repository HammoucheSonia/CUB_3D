/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morikumo <morikumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:34:01 by mabid             #+#    #+#             */
/*   Updated: 2023/01/26 12:43:03 by shammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "option.h"

int	check_status_tx(t_data *data)
{
	if (data->north.status == 1 && data->south.status == 1 && \
	data->west.status == 1 && data->east.status == 1)
		return (1);
	return (0);
}

int	if_not_tmp(char **tmp, int i)
{
	if (!tmp[i])
	{
		free_tab(tmp);
		return (-1);
	}
	return (0);
}

/**
 * @brief Va split a chaque , pour recuperer chaque valeur numerique pour
 *  la couleur ici res est un tableau de 3 pour recuperer les 3 aspect rgb
 * Et doit etre compris entre 0 et 255
 * 
 * @param s_key 
 * @param line 
 * @param data 
 * @return int 
 */

void	verif_tmp(char **tmp, t_data *data)
{
	if (!tmp)
		exit_opt(data, "Error\n Malloc failed\n");
}

int	take_rgb(t_color *s_key, char *line, t_data *data)
{
	int		i;
	int		res[3];
	char	**tmp;

	i = -1;
	bzero(res, sizeof(res));
	if (s_key->status == 1)
		return (2);
	tmp = ft_split(line, ',');
	verif_tmp(tmp, data);
	while (++i < 3)
	{
		if (if_not_tmp(tmp, i) == -1)
			return (-1);
		res[i] = ft_atol(tmp[i], tmp);
		if (res[i] == -1)
			return (-1);
	}
	if (add_rgb(res, s_key) == -1)
	{
		free_tab(tmp);
		return (-1);
	}
	free_tab(tmp);
	return (1);
}

/**
 * @brief Recupere les images pour les direction NO SO WE EA
 * 	printf("Path: %s\n",path); pour recuperer le path a mettre apres le 1er if
 * @param data 
 * @param path 
 * @param img 
 * @return int 
 */
int	get_texture(t_data *data, char *path, t_img *img)
{
	int	i;

	i = 0;
	if (img->status == 1)
		return (2);
	while (path[i])
	{
		if (ft_isspace(path[i]))
		{
			path[i] = '\0';
			break ;
		}
		i++;
	}
	img->img = mlx_xpm_file_to_image(data->mlx, path, \
	&img->width, &img->height);
	if (!img->img)
		return (-1);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, \
	&img->line, &img->endian);
	if (!img->addr)
		return (-1);
	img->status = 1;
	return (1);
}
