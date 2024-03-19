/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:41:32 by jeshin            #+#    #+#             */
/*   Updated: 2024/03/19 16:36:29 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include <math.h>
# include "my_deque.h"
# include <stdio.h>

# define WIDTH 1400
# define HEIGHT 1050

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
	int				i;
	int				j;
	int				r;
	int				g;
	int				b;
	unsigned int	color;
	char			*set;
}	t_clr;

typedef struct s_map_info
{
	int				**crd;
	unsigned int	**color;
	int				has_color;
	int				n_col;
	int				n_row;
	int				offset;
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

typedef struct s_point
{
	int				x;
	int				y;
	unsigned int	color;
}	t_point;

typedef struct s_params
{
	int	dy;
	int	dx;
	int	increment_x;
	int	increment_y;
	int	discriminant;
}	t_params;

//init.c
int				init(int ac, char **av, t_dq *dq);
//parse_map.c
int				parse_map(t_dq *dq, t_map_info *map);
//parse_map2.c
int				has_color_value(t_dq *dq);
unsigned int	cvrt_str_to_color(char *s);
//display.c
int				create_argb(int a, int r, int g, int b);
void			my_mlx_pixel_put(t_img_info *img, int x, int y, int color);
int				display(t_mlx_info *mlx, t_img_info *img, t_map_info *map);
//init_draw.c
t_params		init_params(t_point *p1, t_point *p2);
t_point			init_point(t_map_info *map, int x, int y);
//draw.c
int				draw(t_img_info *img, t_map_info *map);
//malloc.c
void			free_tab(char **tab);
int				free_all(char **tab, t_dq *dq);
int				malloc_map_crd(t_dq *dq, t_map_info *map);
int				calloc_map_color(t_dq *dq, t_map_info *map);

#endif