/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 20:25:06 by jeshin            #+#    #+#             */
/*   Updated: 2024/03/16 19:55:37 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_img_info *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length) + (x * img->bits_per_pixel / 8);
	*(unsigned int *)dst = color;
}

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

	z = map->crd[y][x];
	x +=map->offset;
	y +=map->offset;
	p.x = x*cos(M_PI/6) - y*cos(M_PI/6);
	p.y = x*sin(M_PI/6) + y*sin(M_PI/6) - z;
	p.color = 0xFFFFFF;
	// p.color = map->color[y][x];
	return (p);
}

void	draw_line_with_increment_x(t_img_info *img, t_point *p1, t_point *p2, t_params *params)
{
	params->discriminant = params->dy * 2 - params->dx;
	while ((p1->x) != (p2->x))
	{
		if (params->discriminant >= 0)
		{
			(p1->y) += params->increment_y;
		params->discriminant -= (p1->x) * 2;
		}
		(p1->x) += params->increment_x;
		params->discriminant += params->dy * 2;
		my_mlx_pixel_put(img, p1->x, p1->y, p1->color);
	}
}

void	draw_line_with_increment_y(t_img_info *img, t_point *p1, t_point *p2, t_params *params)
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

int	set_x(t_img_info *img, t_map_info *map, int x, int y)
{
	t_params	params;
	t_point		p1;
	t_point		p2;

	p1 = init_point(map, x, y);
	p2 = init_point(map, x + 1, y);
	params = init_params(&p1, &p2);
	my_mlx_pixel_put(img, p1.x, p1.y, p1.color);
	if (params.dy > params.dx)
		draw_line_with_increment_y(img, &p1, &p2, &params);
	else
		draw_line_with_increment_x(img, &p1, &p2, &params);
	return (EXIT_SUCCESS);
}
int	set_y(t_img_info *img, t_map_info *map, int x, int y)
{
	t_params	params;
	t_point		p1;
	t_point		p2;

	p1 = init_point(map, x, y);
	p2 = init_point(map, x, y + 1);
	params = init_params(&p1, &p2);
	my_mlx_pixel_put(img, p1.x, p1.y, p1.color);
	if (params.dy > params.dx)
		draw_line_with_increment_y(img, &p1, &p2, &params);
	else
		draw_line_with_increment_x(img, &p1, &p2, &params);
	return (EXIT_SUCCESS);
}

int	draw(t_img_info *img, t_map_info *map)
{
	int	y;
	int	x;

	y = -1;
	while (++y < map->n_row - 2)
	{
		x = -1;
		while (++x < map->n_col - 2)
		{
			if (x < map->n_col - 2)
				set_x(img, map, x, y);
			if (y < map->n_row - 2)
				set_y(img, map, x, y);
		}
	}
	return (EXIT_SUCCESS);
}
