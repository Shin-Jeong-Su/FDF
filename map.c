/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 20:43:43 by jeshin            #+#    #+#             */
/*   Updated: 2024/03/16 19:34:29 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_info_map(t_dq *dq, t_map_info *map)
{
	char	**str_tab;
	int		i;

	map->n_row = dq->size;
	str_tab = ft_split(front_dq(dq), ' ');
	if (!str_tab)
		return (EXIT_FAILURE);
	i = -1;
	(map->n_col) = 0;
	while (str_tab[++i])
		(map->n_col)++;
	free_tab(str_tab);
	map->offset = 10;
	while (map->n_row * map->offset < HEIGHT / 2 \
	&& map->n_col * map->offset < WIDTH / 2)
		map->offset++;
	return (EXIT_SUCCESS);
}

static int	get_z_value(t_dq *dq, t_map_info *map)
{
	t_z		z;

	if (malloc_map_crd(dq, map))
		return (EXIT_FAILURE);
	z.start = dq->head;
	z.i = -1;
	while (++(z.i) < map->n_row)
	{
		z.tab = ft_split(z.start->data, ' ');
		z.j = -1;
		while (++(z.j) < map->n_col)
		{
			z.k = -1;
			z.len = 0;
			while (z.tab[z.j][++(z.k)] && z.tab[z.j][z.k] != ',' \
			&& z.tab[z.j][z.k] != '\n')
				z.len++;
			z.tmp = ft_substr(z.tab[z.j], 0, z.len);
			map->crd[z.i][z.j] = ft_atoi(z.tmp);
			free(z.tmp);
		}
		free_tab(z.tab);
		z.start = z.start->next;
	}
	return (EXIT_SUCCESS);
}

static int	get_color(t_dq *dq, t_map_info *map)
{
	t_node	*start;
	char	**tab;
	int		i;
	int		j;

	if (map->has_color == FALSE)
		return (EXIT_SUCCESS);
	if (calloc_map_color(dq, map))
		return (EXIT_FAILURE);
	start = dq->head;
	i = -1;
	while (++i < map->n_row)
	{
		tab = ft_split(start->data, ' ');
		j = -1;
		while (++j < map->n_col)
			map->color[i][j] = cvrt_str_to_color(tab[j]);
		free_tab(tab);
		start = start->next;
	}
	return (EXIT_SUCCESS);
}

int	parse_map(t_dq *dq, t_map_info *map)
{
	map->has_color = has_color_value(dq);
	if (get_info_map(dq, map) & get_z_value(dq, map) & get_color(dq, map))
	{
		clear_dq(dq);
		return (EXIT_FAILURE);
	}
	return (0);
}
