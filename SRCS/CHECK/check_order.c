/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabid <mabid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:04:07 by shammouc          #+#    #+#             */
/*   Updated: 2023/01/27 08:40:47 by mabid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

static int	nb_ligne(char *file)
{
	int		fd;
	int		i;
	char	*tmp;

	i = 0;
	fd = open(file, O_RDONLY);
	tmp = get_next_line(fd);
	while (tmp)
	{
		i++;
		free(tmp);
		tmp = get_next_line(fd);
	}
	close(fd);
	return (i);
}

void	free_tableau(char **tab, int nb)
{
	int		i;

	i = 0;
	while (i < nb)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static int	check_order_final(char **tableau, int nb)
{
	int	i;
	int	j;

	i = nb - 1;
	j = 0;
	while (ft_strlen(tableau[i]) == 0)
		i--;
	while (tableau[i][j])
	{
		if (tableau[i][j] == '1' || tableau[i][j] == ' ')
			j++;
		else
		{
			free_tableau(tableau, nb);
			printf("Error order\n\n");
			return (0);
		}
	}
	free_tableau(tableau, nb);
	return (1);
}

int	check_order(char *file)
{
	int		i;
	int		fd_file;
	char	**tableau;
	int		nb;

	nb = nb_ligne(file);
	fd_file = open(file, O_RDONLY);
	tableau = malloc(sizeof(char *) * nb);
	i = 0;
	while (i < nb)
	{
		tableau[i] = get_next_line(fd_file);
		i++;
	}
	close(fd_file);
	return (check_order_final(tableau, i));
}
