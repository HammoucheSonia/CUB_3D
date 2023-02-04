/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabid <mabid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:37:33 by mabid             #+#    #+#             */
/*   Updated: 2023/01/23 18:09:38 by mabid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

void	check_arg(int ac, char **av)
{
	if (ac != 2)
	{
		printf("Error \nnumber of argument\n");
		exit(1);
	}
	if (ft_check_name_map(av[1]) == 0)
	{
		printf("Error \nbad name\n");
		exit(1);
	}
}

void	check_main(int ac, char **av, t_data *data)
{
	if (!check_all(ac, av, data))
		exit_opt(data, "Error\n map\n");
}

/**
 * @brief Va verifier si la map est bien recuperable
 * Si elle a bien au moin 3 ligne et 3 colonne
 * si elle est bein fermer 
 * Et enfin check_status_tx qui va verifier le status des texture des direction
 * (No, so, we, ea), si il est egal a 0 il y a un probleme et on free tout, 
 * il doit etre egal a 1 pour continuer ce n'est qu'apres tout ca 
 * que l'on a fini de check
 * 
 * @param ac 
 * @param av 
 * @param data 
 * @return int 
 */

int	check_all(int ac, char **av, t_data *data)
{
	if (ac != 2)
		return (0);
	else if (!get_map(data, av))
		exit_opt(data, "Error \n when get map\n");
	if (data->width < 3 || data->lenght < 3)
	{
		free_map(data);
		exit_opt(data, "Error \n map to small\n");
	}
	change_space_to_3(data);
	if (!check_if_is_close(data) || !first_lenght(data) || !check_order(av[1]))
	{
		free_map3(data);
		free_map(data);
		exit_opt(data, "Error \n problem in map\n");
	}
	if (!check_status_tx(data))
	{
		free_map3(data);
		free_map(data);
		exit_opt(data, "Error\n One or more textures are missing\n");
	}
	return (1);
}
