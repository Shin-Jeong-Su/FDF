/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_bonus2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:48:32 by jeshin            #+#    #+#             */
/*   Updated: 2024/03/26 12:50:09 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	handle_rotate_deg(t_fdf_info *fdf, int alpha, int beta, int gamma)
{
	fdf->map->alpha = alpha;
	fdf->map->beta = beta;
	fdf->map->gamma = gamma;
}

int	hook_ortho_project(t_fdf_info *fdf)
{
	fdf->map->ortho_flg++;
	if (fdf->map->ortho_flg % 4 == 0)
		handle_rotate_deg(fdf, 0, 0, 0);
	else if (fdf->map->ortho_flg % 4 == 1)
		handle_rotate_deg(fdf, 0, 0, 0);
	else if (fdf->map->ortho_flg % 4 == 2)
		handle_rotate_deg(fdf, 90, 0, 0);
	else if (fdf->map->ortho_flg % 4 == 3)
		handle_rotate_deg(fdf, 90, 90, 0);
	mlx_destroy_image(fdf->mlx->mlx, fdf->img->img);
	prt(fdf->mlx, fdf->img, fdf->map);
	return (EXIT_SUCCESS);
}
