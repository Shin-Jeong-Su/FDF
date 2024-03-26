/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:13:54 by jeshin            #+#    #+#             */
/*   Updated: 2024/03/26 16:41:40 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static int	click_on_close(t_fdf_info *fdf)
{
	mlx_destroy_image(fdf->mlx->mlx, fdf->img->img);
	mlx_destroy_window(fdf->mlx->mlx, fdf->mlx->win);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

static int	hook_esc_to_close(int keycode, t_fdf_info *fdf)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_image(fdf->mlx->mlx, fdf->img->img);
		mlx_destroy_window(fdf->mlx->mlx, fdf->mlx->win);
		exit(EXIT_SUCCESS);
	}
	return (EXIT_SUCCESS);
}

static int	key_event_hook(int keycode, t_fdf_info *fdf)
{
	if (keycode == KEY_ESC)
		return (hook_esc_to_close(keycode, fdf));
	else if (keycode == UP_ARROW || keycode == DOWN_ARROW \
	|| keycode == LEFT_ARROW || keycode == RIGHT_ARROW)
		return (hook_translate(keycode, fdf));
	else if (keycode == PLUS || keycode == MINUS)
		return (hook_zoom(keycode, fdf));
	else if (keycode == ONE || keycode == TWO || keycode == THREE \
	|| keycode == FOUR || keycode == FIVE || keycode == SIX)
		return (hook_rotate(keycode, fdf));
	else if (keycode == HOME)
		return (hook_return_to_original(fdf));
	else if (keycode == TAB)
		return (hook_ortho_project(fdf));
	return (EXIT_SUCCESS);
}

int	prt(t_mlx_info *mlx, t_img_info *img, t_map_info *map)
{
	img->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	if (mlx->win == 0 || img->img == 0)
		return (EXIT_FAILURE);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), \
	&(img->line_length), &(img->endian));
	if (img->addr == 0)
		return (EXIT_FAILURE);
	if (draw(img, map))
		return (EXIT_FAILURE);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img->img, 0, 0);
	return (EXIT_SUCCESS);
}

int	display(t_mlx_info *mlx, t_img_info *img, t_map_info *map)
{
	t_fdf_info	fdf;

	fdf.mlx = mlx;
	fdf.img = img;
	fdf.map = map;
	mlx->mlx = mlx_init();
	if (mlx->mlx == 0)
		return (EXIT_FAILURE);
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "FDF");
	if (prt(mlx, img, map))
		return (EXIT_FAILURE);
	mlx_hook(mlx->win, ON_DESTROY, NO_EVENT_MASK, click_on_close, &fdf);
	mlx_hook(mlx->win, ON_KEYDOWN, KEY_PRESS, key_event_hook, &fdf);
	mlx_loop(mlx->mlx);
	return (EXIT_SUCCESS);
}
