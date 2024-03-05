#include "fdf.h"
typedef struct data
{
	char *addr;
	char *img;

} t_data;
#include <stdio.h>
int main(){
	t_vars vars;
	t_data data;
	int width = 500;
	int height = 900;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, width, height,"HI");
	data.img = mlx_new_image(vars.mlx,width,height);
	for(int i=0;i<width-1;i++){
		for(int j=0;j<height-1;j++){
			mlx_put_image_to_window(vars.mlx,vars.win,data.img,j,i);
		}
	}
	mlx_loop(vars.mlx);
}