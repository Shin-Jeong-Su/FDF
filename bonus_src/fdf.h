/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:41:32 by jeshin            #+#    #+#             */
/*   Updated: 2024/03/26 15:30:38 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "my_deque.h"
# include <math.h>
# include <stdio.h>

# define WIDTH 1200
# define HEIGHT 1000

typedef enum e_key_code
{
	KEY_ESC = 53,
	UP_ARROW = 126,
	DOWN_ARROW = 125,
	LEFT_ARROW = 123,
	RIGHT_ARROW = 124,
	COMMAND = 259,
	PLUS = 24,
	MINUS = 27,
	ONE = 18,
	TWO = 19,
	THREE = 20,
	FOUR = 21,
	FIVE = 22,
	SIX = 23,
	HOME = 115,
	TAB = 48
}	t_key_code;

typedef enum e_key_mask
{
	NO_EVENT_MASK = 0L,
	KEY_PRESS = 1L<<0,
	KEY_RELEASE = 1L<<0
}	t_key_mask;

typedef enum e_event
{
	ON_KEYDOWN = 2,
	ON_DESTROY = 17,
}	t_event;

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

typedef struct s_map_info
{
	int				**crd;
	unsigned int	**color;
	int				has_color;
	int				n_col;
	int				n_row;
	int				offset;
	int				central_x;
	int				central_y;
	int				alpha;
	int				beta;
	int				gamma;
	int				ortho_flg;
}	t_map_info;

typedef struct s_fdf_info
{
	t_mlx_info	*mlx;
	t_img_info	*img;
	t_map_info	*map;
}	t_fdf_info;

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
	int				z;
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

//init_fdf.c
int				init_fdf(int ac, char **av, t_dq *dq);
//parse_map.c
int				parse_map(t_dq *dq, t_map_info *map);
void			get_central_pos(t_map_info *map);
//parse_map_utils.c
int				has_color_value(t_dq *dq);
unsigned int	cvrt_str_to_color(char *s);
//display.c
int				display(t_mlx_info *mlx, t_img_info *img, t_map_info *map);
int				prt(t_mlx_info *mlx, t_img_info *img, t_map_info *map);
//display_utils.c
int				create_argb(int a, int r, int g, int b);
void			my_mlx_pixel_put(t_img_info *img, int x, int y, int color);
void			get_center(t_img_info *img, t_map_info *map);
//init_point.c
t_params		init_params(t_point *p1, t_point *p2);
t_point			init_point(t_map_info *map, int x, int y);
//draw.c
int				draw(t_img_info *img, t_map_info *map);
//event_bonus.c
int				hook_zoom(int keycode, t_fdf_info *fdf);
int				hook_translate(int keycode, t_fdf_info *fdf);
int				hook_rotate(int keycode, t_fdf_info *fdf);
int				hook_return_to_original(t_fdf_info *fdf);
//event_bonus2.c
int				hook_ortho_project(t_fdf_info *fdf);
//malloc.c
void			free_tab(char **tab);
int				free_all(char **tab, t_dq *dq);
int				malloc_map_crd(t_dq *dq, t_map_info *map);
int				calloc_map_color(t_dq *dq, t_map_info *map);
//rotation.c
void			rotate(t_point *p, t_map_info *map);
#endif