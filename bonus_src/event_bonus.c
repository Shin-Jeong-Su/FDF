/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:32:43 by jeshin            #+#    #+#             */
/*   Updated: 2024/03/26 12:51:51 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	hook_zoom(int keycode, t_fdf_info *fdf)
{
	if (keycode == PLUS)
	{
		fdf->map->offset += fdf->map->offset / 5;
		mlx_destroy_image(fdf->mlx->mlx, fdf->img->img);
		prt(fdf->mlx, fdf->img, fdf->map);
	}
	if (keycode == MINUS)
	{
		fdf->map->offset -= fdf->map->offset / 5;
		mlx_destroy_image(fdf->mlx->mlx, fdf->img->img);
		prt(fdf->mlx, fdf->img, fdf->map);
	}
	return (EXIT_SUCCESS);
}

int	hook_translate(int keycode, t_fdf_info *fdf)
{
	if (keycode == UP_ARROW)
	{
		fdf->map->central_y += fdf->map->offset;
		mlx_destroy_image(fdf->mlx->mlx, fdf->img->img);
		prt(fdf->mlx, fdf->img, fdf->map);
	}
	if (keycode == DOWN_ARROW)
	{
		fdf->map->central_y -= fdf->map->offset;
		mlx_destroy_image(fdf->mlx->mlx, fdf->img->img);
		prt(fdf->mlx, fdf->img, fdf->map);
	}
	if (keycode == LEFT_ARROW)
	{
		fdf->map->central_x += fdf->map->offset;
		mlx_destroy_image(fdf->mlx->mlx, fdf->img->img);
		prt(fdf->mlx, fdf->img, fdf->map);
	}
	if (keycode == RIGHT_ARROW)
	{
		fdf->map->central_x -= fdf->map->offset;
		mlx_destroy_image(fdf->mlx->mlx, fdf->img->img);
		prt(fdf->mlx, fdf->img, fdf->map);
	}
	return (EXIT_SUCCESS);
}

int	hook_rotate(int keycode, t_fdf_info *fdf)
{
	if (keycode == ONE)
		fdf->map->alpha += 10;
	else if (keycode == TWO)
		fdf->map->alpha -= 10;
	else if (keycode == THREE)
		fdf->map->beta += 10;
	else if (keycode == FOUR)
		fdf->map->beta -= 10;
	else if (keycode == FIVE)
		fdf->map->gamma += 10;
	else if (keycode == SIX)
		fdf->map->gamma -= 10;
	mlx_destroy_image(fdf->mlx->mlx, fdf->img->img);
	prt(fdf->mlx, fdf->img, fdf->map);
	return (EXIT_SUCCESS);
}

int	hook_return_to_original(t_fdf_info *fdf)
{
	t_map_info	*map;

	map = fdf->map;
	map->offset = 0;
	while (map->n_row * map->offset < HEIGHT / 2 \
	&& map->n_col * map->offset < WIDTH / 2)
		map->offset++;
	map->central_x = (map->n_col / 2 * cos(M_PI / 6) * map->offset) - \
	(map->n_row / 2 * cos(M_PI / 6) * map->offset);
	map->central_y = (map->n_col / 2 * sin(M_PI / 6) * map->offset) + \
	(map->n_row / 2 * sin(M_PI / 6) * map->offset);
	fdf->map->alpha = 0;
	fdf->map->beta = 0;
	fdf->map->gamma = 0;
	fdf->map->ortho_flg = 0;
	mlx_destroy_image(fdf->mlx->mlx, fdf->img->img);
	prt(fdf->mlx, fdf->img, fdf->map);
	return (EXIT_SUCCESS);
}
