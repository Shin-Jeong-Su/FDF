/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:41:32 by jeshin            #+#    #+#             */
/*   Updated: 2024/03/13 20:56:34 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include <math.h>
# include "my_deque.h"
# include <stdio.h>

# define WIDTH 1080
# define HEIGHT 1280

typedef struct s_mlx_info
{
	void	*mlx;
	void	*win;
}	t_mlx_info;

typedef struct s_img_info
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img_info;

typedef struct s_clr
{
	int		i;
	int		j;
	int		r;
	int		g;
	int		b;
	int		color;
	char	*set;
}	t_clr;

typedef struct s_map_info
{
	int		**crd;
	int		**color;
	int		has_color;
	int		n_col;
	int		n_row;
	int		offset;
}	t_map_info;

typedef struct s_z
{
	t_node	*start;
	char	**tab;
	char	*tmp;
	int		len;
	int		i;
	int		j;
	int		k;
}	t_z;

//init.c
int		init(int ac, char **av, t_dq *dq);
//malloc.c
void	free_tab(char **tab);
int		free_all(char **tab, t_dq *dq);
int		malloc_map_crd(t_dq *dq, t_map_info *map);
int		calloc_map_color(t_dq *dq, t_map_info *map);
//map.c
int		parse_map(t_dq *dq, t_map_info *map);
//map2.c
int		has_color_value(t_dq *dq);
int		cvrt_str_to_color(char *s);
//img.c
void	prt_img(t_mlx_info *mlx, t_img_info *img, t_map_info *map);

#endif