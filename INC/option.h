/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morikumo <morikumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:50:23 by mabid             #+#    #+#             */
/*   Updated: 2023/01/26 01:26:10 by morikumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTION_H
# define OPTION_H

# include "parse.h"

int		get_opt(t_data *data, char *line, int res);
int		check_status_tx(t_data *data);
int		take_rgb(t_color *s_key, char *line, t_data *data);
int		get_texture(t_data *data, char *path, t_img *img);

#endif