/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabid <mabid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:39:52 by mabid             #+#    #+#             */
/*   Updated: 2023/01/20 19:38:50 by shammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <errno.h>
# include <math.h>
# include <string.h>
# include "parse.h"

typedef struct s_coord
{
	double		x;
	double		y;
}				t_coord;

typedef struct s_color
{
	int			r;
	int			g;
	int			b;
	int			status;
}				t_color;

typedef struct s_play
{
	t_coord		pos;
	t_coord		dir;
	int			status;
	t_coord		plane;
	int			pos_x;
	int			pos_y;
	char		dir_pers;
	int			dir_x_pers;
	int			dire_y_pers;
}				t_play;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		height;
	int		width;
	int		endian;
	int		line;
	int		status;
}				t_img;

typedef struct s_ray
{
	t_coord		dir;
	t_coord		map;
	int			mapx;
	int			mapy;
	t_coord		delta_dist;
	t_coord		side_dist;
	t_coord		cam;
	int			hit;
	int			stepx;
	int			stepy;
	int			side;
	double		wall_dist;
	int			line_height;
	int			wall_start;
	int			wall_end;
	double		wall_x;
}				t_ray;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;

	char	*line;
	int		fd;
	char	**map;
	char	**map3;
	int		width;
	int		exit;
	int		key_w;
	int		key_s;
	int		key_d;
	int		key_a;
	int		key_l;
	int		key_r;
	int		status;
	int		status_fc;
	int		lenght;
	t_ray	ray;
	t_img	north;
	t_img	south;
	t_img	west;
	t_img	east;
	t_img	tx;
	t_color	floor;
	t_color	ceiling;
	t_play	player;
}	t_data;

#endif
