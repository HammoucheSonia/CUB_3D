/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morikumo <morikumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:43:26 by mabid             #+#    #+#             */
/*   Updated: 2023/01/26 10:39:53 by shammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	check_temp(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * @brief 
 * Pour voir la valeur de chaque case du tableau : 
 * 		printf("res[%d] = %d \n", i, res[i]);
 * @param res 
 * @param s_key 
 * @param data 
 */
int	add_rgb(int *res, t_color *s_key)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (res[i] < 0 || res[i] > 255)
		{
			printf("Error\nRGB value must be between 0 and 255\n");
			return (-1);
		}
		i++;
	}
	s_key->r = (int)res[0];
	s_key->g = (int)res[1];
	s_key->b = (int)res[2];
	s_key->status = 1;
	return (0);
}
