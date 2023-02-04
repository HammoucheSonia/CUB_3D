/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_to_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabid <mabid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:37:37 by mabid             #+#    #+#             */
/*   Updated: 2023/01/13 17:56:54 by mabid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

/**
 * @brief Check si la line est bien fermer de 1
 * 
 * @param data 
 * @param line 
 * @return int 
 */
int	check_line_close(t_data *data, int line)
{
	int	i;

	i = 0;
	while (data->map[line][i])
	{
		if (data->map[line][i] != '1')
			return (1);
		i++;
	}
	return (0);
}

/**
 * @brief Commence par allouer de la memoire pour la string s2 et la remplie 
 * de '3'Puis dans la seconde boucle si s[i] existe et que c'est different 
 * d'un espace s2[i] est assigner a s[i] enfin si c'est un ' ' il remplace 
 * par le caractere '3'
 * 
 * @param s 
 * @param data 
 * @return char* 
 */
char	*ft_str3dup(char *s, t_data *data)
{
	int		i;
	char	*s2;

	s2 = malloc(sizeof(char) * (data->width + 1));
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (i <= data->width - 1)
	{
		s2[i] = '3';
		i++;
	}
	s2[i] = '\0';
	i = 0;
	while (i <= data->width - 1)
	{
		if (s[i] && s[i] != ' ')
			s2[i] = s[i];
		else if (s[i] == ' ')
			s2[i] = '3';
		else
			return (s2);
		i++;
	}
	return (s2);
}

void	change_space_to_3(t_data *data)
{
	int	i;

	i = -1;
	data->lenght = 0;
	data->map3 = NULL;
	if (!data->map)
		return ;
	while (data->map[data->lenght])
		data->lenght++;
	data->map3 = malloc(sizeof(char *) * data->lenght + 1);
	if (!data->map3)
		return ;
	while (++i < data->lenght)
		data->map3[i] = ft_str3dup(data->map[i], data);
}
