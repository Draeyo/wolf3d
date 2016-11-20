#include "w3d.h"

void	new_image(t_wolf *wolf)
{
	IMG_P = mlx_new_image(MLX, WIN_X, WIN_Y);
	IMG = mlx_get_data_addr(IMG_P, &BPP, &SL, &END);
	ft_calc(wolf);
	mlx_put_image_to_window(MLX, WIN, IMG_P, 0, 0);
	mlx_destroy_image(MLX, IMG_P);
}
