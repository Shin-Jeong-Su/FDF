/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:33:04 by jeshin            #+#    #+#             */
/*   Updated: 2024/03/20 17:38:52 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	create_argb(int a, int r, int g, int b)
{
	int	color;

	color = (a << 24) + (r << 16) + (g << 8) + b;
	return (color);
}

void	my_mlx_pixel_put(t_img_info *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length) + (x * img->bits_per_pixel / 8);
	*(unsigned int *)dst = color;
}

int	hook_esc_to_close(int keycode ,t_mlx_info *mlx)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(EXIT_SUCCESS);
	}
	return (EXIT_SUCCESS);
}

int	hook_click_to_close(t_mlx_info *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(EXIT_SUCCESS);
}

int	display(t_mlx_info *mlx, t_img_info *img, t_map_info *map)
{
	mlx->mlx = mlx_init();
	if (mlx->mlx == 0)
		return (EXIT_FAILURE);
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "FDF");
	if (mlx->win == 0)
		return (EXIT_FAILURE);
	img->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	if (img->img == 0)
		return (EXIT_FAILURE);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), \
	&(img->line_length), &(img->endian));
	if (!img->addr)
		return (EXIT_FAILURE);
	if (draw(img, map))
		return (EXIT_FAILURE);
	// mlx_put_image_to_window(mlx->mlx, mlx->win, img->img, WIDTH/2 - (map->n_col * map->offset), HEIGHT/2 - (map->n_row * map->offset));
	// mlx_put_image_to_window(mlx->mlx, mlx->win, img->img, WIDTH/2, HEIGHT/2);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img->img,0, 0);
	mlx_hook(mlx->win,ON_DESTROY,NO_EVENT,hook_click_to_close, mlx);
	mlx_hook(mlx->win,ON_KEYDOWN,KEY_PRESS,hook_esc_to_close, mlx);
	mlx_loop(mlx->mlx);
	return (EXIT_SUCCESS);
}
