/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:13:54 by jeshin            #+#    #+#             */
/*   Updated: 2024/03/26 11:53:31 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		exit (EXIT_FAILURE);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img->img, 0, 0);
	return (EXIT_SUCCESS);
}

int	display(t_mlx_info *mlx, t_img_info *img, t_map_info *map)
{
	t_fdf_info fdf;

	fdf.mlx = mlx;
	fdf.img = img;
	fdf.map = map;
	mlx->mlx = mlx_init();
	if (mlx->mlx == 0)
		return (EXIT_FAILURE);
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "FDF");
	if (prt(mlx,img,map))
		exit (EXIT_FAILURE);
	mlx_hook(mlx->win, ON_DESTROY, NO_EVENT_MASK, click_on_close, &fdf);
	mlx_hook(mlx->win, ON_KEYDOWN, KEY_PRESS, key_event_hook, &fdf);
	mlx_loop(mlx->mlx);
	return (EXIT_SUCCESS);
}
