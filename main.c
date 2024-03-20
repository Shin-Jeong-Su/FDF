/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:40:14 by jeshin            #+#    #+#             */
/*   Updated: 2024/03/20 17:43:28 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_dq			dq;
	t_map_info		map;
	t_mlx_info		mlx;
	t_img_info		img;


	if (init(argc, argv, &dq))
		return (EXIT_FAILURE);
	if (parse_map(&dq, &map))
		return (EXIT_FAILURE);
	for(int i=0;i<map.n_row;i++){
		for(int j=0;j<map.n_col;j++){
			avg_z +=map.crd[i][j];
		}
	}
	avg_z /=map.n_col * map.n_row;
	printf("%d",avg_z);
	if (display(&mlx, &img, &map))
		return (EXIT_FAILURE);
	// free_all();
	// free(map.crd);
	return (EXIT_SUCCESS);
}
