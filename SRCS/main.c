/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabid <mabid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:18:14 by mabid             #+#    #+#             */
/*   Updated: 2023/01/23 19:23:19 by mabid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	main(int ac, char **av)
{
	t_data	data;

	check_arg(ac, av);
	data.mlx = NULL;
	data.mlx = mlx_init();
	if (!data.mlx)
		return (0);
	data.map = NULL;
	data.map3 = NULL;
	check_main(ac, av, &data);
	init_ray(&data);
	init_pos_dir(&data);
	mlx_hook(data.win, 17, 1L << 17, mouse_hook, &data);
	mlx_loop_hook(data.mlx, loop_raycast, &data);
	mlx_hook(data.win, 2, 1L << 0, key_press, &data);
	mlx_hook(data.win, 3, 1L << 1, key_release, &data);
	mlx_do_sync(data.mlx);
	mlx_loop(data.mlx);
	free_map(&data);
	return (0);
}
