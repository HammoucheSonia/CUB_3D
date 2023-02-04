/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabid <mabid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:00:32 by mabid             #+#    #+#             */
/*   Updated: 2023/01/13 19:52:09 by mabid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_H
# define MOVE_H
# include "parse.h"

# define SPEED 0.1
# define ROT_SPEED 0.07

# define ESC	65307
# define W 119// UP
# define A 97// LEFT
# define S 115// DOWN
# define D 100// RIGHT
# define LEFT 65361
# define RIGHT 65363

# define Q 113// LEFT for azerty
# define Z 122// UP for azerty

void	init_player(t_data *data, int h, int w, char dir);
void	rot_left(t_data *data);
void	rot_right(t_data *data);
int		key_press(int keycode, t_data *data);
int		key_release(int keycode, t_data *data);
int		mouse_hook(t_data *data);
int		key_hook(t_data *data);

#endif