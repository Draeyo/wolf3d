#include "w3d.h"

void	init(t_wolf *wolf)
{
	POS_X = 19;
	POS_Y = 19;
	DIR_X = -1;
	DIR_Y = 0;
	PLANE_X = 0;
	PLANE_Y = 0.66;
	MUSIC = 0;
	COLOR = 0xF0F0FF;
	MOVESPEED = MOVESPEED_V;
	MOVE_FORW = 0;
	MOVE_BACK = 0;
	MOVE_LEFT = 0;
	MOVE_RIGHT = 0;
	HIT = 0;
}
