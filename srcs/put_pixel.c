/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:57:01 by vlistrat          #+#    #+#             */
/*   Updated: 2016/11/24 14:47:59 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	set_color(t_wolf *wolf)
{
	COLOR = 0xFF00FF;
	if (SIDE == 1)
		COLOR /= 4;
}

void		put_pixel(int x, t_wolf *wolf)
{
	int i;
	int	j;

	j = DRAW_START - 1;
	set_color(wolf);
	while (++j < DRAW_END)
	{
		i = (SLINE * j) + (x * (BPP / 8));
		if (ENDIAN == 0)
		{
			IMG[i] = mlx_get_color_value(MLX, COLOR);
			IMG[++i] = mlx_get_color_value(MLX, COLOR >> 8);
			IMG[++i] = mlx_get_color_value(MLX, COLOR >> 16);
		}
		else
		{
			IMG[i] = mlx_get_color_value(MLX, COLOR >> 16);
			IMG[++i] = mlx_get_color_value(MLX, COLOR >> 8);
			IMG[++i] = mlx_get_color_value(MLX, COLOR);
		}
	}
}
