/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:40:14 by jeshin            #+#    #+#             */
/*   Updated: 2024/03/26 16:55:43 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_dq			dq;
	t_map_info		map;
	t_mlx_info		mlx;
	t_img_info		img;

	if (init_fdf(argc, argv, &dq))
		return (EXIT_FAILURE);
	if (parse_map(&dq, &map))
		return (EXIT_FAILURE);
	if (display(&mlx, &img, &map))
		exit (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
