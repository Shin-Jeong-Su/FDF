/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 20:25:06 by jeshin            #+#    #+#             */
/*   Updated: 2024/03/22 18:32:48 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	drw_wth_x(t_img_info *img, t_point *p1, t_point *p2, t_params *params)
{
	params->discriminant = params->dy * 2 - params->dx;
	while ((p1->x) != (p2->x))
	{
		if (params->discriminant >= 0)
		{
			(p1->y) += params->increment_y;
			params->discriminant -= (params->dx) * 2;
		}
		(p1->x) += params->increment_x;
		params->discriminant += params->dy * 2;
		my_mlx_pixel_put(img, p1->x, p1->y, p1->color);
	}
}

void	drw_wth_y(t_img_info *img, t_point *p1, t_point *p2, t_params *params)
{
	params->discriminant = (params->dx) * 2 - (params->dy);
	while (p1->y != p2->y)
	{
		if (params->discriminant >= 0)
		{
			p1->x += params->increment_x;
			params->discriminant -= params->dy * 2;
		}
		p1->y += params->increment_y;
		params->discriminant += params->dx * 2;
		my_mlx_pixel_put(img, p1->x, p1->y, p1->color);
	}
}

static int	set_x(t_img_info *img, t_map_info *map, int x, int y)
{
	t_params	params;
	t_point		p1;
	t_point		p2;

	p1 = init_point(map, x, y);
	p2 = init_point(map, x + 1, y);
	if (p1.x < 0 || p1.y < 0 || p2.x < 0 || p2.y < 0)
		return (EXIT_SUCCESS);
	if (p1.x > WIDTH - 1 || p1.y > HEIGHT - 1 || p2.x > WIDTH || p2.y > HEIGHT)
		return (EXIT_SUCCESS);
	if (map->offset < 0)
		return (EXIT_SUCCESS);
	params = init_params(&p1, &p2);
	my_mlx_pixel_put(img, p1.x, p1.y, p1.color);
	if (params.dy > params.dx)
		drw_wth_y(img, &p1, &p2, &params);
	else
		drw_wth_x(img, &p1, &p2, &params);
	return (EXIT_SUCCESS);
}

static int	set_y(t_img_info *img, t_map_info *map, int x, int y)
{
	t_params	params;
	t_point		p1;
	t_point		p2;

	p1 = init_point(map, x, y);
	p2 = init_point(map, x, y + 1);
	if (p1.x < 0 || p1.y < 0 || p2.x < 0 || p2.y < 0)
		return (EXIT_SUCCESS);
	if (p1.x > WIDTH - 1 || p1.y > HEIGHT - 1 || p2.x > WIDTH || p2.y > HEIGHT)
		return (EXIT_SUCCESS);
	if (map->offset < 0)
		return (EXIT_SUCCESS);
	params = init_params(&p1, &p2);
	my_mlx_pixel_put(img, p1.x, p1.y, p1.color);
	if (params.dy > params.dx)
		drw_wth_y(img, &p1, &p2, &params);
	else
		drw_wth_x(img, &p1, &p2, &params);
	return (EXIT_SUCCESS);
}

int	draw(t_img_info *img, t_map_info *map)
{
	int	y;
	int	x;

	y = -1;
	while (++y < map->n_row)
	{
		x = -1;
		while (++x < map->n_col)
		{
			if (x < map->n_col - 1)
				set_x(img, map, x, y);
			if (y < map->n_row - 1)
				set_y(img, map, x, y);
		}
	}
	return (EXIT_SUCCESS);
}
