/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:57:01 by vlistrat          #+#    #+#             */
/*   Updated: 2016/11/25 09:32:06 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	set_color(t_wolf *wolf)
{
	if (SIDE && STEP_Y > 0)
		COLOR = 0x0000FF;
	else if (SIDE && STEP_Y < 0)
		COLOR = 0x00FF00;
	else if (!SIDE && STEP_X > 0)
		COLOR = 0xFF0000;
	else
		COLOR = 0x00FFFF;
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
