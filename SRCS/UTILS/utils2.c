/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabid <mabid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:43:14 by mabid             #+#    #+#             */
/*   Updated: 2023/01/13 19:43:20 by mabid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	ft_stronly(const char *s, const char *s2)
{
	int	i;

	i = 0;
	if (!s2)
		return (1);
	while (s2[i])
	{
		if (*s != s2[i] && !ft_isspace(s2[i]))
		{
			printf("Error\n Bad map\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	size_width(t_data *data)
{
	int	i;
	int	width1;
	int	width2;

	i = 0;
	if (!data->map)
		return (0);
	width1 = ft_strlen(data->map[0]);
	while (data->map[i])
	{
		if (data->map[i])
			width2 = ft_strlen(data->map[i]);
		if (width1 < width2)
			width1 = width2;
		i++;
	}
	return (width1);
}

int	size_lenght(t_data *data)
{
	int	i;

	i = 0;
	if (!data->map)
		return (0);
	while (data->map[i])
		i++;
	return (i);
}

int	count(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == ',')
			count++;
		i++;
	}
	return (count);
}

char	*ft_strdup(char *s)
{
	int		i;
	char	*str;
	int		e;

	e = 0;
	i = 0;
	while (s[i] != '\0')
		i++;
	str = malloc(sizeof(*str) * (i + 1));
	if (str == NULL)
		return (NULL);
	while (e < i)
	{
		str[e] = s[e];
		e++;
	}
	str[e] = '\0';
	return (str);
}
