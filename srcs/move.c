#include "w3d.h"

static void	move_forward(t_wolf *wolf)
{
	if (!MAP[(int)(POS_X + DIR_X * MOVESPEED)][(int)POS_Y])
		POS_X += DIR_X * MOVESPEED;
	if (!MAP[(int)POS_X][(int)(POS_Y + DIR_Y * MOVESPEED)])
		POS_Y += DIR_Y * MOVESPEED;
}

static void	move_back(t_wolf *wolf)
{
	if (!MAP[(int)(POS_X - DIR_X * MOVESPEED)][(int)POS_Y])
		POS_X -= DIR_X * MOVESPEED;
	if (!MAP[(int)POS_X][(int)(POS_Y - DIR_Y * MOVESPEED)])
		POS_Y -= DIR_Y * MOVESPEED;
}

static void	move_right(t_wolf *wolf)
{
	OLD_DIR_X = DIR_X;
	DIR_X = DIR_X * cos(-ROTSPEED) - DIR_Y * sin(-ROTSPEED);
	DIR_Y = OLD_DIR_X * sin(-ROTSPEED) + DIR_Y * cos(-ROTSPEED);
	OLD_PLANE_X = PLANE_X;
	PLANE_X = PLANE_X * cos(-ROTSPEED) - PLANE_Y * sin(-ROTSPEED);
	PLANE_Y = OLD_PLANE_X * sin(-ROTSPEED) + PLANE_Y * cos(-ROTSPEED);
}

static void	move_left(t_wolf *wolf)
{
	OLD_DIR_X = DIR_X;
	DIR_X = DIR_X * cos(ROTSPEED) - DIR_Y * sin(ROTSPEED);
	DIR_Y = OLD_DIR_X * sin(ROTSPEED) + DIR_Y * cos(ROTSPEED);
	OLD_PLANE_X = PLANE_X;
	PLANE_X = PLANE_X * cos(ROTSPEED) - PLANE_Y * sin(ROTSPEED);
	PLANE_Y = OLD_PLANE_X * sin(ROTSPEED) + PLANE_Y * cos(ROTSPEED);
}

int	move(t_wolf *wolf)
{
	if (MOVE_FORW)
		move_forward(wolf);
	if (MOVE_BACK)
		move_back(wolf);
	if (MOVE_RIGHT)
		move_right(wolf);
	if (MOVE_LEFT)
		move_left(wolf);
	new_image(wolf);
	return (0);
}
