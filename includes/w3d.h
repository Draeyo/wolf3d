#ifndef W3D_H
# define W3D_H

# include "libft.h"
# include "mlx.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <math.h>

# define WIN_X 960
# define WIN_Y 720
# define FRAME 0.05
# define ROTSPEED (1.5 * FRAME)
# define MOVESPEED_V (2.0 * FRAME)

# define MLX wolf->mlx
# define WIN wolf->win
# define IMG_P wolf->img_p
# define IMG wolf->img
# define BPP wolf->bpp
# define SL wolf->sl
# define END wolf->end

# define MUSIC wolf->music
# define COLOR wolf->color

# define MAP wolf->map
# define POS_X wolf->posx
# define POS_Y wolf->posy
# define DIR_X wolf->dirx
# define DIR_Y wolf->diry
# define OLD_DIR_X wolf->old_dirx
# define PLANE_X wolf->planex
# define PLANE_Y wolf->planey
# define OLD_PLANE_X wolf->old_planex
# define CAMERA_X wolf->camerax
# define RAYPOS_X wolf->rayposx
# define RAYPOS_Y wolf->rayposy
# define RAYDIR_X wolf->raydirx
# define RAYDIR_Y wolf->raydiry
# define SIDE_DX wolf->sidedistx
# define SIDE_DY wolf->sidedisty
# define DELTA_DX wolf->deltadistx
# define DELTA_DY wolf->deltadisty
# define PWALL_DIST wolf->perpwalldist
# define STEP_X wolf->stepx
# define STEP_Y wolf->stepy
# define HIT wolf->hit
# define SIDE wolf->side
# define MAP_X wolf->mapx
# define MAP_Y wolf->mapy
# define LINE_HEIGHT wolf->lineheight
# define DRAW_START wolf->drawstart
# define DRAW_END wolf->drawend
# define MOVESPEED wolf->movespeed
# define MOVE_FORW wolf->moveforward
# define MOVE_BACK wolf->moveback
# define MOVE_LEFT wolf->moveleft
# define MOVE_RIGHT wolf->moveright

typedef struct	s_wolf
{
	// MLX
	void	*mlx;
	void	*win;
	void	*img_p;
	char	*img;
	int	bpp;
	int	sl;
	int	end;
	// UTILS
	int	music;
	int	color;
	//
	int	map[20][20];
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	old_dirx;
	double	planex;
	double	planey;
	double	old_planex;
	double	camerax;
	double	rayposx;
	double	rayposy;
	double	raydirx;
	double	raydiry;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	double	movespeed;
	int	stepx;
	int	stepy;
	int	hit;
	int	side;
	int	mapx;
	int	mapy;
	int	lineheight;
	int	drawstart;
	int	drawend;
	int	moveforward;
	int	moveback;
	int	moveleft;
	int	moveright;
}		t_wolf;

/*
** MAIN
*/
void		init(t_wolf *wolf);
void		init_map(t_wolf *wolf);
void		ft_calc(t_wolf *wolf);

/*
** HOOK
*/
int		expose(t_wolf *wolf);
int		ft_exit(t_wolf *wolf);
int		move_key(int keycode, t_wolf *wolf);
int		release_key(int keycode, t_wolf *wolf);

/*
** IMAGE
*/
void		new_image(t_wolf *wolf);
void		put_pixel(t_wolf *wolf, int x);

/*
** UTILS & EVENTS
*/
int		move(t_wolf *wolf);

#endif
