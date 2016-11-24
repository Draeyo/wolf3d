/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:56:52 by vlistrat          #+#    #+#             */
/*   Updated: 2016/11/21 14:56:54 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	press(int k, t_wolf *wolf)
{
	if (k == 0)
		CHECK_LEFT = 1;
	else if (k == 2)
		CHECK_RIGHT = 1;
	if (k == 1)
		CHECK_DOWN = 1;
	else if (k == 13)
		CHECK_UP = 1;
	new_image(wolf);
	return (0);
}
