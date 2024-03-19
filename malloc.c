/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:36:40 by jeshin            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/03/19 15:32:41 by jeshin           ###   ########.fr       */
=======
/*   Updated: 2024/03/19 16:44:53 by jeshin           ###   ########.fr       */
>>>>>>> Fix draw. Need to make isometric projection
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_tab(char **tab)
{
	int	i;

	if (tab == 0)
		return ;
	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

int	free_all(char **tab, t_dq *dq)
{
	free_tab(tab);
	clear_dq(dq);
	return (0);
}

int	malloc_map_crd(t_dq *dq, t_map_info *map)
{
	int	i;
	int	j;

	map->crd = (int **)malloc(sizeof(int *) * map->n_row);
	if (map->crd == 0)
	{
		clear_dq(dq);
		return (EXIT_FAILURE);
	}
	i = -1;
	while (++i < map->n_row)
	{
		map->crd[i] = (int *)malloc(sizeof(int) * map->n_col);
		if (map->crd[i] == 0)
		{
			j = -1;
			while (++j < i - 1)
				free(map->crd[j]);
			clear_dq(dq);
			free(map->crd);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

int	calloc_map_color(t_dq *dq, t_map_info *map)
{
	int	i;
	int	j;

	map->color = (unsigned int **)malloc(sizeof(unsigned int *) * map->n_row);
	if (map->crd == 0)
	{
		clear_dq(dq);
		return (EXIT_FAILURE);
	}
	i = -1;
	while (++i < map->n_row)
	{
<<<<<<< HEAD
		 map->color[i] = (unsigned int *)malloc(sizeof(unsigned int) * map->n_col);
		 if (map->color[i] == 0)
		 {
=======
		map->color[i] = (unsigned int *)malloc(sizeof(int) * map->n_col);
		if (map->color[i] == 0)
		{
>>>>>>> Fix draw. Need to make isometric projection
			j = -1;
			while (++j < i - 1)
				free(map->color[j]);
			clear_dq(dq);
			free(map->color);
			return (1);
<<<<<<< HEAD
		 }
		 ft_bzero(map->color[i], map->n_col * sizeof(unsigned int));
=======
		}
		ft_bzero(map->color[i], map->n_col * sizeof(unsigned int));
>>>>>>> Fix draw. Need to make isometric projection
	}
	return (EXIT_SUCCESS);
}
