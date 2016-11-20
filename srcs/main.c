#include "w3d.h"

int	main(void)
{
	t_wolf	wolf;

	wolf.mlx = mlx_init();
	init(&wolf);
	init_map(&wolf);
	wolf.win = mlx_new_window(wolf.mlx, WIN_X, WIN_Y, "wolf3d");
	new_image(&wolf);
//	mlx_expose_hook(wolf.win, expose, &wolf);
	mlx_hook(wolf.win, 17, (1L << 17), ft_exit, &wolf);
	mlx_hook(wolf.win, 2, (1L << 0), move_key, &wolf);
	mlx_hook(wolf.win, 3, (1L << 1), release_key, &wolf);
	mlx_loop_hook(wolf.mlx, move, &wolf);
	mlx_loop(wolf.mlx);
	return (0);
}
