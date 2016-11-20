#include "w3d.h"

static void	get_values(int x, t_wolf *wolf)
{
	CAMERA_X = 2 * x / (double)WIN_X - 1;
	RAYPOS_X = POS_X;
	RAYPOS_Y = POS_Y;
	RAYDIR_X = DIR_X + PLANE_X * CAMERA_X;
	RAYDIR_Y = DIR_Y + PLANE_Y * CAMERA_X;
	MAP_X = (int)RAYPOS_X;
	MAP_Y = (int)RAYPOS_Y;
	DELTA_DX = sqrt(1 + (RAYDIR_Y * RAYDIR_Y) / (RAYDIR_X * RAYDIR_X));
	DELTA_DY = sqrt(1 + (RAYDIR_X * RAYDIR_X) / (RAYDIR_Y * RAYDIR_Y));
	HIT = 0;
}

static void	calc_dist(t_wolf *wolf)
{
	if (RAYDIR_X < 0)
	{
		STEP_X = -1;
		SIDE_DX = (RAYPOS_X - MAP_X) * DELTA_DX;
	}
	else
	{
		STEP_X = 1;
		SIDE_DX = (MAP_X + 1.0 - RAYPOS_X) * DELTA_DX;
	}
	if (RAYDIR_Y < 0)
	{
		STEP_Y = -1;
		SIDE_DY = (RAYPOS_Y - MAP_Y) * DELTA_DY;
	}
	else
	{
		STEP_Y = 1;
		SIDE_DY = (MAP_Y + 1.0 - RAYPOS_Y) * DELTA_DY;
	}
}

static void	wall_pos(t_wolf *wolf)
{
	while (HIT == 0)
	{
		if (SIDE_DX < SIDE_DY)
		{
			SIDE_DX += DELTA_DX;
			MAP_X += STEP_X;
			SIDE = 0;
		}
		else
		{
			SIDE_DY += DELTA_DY;
			MAP_Y += STEP_Y;
			SIDE = 1;
		}
		if (MAP[MAP_X][MAP_Y] > 0)
			HIT = 1;
	}
}

void	ft_calc(t_wolf *wolf)
{
	int	x;

	x = -1;
	while (++x < WIN_X)
	{
		get_values(x, wolf);
		calc_dist(wolf);
		wall_pos(wolf);
		if (SIDE == 0)
			PWALL_DIST = (MAP_X - RAYPOS_X + (1 - STEP_X) / 2) / RAYDIR_X;
		else
			PWALL_DIST = (MAP_Y - RAYPOS_Y + (1 - STEP_Y) / 2) / RAYDIR_Y;
		LINE_HEIGHT = (int)(WIN_Y / PWALL_DIST);
		if ((DRAW_START = -LINE_HEIGHT / 2 + WIN_Y / 2) < 0)
			DRAW_START = 0;
		if ((DRAW_END = LINE_HEIGHT / 2 + WIN_Y / 2) >= WIN_Y)
			DRAW_END = WIN_Y - 1;
		put_pixel(wolf, x);
	}
}
