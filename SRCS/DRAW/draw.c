/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabid <mabid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:22:49 by mabid             #+#    #+#             */
/*   Updated: 2023/01/14 15:42:37 by mabid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

/**
 * @brief La fonction utilise les informations contenues dans les structures 
 * "data" et "color" pour dessiner un pixel de couleur 
 * sur l'image pointée par "data->tx.addr".
 * 
 * L'opération ">> 3" est une opération de décalage de bits vers la droite.
 *  Elle prend un nombre binaire et déplace tous les bits vers la droite en
 *  ajoutant des zéros à gauche. Cela a pour effet de diviser la valeur par 
 * 2^3 (8 en décimal).
 * 
 * Dans le cas de cette fonction, "data->tx.bpp" est le nombre de bits par 
 * pixel utilisé dans l'image. En effectuant un "x * data->tx.bpp >> 3", 
 * le code divise la position en x par 8.Cela est utile pour accéder aux 
 * octets de chaque composante de la couleur, en utilisant un pointeur sur un 
 * tableau de bytes. En effet,l'accès aux données par octet est plus efficace 
 * que l'accès aux données par bit.
 * Cette division permet également d'éviter les erreurs d'accès mémoire qui 
 * pourrait survenir lorsque l'on accède à des positions de mémoire qui ne sont
 *  pas alignées sur des limites d'octets.
 * 
 * @param data 
 * @param color 
 * @param y 
 * @param x 
 */
void	draw_rgb(t_data *data, t_color *color, int y, int x)
{
	if (data->tx.endian == 1)
	{
		data->tx.addr[(x * data->tx.bpp >> 3)
			+ y * data->tx.line] = color->r;
		data->tx.addr[(x * data->tx.bpp >> 3)
			+ 1 + y * data->tx.line] = color->g;
		data->tx.addr[(x * data->tx.bpp >> 3)
			+ 2 + y * data->tx.line] = color->b;
	}
	else
	{
		data->tx.addr[(x * data->tx.bpp >> 3)
			+ y * data->tx.line] = color->b;
		data->tx.addr[(x * data->tx.bpp >> 3)
			+ 1 + y * data->tx.line] = color->g;
		data->tx.addr[(x * data->tx.bpp >> 3)
			+ 2 + y * data->tx.line] = color->r;
	}
}

/**
 * @brief Utilise les textures pour dessiner les murs
 * 		bpp Ici pour bits par pixel	
 * La fonction utilise des opérations mathématiques pour calculer 
 * les coordonnées du pixel à dessiner, en utilisant des propriétés comme 
 * la hauteur de ligne, la largeur, le bpp, les coordonnées de début 
 * et fin d'affichage de mur, les coordonnées de la projection de rayon 
 * sur le mur.
 * 
 * Ici l'operation est effectuer 3 fois pour la composant rgb des couleurs
 * Pour chaque pisxel l'action est repeter
 * @param data 
 * @param tex 
 * @param y 
 * @param x 
 */
void	draw_wall(t_data *data, t_img *tex, int y, int x)
{
	data->tx.addr[(x * data->tx.bpp >> 3)
		+ y * data->tx.line]
		= tex->addr[(int)(data->ray.wall_x * tex->width) * (tex->bpp >> 3)
		+ (int)((y - data->ray.wall_start * 1.0) / data->ray.line_height
			* tex->height) *tex->line];
	data->tx.addr[(x * data->tx.bpp >> 3)
		+ 1 + y * data->tx.line]
		= tex->addr[(int)(data->ray.wall_x * tex->width) * (tex->bpp >> 3)
		+ 1 + (int)((y - data->ray.wall_start * 1.0)
			/ data->ray.line_height * tex->height) *tex->line];
	data->tx.addr[(x * data->tx.bpp >> 3)
		+ 2 + y * data->tx.line]
		= tex->addr[(int)(data->ray.wall_x * tex->width) * (tex->bpp >> 3)
		+ 2 + (int)((y - data->ray.wall_start * 1.0)
			/ data->ray.line_height * tex->height) *tex->line];
}

/**
 * @brief Ici NO = 0, So = 1, WE = 2, EA = 3
 * 		Chaque valeur est assigner a une direction
 * 		On fait avec les moyens du bord
 * 
 * @param data 
 * @param y 
 * @param x 
 */
void	draw_tmp(t_data *data, int y, int x)
{
	if (data->ray.side == NO)
		draw_wall(data, &data->west, y, x);
	else if (data->ray.side == SO)
		draw_wall(data, &data->east, y, x);
	else if (data->ray.side == WE)
		draw_wall(data, &data->north, y, x);
	else if (data->ray.side == EA)
		draw_wall(data, &data->south, y, x);
}

/**
 * @brief Definit les valeur de depart et d'arriver d'un mur
 * 
 * @param data 
 * @param start 
 * @param end 
 */
void	set_stop(t_data *data, int *start, int *end)
{
	if (data->ray.wall_start < 0)
		*start = 0;
	else
		*start = data->ray.wall_start;
	if (data->ray.wall_end >= WIN_HEIGHT)
		*end = WIN_HEIGHT - 1;
	else
		*end = data->ray.wall_end;
}

/**
 * @brief La synthese de tout ce qu'il y a plus haut
 * 
 * @param data 
 * @param x 
 */
void	put_in_display(t_data *data, int x)
{
	int	y;
	int	start;
	int	end;

	y = 0;
	set_stop(data, &start, &end);
	while (y < start)
	{
		draw_rgb(data, &data->ceiling, y, x);
		y++;
	}
	while (y < end)
	{
		draw_tmp(data, y, x);
		y++;
	}
	while (y < WIN_HEIGHT - 1)
	{
		draw_rgb(data, &data->floor, y, x);
		y++;
	}
}
