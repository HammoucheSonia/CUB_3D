/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morikumo <morikumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:43:15 by mabid             #+#    #+#             */
/*   Updated: 2023/01/26 01:38:18 by morikumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <errno.h>
# include <math.h>
# include <string.h>

# define NO 0
# define SO 1
# define WE 2
# define EA 3

# define WIN_WIDTH	1920
# define WIN_HEIGHT	1000

# include "struct.h"
# include "check.h"
# include "init_all.h"
# include "free.h"
# include "draw.h"
# include "move.h"
# include "option.h"
# include "get.h"
# include "get_next_line.h"
# include "../mlx/mlx.h"

void	exit_opt(t_data *data, char *msg);
char	**ft_split(char const *s, char c);
char	*ft_strjoinfree(char *s1, char *s2, int to_free);
char	*ft_strdup(char *s);
int		add_rgb(int *res, t_color *s_key);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
int		ft_isspace(char c);
int		ft_stronly(const char *s, const char *s2);
int		size_width(t_data *data);
int		size_lenght(t_data *data);
int		count(char *line);
int		ft_digit(char *str);
int		check_temp(char *s);
int		ft_atol(char *str, char **tmp);
char	*ft_strcpy(char *dest, char *src);
char	*ft_itoa(int n);

#endif
