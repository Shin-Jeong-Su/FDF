/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:10:36 by jeshin            #+#    #+#             */
/*   Updated: 2024/03/26 15:55:15 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

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
