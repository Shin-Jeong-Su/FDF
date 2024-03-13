/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:40:14 by jeshin            #+#    #+#             */
/*   Updated: 2024/03/13 13:25:35 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

int main(int argc, char **argv)
{
	t_dq			dq;
	t_map_info		map;
	t_mlx_info		mlx;
	t_img_info		img;

	if (init(argc, argv, &dq))
		return (EXIT_FAILURE);
	if (parse_map(&dq, &map))
		return (EXIT_FAILURE);
	prt_img(&mlx, &img, &map);
	free(map.crd);
	
	return (EXIT_SUCCESS);
}
