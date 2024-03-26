/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:42:30 by jeshin            #+#    #+#             */
/*   Updated: 2024/03/26 15:27:32 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_params	init_params(t_point *p1, t_point *p2)
{
	t_params	params;

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
	int			tmp_x;
	int			tmp_y;

	if (map->has_color == FALSE)
		p.color = create_argb(0, 255, 255, 255);
	else if (map->color[y][x] == 0)
		p.color = create_argb(0, 255, 255, 255);
	else
		p.color = map->color[y][x];
	p.z = map->crd[y][x] * map->offset / 5;
	p.x = x * map->offset;
	p.y = y * map->offset;
	tmp_x = p.x;
	tmp_y = p.y;
	if (map->ortho_flg % 4 == 0)
	{
		p.x = (tmp_x * cos(M_PI / 6)) - (tmp_y * cos(M_PI / 6));
		p.y = (tmp_x * sin(M_PI / 6)) + (tmp_y * sin(M_PI / 6)) - p.z;
	}
	p.x += (WIDTH / 2) - map->central_x;
	p.y += (HEIGHT / 2) - map->central_y;
	return (p);
}
