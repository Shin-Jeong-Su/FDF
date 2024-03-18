/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 20:25:06 by jeshin            #+#    #+#             */
/*   Updated: 2024/03/18 15:47:36 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
void	draw_line_with_increment_y(t_img_info *img, t_point *p1, t_point *p2, t_params *params);

int	create_argb(int a, int r, int g, int b)
{
	int color;

	color = (a << 24) + (r << 16) + (g << 8) + b;
	return (color);
}

void	my_mlx_pixel_put(t_img_info *img, int x, int y, int color)
{
	char	*dst;

	// printf("%d\t",x);
	// printf("%d\n",y);
	dst = img->addr + (y * img->line_length) + (x * img->bits_per_pixel / 8);
	*(unsigned int *)dst = 0xFFFFFF;
	color = 0xFFFFFF;
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
	int			ofs;

	ofs = map->offset;
	z = map->crd[y][x] * ofs;
	x = x*ofs;
	y = y*ofs;
	// p.x = x;
	// p.y = y;
	p.x = x*cos(M_PI/6) - y*cos(M_PI/6) + WIDTH/2;
	p.y = x*sin(M_PI/6) + y*sin(M_PI/6) - z + HEIGHT/2;
	p.color = create_argb(0,255,255,255);
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
	// if (p1->y < p2->y)
	// 	draw_line_with_increment_y(img,p1,p2,params);
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
	// if (p1->x < p2->x)
	// 	draw_line_with_increment_x(img,p1,p2,params);
}

int	set_x(t_img_info *img, t_map_info *map, int x, int y)
{
	t_params	params;
	t_point		p1;
	t_point		p2;

	p1 = init_point(map, x, y);
	// p1.x =WIDTH/2 + x*map->offset;
	// p1.y =HEIGHT/2 + y*map->offset;
	// p1.color = create_argb(0,255,255,255);

	p2 = init_point(map, x + 1, y);
	// p2.x =WIDTH/2 + (x+1)* map->offset;
	// p2.y =HEIGHT/2 + y*map->offset;
	// p2.color = create_argb(0,255,255,255);

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
	// p1.x =WIDTH/2 + x*map->offset;
	// p1.y =HEIGHT/2 + y*map->offset;
	// p1.color = create_argb(0,255,255,255);

	p2 = init_point(map, x, y + 1);
	// p2.x =WIDTH/2 + x*map->offset ;
	// p2.y =HEIGHT/2 + (y+1) * map->offset;
	// p2.color = create_argb(0,255,255,255);

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
