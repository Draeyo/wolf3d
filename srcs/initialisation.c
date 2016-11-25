/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:56:15 by vlistrat          #+#    #+#             */
/*   Updated: 2016/11/25 07:57:54 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	initialisation(t_wolf *wolf)
{
	POS_X = 18.5;
	POS_Y = 12.5;
	DIR_X = -1;
	DIR_Y = 0;
	PLANX = 0;
	PLANY = 0.66;
	MOVE_SPD = MOVE_SPD_VAL;
	MUSIC = 1;
	CHECK_MUSIC = 0;
	MAP_NB = 1;
}
