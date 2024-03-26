/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:32:43 by jeshin            #+#    #+#             */
/*   Updated: 2024/03/26 12:19:30 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	hook_esc_to_close(int keycode, t_fdf_info *fdf)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_image(fdf->mlx->mlx, fdf->img->img);
		mlx_destroy_window(fdf->mlx->mlx, fdf->mlx->win);
		exit(EXIT_SUCCESS);
	}
}

static void	hook_zoom(int keycode, t_fdf_info *fdf)
{
	if (keycode == PLUS)
	{
		fdf->map->offset += fdf->map->offset/5;
		mlx_destroy_image(fdf->mlx->mlx, fdf->img->img);
		prt(fdf->mlx,fdf->img,fdf->map);
	}
	if (keycode == MINUS)
	{
		fdf->map->offset -= fdf->map->offset/5;
		mlx_destroy_image(fdf->mlx->mlx, fdf->img->img);
		prt(fdf->mlx,fdf->img,fdf->map);
	}
}

static void	hook_translate(int keycode, t_fdf_info *fdf)
{
	if (keycode == UP_ARROW)
	{
		fdf->map->central_y += fdf->map->offset;
		mlx_destroy_image(fdf->mlx->mlx, fdf->img->img);
		prt(fdf->mlx,fdf->img,fdf->map);
	}
	if (keycode == DOWN_ARROW)
	{
		fdf->map->central_y -= fdf->map->offset;
		mlx_destroy_image(fdf->mlx->mlx, fdf->img->img);
		prt(fdf->mlx,fdf->img,fdf->map);
	}
	if (keycode == LEFT_ARROW)
	{
		fdf->map->central_x += fdf->map->offset;
		mlx_destroy_image(fdf->mlx->mlx, fdf->img->img);
		prt(fdf->mlx,fdf->img,fdf->map);
	}
	if (keycode == RIGHT_ARROW)
	{
		fdf->map->central_x -= fdf->map->offset;
		mlx_destroy_image(fdf->mlx->mlx, fdf->img->img);
		prt(fdf->mlx,fdf->img,fdf->map);
	}
}

static void hook_rotate(int keycode , t_fdf_info *fdf)
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
	prt(fdf->mlx,fdf->img,fdf->map);
}

static void	hook_return_to_original(t_fdf_info *fdf)
{
	t_map_info *map =  fdf->map;
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
	prt(fdf->mlx,fdf->img,fdf->map);
}

static void	hook_ortho_project(t_fdf_info *fdf)
{
	fdf->map->ortho_flg++;
	if (fdf->map->ortho_flg % 4 == 0)
	{
		fdf->map->alpha = 0;
		fdf->map->beta = 0;
		fdf->map->gamma = 0;
	}
	else if (fdf->map->ortho_flg % 4 == 1)
	{
		fdf->map->alpha = 0;
		fdf->map->beta = 0;
		fdf->map->gamma = 0;
	}
	else if (fdf->map->ortho_flg % 4 == 2)
	{
		fdf->map->alpha = 90;
		fdf->map->beta = 0;
		fdf->map->gamma = 0;
	}
	else if (fdf->map->ortho_flg % 4 == 3)
	{
		fdf->map->alpha = 90;
		fdf->map->beta = 90;
		fdf->map->gamma = 0;
	}
	mlx_destroy_image(fdf->mlx->mlx, fdf->img->img);
	prt(fdf->mlx,fdf->img,fdf->map);
}

int	key_event_hook(int keycode, t_fdf_info *fdf)
{
	if (keycode == KEY_ESC)
		hook_esc_to_close(keycode, fdf);
	else if (keycode == UP_ARROW || keycode == DOWN_ARROW || keycode == LEFT_ARROW || keycode == RIGHT_ARROW)
		hook_translate(keycode, fdf);
	else if (keycode == PLUS || keycode == MINUS)
		hook_zoom(keycode, fdf);
	else if (keycode == ONE || keycode == TWO || keycode == THREE || keycode == FOUR || keycode == FIVE || keycode == SIX)
		hook_rotate(keycode, fdf);
	else if (keycode == HOME)
		hook_return_to_original(fdf);
	else if (keycode == TAB)
		hook_ortho_project(fdf);

	return (EXIT_SUCCESS);
}


int	click_on_close(t_fdf_info *fdf)
{
	mlx_destroy_image(fdf->mlx->mlx, fdf->img->img);
	mlx_destroy_window(fdf->mlx->mlx, fdf->mlx->win);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}