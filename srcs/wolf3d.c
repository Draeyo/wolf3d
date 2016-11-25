/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 17:29:59 by vlistrat          #+#    #+#             */
/*   Updated: 2016/11/25 08:01:01 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	new_image(t_wolf *wolf)
{
	IMG_P = mlx_new_image(MLX, WIN_X, WIN_Y);
	IMG = mlx_get_data_addr(IMG_P, &BPP, &SLINE, &ENDIAN);
	ft_calc(wolf);
	mlx_put_image_to_window(MLX, WIN, IMG_P, 0, 0);
	mlx_destroy_image(MLX, IMG_P);
}

void	wolf3d(t_wolf *wolf)
{
	initialisation(wolf);
	select_map(wolf);
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, WIN_X, WIN_Y, "wolf3d");
	new_image(wolf);
	mlx_expose_hook(WIN, expose, wolf);
	mlx_hook(WIN, 17, (1L << 17), echap, wolf);
	mlx_hook(WIN, 2, (1L << 0), press, wolf);
	mlx_hook(WIN, 3, (1L << 1), release_key, wolf);
	mlx_loop_hook(MLX, move, wolf);
	mlx_loop(MLX);
}
