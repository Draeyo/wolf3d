#include "w3d.h"

int	ft_exit(t_wolf *wolf)
{
	if (MUSIC)
		system("killall afplay");
	exit(EXIT_SUCCESS);
	return (0);
}
