#include "fdf.h"
int main(int ac, char **av){
	t_dq dq;
	t_map_info map;
	init_fdf(ac,av,&dq);
	parse_map(&dq,&map);
	printf("cx : %d ",map.central_x);
	printf("cy : %d ",map.central_y);
	printf("\n");
	printf("midx : %d", WIDTH/2 - map.central_x);
	printf("midy : %d", HEIGHT/2 - map.central_y);

}