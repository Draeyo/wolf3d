/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:57:31 by vlistrat          #+#    #+#             */
/*   Updated: 2016/11/24 14:46:50 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "libft.h"
# include <fcntl.h>
# include "mlx.h"
# include <math.h>

# define WIN_X 1280
# define WIN_Y 720
# define FRAME 0.05
# define ROT_SPD (1.5 * FRAME)
# define MOVE_SPD_VAL (2.3 * FRAME)

# define MLX wolf->mlx
# define WIN wolf->win
# define IMG_P wolf->img_p
# define IMG wolf->img
# define BPP wolf->bpp
# define ENDIAN wolf->endian
# define SLINE wolf->sline
# define COLOR wolf->color

# define MUSIC wolf->music

# define MAPX wolf->mapx
# define MAPY wolf->mapy
# define MAP wolf->map
# define CHECK_LEFT wolf->check_left
# define CHECK_RIGHT wolf->check_right
# define CHECK_UP wolf->check_up
# define CHECK_DOWN wolf->check_down

# define POS_X  wolf->pos.x
# define POS_Y  wolf->pos.y
# define DIR_X wolf->d_x
# define OLDDIR_X wolf->dold_x
# define DIR_Y wolf->d_y
# define PLANX wolf->planx
# define OLD_PLANX wolf->old_planx
# define PLANY wolf->plany
# define CAMX wolf->camx

# define RAY_PX wolf->ray_px
# define RAY_PY wolf->ray_py
# define RAY_DX wolf->ray_dx
# define RAY_DY wolf->ray_dy
# define PWALL_DIST wolf->perp_wall_dist
# define SIDE_DX wolf->side_dx
# define SIDE_DY wolf->side_dy
# define DELTA_DX wolf->delta_dx
# define DELTA_DY wolf->delta_dy
# define STEP_X wolf->step_x
# define STEP_Y wolf->step_y
# define HIT wolf->hit
# define SIDE wolf->side
# define LINE_H wolf->line_h

# define DRAW_START wolf->draw_start
# define DRAW_END wolf->draw_end
# define MOVE_SPD wolf->move_spd

typedef struct	s_pos
{
	double		x;
	double		y;
}				t_pos;

typedef struct	s_wolf
{
	void		*mlx;
	void		*win;
	void		*img_p;
	char		*img;
	int			win_x;
	int			win_y;
	int			bpp;
	int			endian;
	int			sline;

	int			map[20][20];
	int			mapx;
	int			mapy;
	t_pos		pos;
	double		d_x;
	double		dold_x;
	double		d_y;
	double		planx;
	double		old_planx;
	double		plany;
	double		move_spd;

	double		camx;
	double		ray_px;
	double		ray_py;
	double		ray_dx;
	double		ray_dy;
	double		side_dx;
	double		side_dy;
	double		delta_dx;
	double		delta_dy;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_h;
	int			check_left;
	int			check_right;
	int			check_up;
	int			check_down;

	int			color;
	int			draw_start;
	int			draw_end;

	int			music;
}				t_wolf;

void			wolf3d(t_wolf *wolf);
void			new_image(t_wolf *wolf);
void			initialisation(t_wolf *wolf);

void			map(t_wolf *wolf);
void			complete_map(int map_tmp[20][20], t_wolf *wolf);

void			ft_calc(t_wolf *wolf);
void			put_pixel(int x, t_wolf *wolf);

int				echap(t_wolf *wolf);
int				press(int k, t_wolf *wolf);
int				release_key(int k, t_wolf *wolf);
int				move(t_wolf *wolf);

#endif
