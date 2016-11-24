/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:57:10 by vlistrat          #+#    #+#             */
/*   Updated: 2016/11/21 14:57:11 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	release_key(int k, t_wolf *wolf)
{
	if (k == 53)
		echap(wolf);
	if (k == 0)
		CHECK_LEFT = 0;
	else if (k == 2)
		CHECK_RIGHT = 0;
	if (k == 1)
		CHECK_DOWN = 0;
	else if (k == 13)
		CHECK_UP = 0;
	return (0);
}
