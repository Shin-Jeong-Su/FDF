/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:42:30 by jeshin            #+#    #+#             */
/*   Updated: 2024/03/20 17:43:38 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

t_params	init_params(t_point *p1, t_point *p2)
{
	t_params params;

	params.dy = (p2->y) - (p1->y);
	params.dx = (p2->x) - (p1->x);
	params.increment_x = 1;
	if (params.dx < 0)
	{
		params.dx = -params.dx;
		params.increment_x = -1;
	}
	params.increment_y = 1;
	if (params.dy < 0)
	{
		params.dy = -params.dy;
		params.increment_y = -1;
	}
	return (params);
}

t_point	init_point(t_map_info *map, int x, int y)
{
	t_point		p;
	int			z;

	if (map->has_color == FALSE)
		p.color = create_argb(0,255,255,255);
	else if (map->color[y][x] == 0)
		p.color = create_argb(0,255,255,255);
	else
		p.color = map->color[y][x];
	z = map->crd[y][x] * map->offset;
	x = x*map->offset;
	y = y*map->offset;
	p.x = x*cos(M_PI/6) - y*cos(M_PI/6) + WIDTH/2 - (map->n_col/2 *cos(M_PI/6) - map->n_row/2*cos(M_PI/6));
	p.y = x*sin(M_PI/6) + y*sin(M_PI/6) - z + HEIGHT/2 - (map->n_col/2*sin(M_PI/6) + map->n_row/2*sin(M_PI/6) - avg_z);
	return (p);
}
