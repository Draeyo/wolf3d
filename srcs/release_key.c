/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:57:10 by vlistrat          #+#    #+#             */
/*   Updated: 2016/11/25 08:00:42 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		change_map(int k, t_wolf *wolf)
{
	if (k == 19)
	{
		POS_X = 18.5;
		POS_Y = 12.5;
		MAP_NB = 1;
	}
	if (k == 20)
	{
		POS_X = 10.5;
		POS_Y = 10.5;
		MAP_NB = 2;
	}
	if (k == 21)
	{
		POS_X = 2;
		POS_Y = 2;
		MAP_NB = 3;
	}
	select_map(wolf);
}

static void		music_key(t_wolf *wolf)
{
	if (CHECK_MUSIC)
		system("killall afplay");
	CHECK_MUSIC = (CHECK_MUSIC ? 0 : 1);
	MUSIC = MAP_NB;
	start_music(wolf);
}

void		start_music(t_wolf *wolf)
{
	if (CHECK_MUSIC)
	{
		if (MUSIC == 1)
			system("afplay ./music/zelda.mp3 &");
		else if (MUSIC == 2)
			system("afplay ./music/megaman.mp3 &");
		else if (MUSIC == 3)
			system("afplay ./music/pokemon.mp3 &");
	}
}

int				release_key(int k, t_wolf *wolf)
{
	if (k == 53)
		echap(wolf);
	if (k == 18)
	{
		initialisation(wolf);
		new_image(wolf);
	}
	if (k >= 19 && k <= 21)
		change_map(k, wolf);
	if (k == 0)
		CHECK_LEFT = 0;
	else if (k == 2)
		CHECK_RIGHT = 0;
	if (k == 1)
		CHECK_DOWN = 0;
	else if (k == 13)
		CHECK_UP = 0;
	if (k == 46)
		music_key(wolf);
	return (0);
}
