#include "w3d.h"

void	put_pixel(t_wolf *wolf, int x)
{
	int	value;
	int	start;

	start = DRAW_START - 1;
	value = 0;
	if (SIDE == 1)
		COLOR /= 4;
	while (++start < DRAW_END)
	{
		value = (SL * start) + (x * (BPP / 8));
		if (END == 0)
		{
			IMG[value] = COLOR;
			IMG[++value] = COLOR >> 8;
			IMG[++value] = COLOR >> 16;
		}
		else
		{
			IMG[value] = COLOR >> 16;
			IMG[value] = COLOR >> 8;
			IMG[value] = COLOR;
		}
	}
}
