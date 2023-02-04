/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabid <mabid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:58:09 by mabid             #+#    #+#             */
/*   Updated: 2023/01/13 19:48:32 by mabid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "parse.h"

void	init_display(t_data *data);
void	put_in_display(t_data *data, int x);
int		draw(t_data *data);

#endif