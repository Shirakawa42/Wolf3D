/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvasseur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 11:58:10 by lvasseur          #+#    #+#             */
/*   Updated: 2017/02/03 13:24:40 by lvasseur         ###   ########.fr       */
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

# define W 320
# define H 200
# define CUBE 64
# define WALL_COLOR 0x0000FFFF
# define PLAYER_FOV 60
# define PLAYER_HEIGHT 32

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
	int			player_pos_x;
	int			player_pos_y;
	double		player_view;
	double		distance;
	double		angle;
	int			x1;
	int			x2;
	int			y1;
	int			y2;
	int			ray_lenght;
}				t_all;

int				keyboard_input(int keycode, t_all *truc);
void			ray_caster(t_all *truc, int x);

#endif
