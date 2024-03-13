#include "fdf.h"
#include <stdio.h>

typedef struct s_info
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;

}t_img;

int	create_argb(int a, int r, int g, int b)
{
	int color;

	color = (a << 24) + (r << 16) + (g << 8) + b;
	return (color);
}

void my_mlx_pixel_put(t_img *img, int x,int y, int color)
{
	char *dst;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	hook_esc_to_exit(int keycode ,t_vars *vars){
	if (keycode ==53)
	{
		mlx_destroy_window(vars->mlx,vars->win);
		exit(0);
	}
	return (0);
}
int	hook_test_esc(int keycode){
	if (keycode ==53)
		printf("Exited Fdf");
	return (0);
}
#define PI 3.1415922653
#include <math.h>
int main(){
	t_vars vars;
	t_img img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, width, height,"HI");
	img.img = mlx_new_image(vars.mlx,width,height);
	img.addr = mlx_get_data_addr(img.img,&(img.bits_per_pixel),&(img.line_length),&(img.endian));
	int R = 100;
	int th = (PI/180) * 30;
	for(int i=0;i<height;i++){
		for(int j=0;j<width;j++){
			int x = j*cos(th) -i*sin(th);
			int y = j*sin(th) +i*cos(th);
			if ((y-512)*(y-512) + (x-640)*(x-640) <= R*R ){
			// if ((j-512)*(j-512) + (i-640)*(i-640) <= R*R &&(j-512)*(j-512) + (i-640)*(i-640) >= (R-1)*(R-1)){
				my_mlx_pixel_put(&img,y,x,create_argb(0,100,150,50));
			}
			// else
			// 	my_mlx_pixel_put(&img,j,i,create_argb(0,255,255,255));
		}
	}
	mlx_put_image_to_window(vars.mlx,vars.win,img.img,0,0);
	mlx_hook(vars.win,2,1L<<2,hook_esc_to_exit,&vars);
	// mlx_hook(vars.win,2,1L<<2,hook_test_esc,0);
	// mlx_key_hook(vars.win,hook_esc_to_exit,&vars);
	mlx_loop(vars.mlx);
}