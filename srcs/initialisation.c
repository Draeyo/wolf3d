/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:56:15 by vlistrat          #+#    #+#             */
/*   Updated: 2016/11/21 14:56:16 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	initialisation(t_wolf *wolf)
{
	POS_X = 18;
	POS_Y = 12;
	DIR_X = -1;
	DIR_Y = 0;
	PLANX = 0;
	PLANY = 0.66;
	MOVE_SPD = MOVE_SPD_VAL;
	MUSIC = 0;
}
