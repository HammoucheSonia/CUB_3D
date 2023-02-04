/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morikumo <morikumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:32:25 by mabid             #+#    #+#             */
/*   Updated: 2023/01/26 12:50:33 by shammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "option.h"

void	return_get_opt(char *line, char **tmp, t_data *data)
{
	if (line)
	{
		free(line);
		line = NULL;
	}
	free_tab(tmp);
	if (data->line)
	{
		free(data->line);
		data->line = NULL;
	}
	exit_opt(data, "Error\n Already load\n");
}

void	get_opt_exit(int res, t_data *data, char *line, char **tmp)
{
	if (res == -1)
	{
		free(line);
		free_tab(tmp);
		exit_opt(data, "Error\n texture\n");
	}
}

/**
 * @brief 	printf("tmp%s\n", tmp[0]); pour voir la map a ajouter avant le if
 * 			
 * 
 * @param data 
 * @param tmp 
 * @param res 
 * @param line 
 * @return int 
 */

int	if_opt_suite(t_data *data, char **tmp, int res, char *line)
{
	if (!ft_strncmp(tmp[0], "EA", 3))
	{
		res = get_texture(data, tmp[1], &data->east);
		get_opt_exit(res, data, line, tmp);
	}
	else if (!ft_strncmp(tmp[0], "F", 2))
	{
		res = take_rgb(&data->floor, tmp[1], data);
		get_opt_exit(res, data, line, tmp);
	}
	else if (!ft_strncmp(tmp[0], "C", 2))
	{
		res = take_rgb(&data->ceiling, tmp[1], data);
		get_opt_exit(res, data, line, tmp);
	}
	return (res);
}

int	if_opt(t_data *data, char **tmp, int res, char *line)
{
	if (!ft_strncmp(tmp[0], "NO", 3))
	{
		res = get_texture(data, tmp[1], &data->north);
		get_opt_exit(res, data, line, tmp);
	}
	else if (!ft_strncmp(tmp[0], "SO", 3))
	{	
		res = get_texture(data, tmp[1], &data->south);
		get_opt_exit(res, data, line, tmp);
	}
	else if (!ft_strncmp(tmp[0], "WE", 3))
	{
		res = get_texture(data, tmp[1], &data->west);
		get_opt_exit(res, data, line, tmp);
	}
	else
		return (if_opt_suite(data, tmp, res, line));
	return (res);
}

int	get_opt(t_data *data, char *line, int res)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = NULL;
	tmp = ft_split(line, ' ');
	if (!tmp)
		exit_opt(data, "Error\n, Malloc failed");
	res = if_opt(data, tmp, res, line);
	while (tmp[i])
	{
		if (i > ft_strlen(line))
		{
			free(line);
			free_tab(tmp);
			exit_opt(data, "Error\n bad arg\n");
		}
		i++;
	}
	if (res == 2)
		return_get_opt(line, tmp, data);
	free_tab(tmp);
	return (res);
}
