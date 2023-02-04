/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabid <mabid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:09:28 by mabid             #+#    #+#             */
/*   Updated: 2023/01/11 16:28:36 by mabid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_ALL_H
# define INIT_ALL_H

# include "parse.h"

void	init_win(t_data *data);
void	init_data(t_data *data);
void	init_img(t_data *data);
void	init_ray(t_data *data);
int		loop_raycast(t_data *data);

#endif