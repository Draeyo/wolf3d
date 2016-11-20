#include "w3d.h"

int	move_key(int keycode, t_wolf *wolf)
{
	if (keycode == 13)
		MOVE_FORW = 1;
	else if (keycode == 1)
		MOVE_BACK = 1;
	if (keycode == 0)
		MOVE_LEFT = 1;
	else if (keycode == 2)
		MOVE_RIGHT = 1;
	new_image(wolf);
	return (0);
}

int	release_key(int keycode, t_wolf *wolf)
{
	if (keycode == 53)
		ft_exit(wolf);
	if (keycode == 13)
		MOVE_FORW = 0;
	else if (keycode == 1)
		MOVE_BACK = 0;
	if (keycode == 0)
		MOVE_LEFT = 0;
	else if (keycode == 2)
		MOVE_RIGHT = 0;
	return (0);
}
