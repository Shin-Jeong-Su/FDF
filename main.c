/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:40:14 by jeshin            #+#    #+#             */
/*   Updated: 2024/03/06 19:22:38 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_dq			dq;
	t_vars			vars;
	t_img_info		img_info;

	if (init(argc, argv, &dq))
		return (1);
	prt_img(&vars, &img_info);
	
}

void prtimg(t_vars *vars,t_img_info *img_info)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx,width,height,"FDF");
	img_info->img = mlx_new_image(vars->mlx,width,height);
	mlx_get_data_addr(img_info->img, &(img_info->bits_per_pixel), &(img_info->line_length), &(img_info->endian));

}