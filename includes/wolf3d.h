/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvasseur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 11:58:10 by lvasseur          #+#    #+#             */
/*   Updated: 2017/02/15 16:35:40 by lvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H

# define WOLF3D_H

# include <stdlib.h>
# include "../libft/libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include <unistd.h>
# include <time.h>

# define W 2464
# define H 1386
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define ECHAP 53
# define ECHAP_UBUNTU 65307
# define UP_UBUNTU 65362
# define DOWN_UBUNTU 65364
# define LEFT_UBUNTU 65361
# define RIGHT_UBUNTU 65363
# define MOVE_SPEED 0.09
# define TURN_SPEED 0.06

typedef struct	s_img
{
	void		*img;
	char		*data_addr;
	int			idgaf;
	int			size;
	int			bpx;
	int			w;
	int			h;
}				t_img;

typedef struct	s_all
{
	void		*win;
	void		*mlx;
	int			bpx;
	int			size;
	char		*data_addr;
	void		*img;
	int			idgaf;
	double		player_pos_x;
	double		player_pos_y;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	double		cameraX;
	double		rayPosX;
	double		rayPosY;
	double		rayDirX;
	double		rayDirY;
	int			mapX;
	int			mapY;
	double		sideDistX;
	double		sideDistY;
	double		deltaDistX;
	double		deltaDistY;
	double		perpWallDist;
	int			stepX;
	int			stepY;
	int			hit;
	int			side;
	int			lineHeight;
	int			drawStart;
	int			drawEnd;
	double		fps;
	int			player_moving_up;
	int			player_moving_down;
	int			player_moving_left;
	int			player_moving_right;
	double		frame;
	double		oldframe;
	int			**map;
	t_img		sky;
}				t_all;

void			ray_caster(t_all *truc, int x);
void			find_walls(t_all *truc);
int				loop_hook(t_all *truc);
int				key_input(int keycode, t_all *truc);

#endif
