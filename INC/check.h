/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabid <mabid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:39:01 by mabid             #+#    #+#             */
/*   Updated: 2023/01/23 17:16:24 by shammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "parse.h"

void	change_space_to_3(t_data *data);
void	check_arg(int ac, char **av);
void	check_main(int ac, char **av, t_data *data);
void	init_pos_dir(t_data *data);
void	init_pos_dir(t_data *data);
int		first_lenght(t_data *data);
int		ft_check_name_map(char *s1);
int		check_line_close(t_data *data, int line);
int		check_if_is_close(t_data *data);
int		check_file(char *name_map);
int		check_fd(char *name_map);
int		check_all(int ac, char **av, t_data *data);
int		check_letter(t_data *data);
int		check_duplicate_position(t_data *data);
int		return_x(char **str);
int		check_close(t_data *data);
int		check_order(char *file);

#endif
