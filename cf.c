/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cf.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:16:41 by jeshin            #+#    #+#             */
/*   Updated: 2024/03/04 19:16:34 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx/mlx.h"
#include <unistd.h>
#include <stdlib.h>

typedef struct s_data{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
}	t_data;

typedef struct s_vars{
	void *mlx;
	void *win;
}		t_vars;

//////////////////////////////////////////

void my_mlx_pixel_put(t_data *data, int x,int y,int color);
int	key_hook(int keycode ,t_vars *vars);
int	exit_hook();
int	prtimage();
///////////////////////////////////////////

int main(){
	prtimage();
	return (0);
}

int	key_hook(int keycode ,t_vars *vars){
	if (keycode ==53)
	{
		mlx_destroy_window(vars->mlx,vars->win);
		exit(0);
	}
	return (0);
}

void my_mlx_pixel_put(t_data *data, int x,int y,int color){
	char *dst;
	dst = data->addr + (y *data->line_length + x*(data->bits_per_pixel)/8);
	*(unsigned int *)dst = color;
}

int exit_hook(){
	exit(0);
}

int prtimage(){
	int color;
	t_vars vars;
	t_data image;

	int img_width = 1920;
	int img_height = 1080;
	vars.mlx=mlx_init();
	vars.win=mlx_new_window(vars.mlx, img_width, img_height, "HELL");
	image.img=mlx_new_image(vars.mlx,img_width,img_height);
	image.addr=mlx_get_data_addr(image.img, &image.bits_per_pixel,&image.line_length, &image.endian);
	for(int i=0;i<img_height-1;i++){
		for(int j=0;j<img_width-1;j++){
			double r = (double)(img_width-j)/(img_width-1);
			double g = (double)(i)/(img_height-1);
			double b =1;
			color = ((int)(255.999*r)<<16)+((int)(255.999*g)<<8)+((int)(255.999*b));
			my_mlx_pixel_put(&image,j,i,color);
		}
	}
	
	mlx_put_image_to_window(vars.mlx,vars.win,image.img,0,0);
	mlx_key_hook(vars.win,key_hook,&vars);
	mlx_hook(vars.win,17,0,exit_hook,0);
	mlx_loop(vars.mlx);
	return(0);
}