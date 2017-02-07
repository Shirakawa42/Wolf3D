/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvasseur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 11:58:10 by lvasseur          #+#    #+#             */
/*   Updated: 2017/02/07 17:24:58 by lvasseur         ###   ########.fr       */
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

# define W 1280
# define H 720
# define CUBE 64
# define WALL_COLOR 0x0000FFFF
# define PLAYER_FOV 60
# define PLAYER_HEIGHT 32
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

typedef struct	s_all
{
	void		*win;
	void		*mlx;
	int			bpx;
	int			size;
	char		*data_addr;
	void		*img;
	int			idgaf;
	int			map[8][8];
	double		player_pos_x;
	double		player_pos_y;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	double		time;
	double		oldtime;
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
}				t_all;

int				keyboard_input(int keycode, t_all *truc);
void			ray_caster(t_all *truc, int x);
void			find_walls(t_all *truc);

#endif
