/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabid <mabid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:43:10 by mabid             #+#    #+#             */
/*   Updated: 2023/01/11 14:12:25 by mabid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H

# include "parse.h"

void	free_map(t_data *data);
void	free_map3(t_data *data);
void	free_tab(char **map);
void	free_img(t_data *data);
void	free_tmp(char *tmp);

#endif