/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:05:40 by jeshin            #+#    #+#             */
/*   Updated: 2024/03/26 11:37:50 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pitch(t_point *p, int deg)
{
	int	prv_y;
	int	prv_z;

	prv_y = p->y;
	prv_z = p->z;
	p->y = prv_y * cos(M_PI / 180 * deg) - prv_z * sin(M_PI / 180 * deg);
	p->z = prv_y * sin(M_PI / 180 * deg) + prv_z * cos(M_PI / 180 * deg);
}

void	yaw(t_point *p, int deg)
{
	int	prv_x;
	int	prv_z;

	prv_x = p->x;
	prv_z = p->z;
	p->x = prv_x * cos(M_PI / 180 * deg) + prv_z * sin(M_PI / 180 * deg);
	p->z = -prv_x * sin(M_PI / 180 * deg) + prv_z * cos(M_PI / 180 * deg);
}

void	roll(t_point *p, int deg)
{
	int	prv_x;
	int	prv_y;

	prv_x = p->x;
	prv_y = p->y;
	p->x = prv_x * cos(M_PI / 180 * deg) - prv_y * sin(M_PI / 180 * deg);
	p->y = prv_x * sin(M_PI / 180 * deg) + prv_y * cos(M_PI / 180 * deg);
}

int	rotate(t_point *p, t_map_info *map)
{
	if (map->alpha)
		pitch(p, map->alpha);
	if (map->beta)
		yaw(p, map->beta);
	if (map->gamma)
		roll(p, map->gamma);
	return (EXIT_SUCCESS);
}
