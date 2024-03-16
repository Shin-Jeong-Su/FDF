/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:56:48 by jeshin            #+#    #+#             */
/*   Updated: 2024/03/16 16:57:14 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_x_pixel(int x, int y, t_map_info *map)
{
	t_point *p1;
	t_point *p2;

	p1 = malloc(sizeof(t_point));
	p2 = malloc(sizeof(t_point));

	p1->x = rotate(x);
	p1->y = rotate(y);
	p1->z = rotate(z);
	p1->color = map->crd[x][y];

	p2->x = rotate(x+1);
	p2->y = rotate(y);
	p2->z = rotate(z);
	p2->color = map->crd[x+1][y];
	bresenham(img,p1,p2);
	free(p1);
	free(p2);
}

void	put_y_pixel(int x, int y, t_map_info *map)
{
	t_point *p1;
	t_point *p2;

	p1 = malloc(sizeof(t_point));
	p2 = malloc(sizeof(t_point));

	p1->x = rotate(x);
	p1->y = rotate(y);
	p1->z = rotate(z);
	p2->color = map->crd[x][y];

	p2->x = rotate(x);
	p2->y = rotate(y+1);
	p2->z = rotate(z);
	p2->color = map->crd[x][y+1];
	bresenham(img,p1,p2);
	free(p1);
	free(p2);
}