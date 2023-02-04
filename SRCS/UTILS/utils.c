/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morikumo <morikumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:45:51 by mabid             #+#    #+#             */
/*   Updated: 2023/01/26 10:40:20 by shammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < n - 1)
		i++;
	return (s1[i] - s2[i]);
}

int	ft_isspace(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

int	ft_atol(char *str, char **tmp)
{
	int	res;

	res = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		++str;
	if (*str < '0' || *str > '9')
	{
		free_tab(tmp);
		printf("It's not a number !\n");
		return (-1);
	}
	while ((*str >= '0' && *str <= '9'))
	{
		res = res * 10 + *str - '0';
		++str;
	}
	return (res);
}

char	*ft_strjoinfree(char *s1, char *s2, int to_free)
{
	char	*array;

	array = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	ft_strcpy(array, s1);
	ft_strcpy(array + ft_strlen(s1), s2);
	if (to_free == 1 || to_free == 3)
		free(s1);
	if (to_free == 2 || to_free == 3)
		free(s2);
	return (array);
}

/**
 * @brief Fonction qui va agir en exit, va tout free et destroy
 * 			Et renvoyer un message si demander
 * @param data 
 * @param msg 
 */
void	exit_opt(t_data *data, char *msg)
{
	if (msg == NULL)
		(void)msg;
	else
		printf("%s\n", msg);
	if (data->mlx != NULL)
	{
		if (data->win != NULL)
		{
			free_img(data);
			mlx_destroy_window(data->mlx, data->win);
			data->win = NULL;
		}
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		data->mlx = NULL;
	}
	if (data->line)
	{
		free(data->line);
		data->line = NULL;
	}
	exit(1);
}
