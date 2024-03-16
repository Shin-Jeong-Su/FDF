/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:40:14 by jeshin            #+#    #+#             */
/*   Updated: 2024/03/16 19:51:16 by jeshin           ###   ########.fr       */
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
	if (display(&mlx, &img, &map))
		return (EXIT_FAILURE);
	// free_all();
	// free(map.crd);
	
	return (EXIT_SUCCESS);
}
