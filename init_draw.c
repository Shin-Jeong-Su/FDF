/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:42:30 by jeshin            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/03/19 16:41:00 by jeshin           ###   ########.fr       */
=======
/*   Updated: 2024/03/19 16:49:43 by jeshin           ###   ########.fr       */
>>>>>>> Fix draw. Need to make isometric projection
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
<<<<<<< HEAD
	z = map->crd[y][x] * map->offset / 10;
=======
	z = map->crd[y][x] * map->offset / 5;
>>>>>>> Fix draw. Need to make isometric projection
	x = x*map->offset;
	y = y*map->offset;
	p.x = x*cos(M_PI/6) - y*cos(M_PI/6) + WIDTH / 2;
	p.y = x*sin(M_PI/6) + y*sin(M_PI/6) - z + HEIGHT / 2;
	return (p);
}
