#include "fdf.h"
typedef struct s_info
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;

}t_info;
#include <stdio.h>
int main(){
	t_vars vars;
	t_info info;

	int width = 500;
	int height = 600;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, width, height,"HI");
	info.img = mlx_new_image(vars.mlx,width,height);
	mlx_get_data_addr(info.img,&info.bits_per_pixel,&info.line_length,&info.endian);
	for(int i=0;i<width-1;i++){
		for(int j=0;j<height-1;j++){


		}
	}
	mlx_put_image_to_window(vars.mlx,vars.win,info.img,0,0);
	mlx_loop(vars.mlx);
}