/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:33:04 by jeshin            #+#    #+#             */
/*   Updated: 2024/03/13 13:53:55 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void my_mlx_pixel_put(t_img_info *img_info,int x,int y, int color)
{
	char *dst;

	dst = img_info->addr + (y * img_info->line_length)+(x * img_info->bits_per_pixel / 8);
	*(unsigned int *)dst = color;
}

void prt_img(t_mlx_info *mlx_info, t_img_info *img_info, t_map_info *map_info)
{
	mlx_info->mlx = mlx_init();
	mlx_info->win = mlx_new_window(mlx_info->mlx, WIDTH, HEIGHT, "FDF");
	img_info->img = mlx_new_image(mlx_info->mlx, WIDTH, HEIGHT);
	mlx_get_data_addr(img_info->img, &(img_info->bits_per_pixel), &(img_info->line_length), &(img_info->endian));
	printf("%d\n",map_info->n_col);
	mlx_put_image_to_window(mlx_info->mlx, mlx_info->win ,img_info->img, 0, 0);
}