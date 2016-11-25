/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 17:29:51 by vlistrat          #+#    #+#             */
/*   Updated: 2016/11/24 17:29:53 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	move_left(t_wolf *wolf)
{
	OLDDIR_X = DIR_X;
	DIR_X = DIR_X * cos(ROT_SPD) - DIR_Y * sin(ROT_SPD);
	DIR_Y = OLDDIR_X * sin(ROT_SPD) + DIR_Y * cos(ROT_SPD);
	OLD_PLANX = PLANX;
	PLANX = PLANX * cos(ROT_SPD) - PLANY * sin(ROT_SPD);
	PLANY = OLD_PLANX * sin(ROT_SPD) + PLANY * cos(ROT_SPD);
}

static void	move_right(t_wolf *wolf)
{
	OLDDIR_X = DIR_X;
	DIR_X = DIR_X * cos(-ROT_SPD) - DIR_Y * sin(-ROT_SPD);
	DIR_Y = OLDDIR_X * sin(-ROT_SPD) + DIR_Y * cos(-ROT_SPD);
	OLD_PLANX = PLANX;
	PLANX = PLANX * cos(-ROT_SPD) - PLANY * sin(-ROT_SPD);
	PLANY = OLD_PLANX * sin(-ROT_SPD) + PLANY * cos(-ROT_SPD);
}

static void	move_up(t_wolf *wolf)
{
	if (MAP[(int)(POS_X + DIR_X * MOVE_SPD)][(int)(POS_Y)] == 0)
		POS_X += DIR_X * MOVE_SPD;
	if (MAP[(int)(POS_X)][(int)(POS_Y + DIR_Y * MOVE_SPD)] == 0)
		POS_Y += DIR_Y * MOVE_SPD;
}

static void	move_down(t_wolf *wolf)
{
	if (MAP[(int)(POS_X - DIR_X * MOVE_SPD)][(int)(POS_Y)] == 0)
		POS_X -= DIR_X * MOVE_SPD;
	if (MAP[(int)(POS_X)][(int)(POS_Y - DIR_Y * MOVE_SPD)] == 0)
		POS_Y -= DIR_Y * MOVE_SPD;
}

int			move(t_wolf *wolf)
{
	if (CHECK_LEFT == 1)
		move_left(wolf);
	else if (CHECK_RIGHT == 1)
		move_right(wolf);
	if (CHECK_UP == 1)
		move_up(wolf);
	else if (CHECK_DOWN == 1)
		move_down(wolf);
	if (MAP_NB == 2 && POS_X >= 17.9 && POS_Y >= 17.9)
	{
		MAP_NB = 3;
		POS_X = 2;
		POS_Y = 2;
		select_map(wolf);
	}
	new_image(wolf);
	return (0);
}
