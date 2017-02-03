/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvasseur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 11:59:30 by lvasseur          #+#    #+#             */
/*   Updated: 2017/02/03 15:05:55 by lvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	init_map(t_all *truc)
{
	int		x;
	int		y;

	x = -1;
	while (++x < 8)
	{
		y = -1;
		while (++y < 8)
			truc->map[x][y] = 0;
	}
	x = -1;
	while (++x < 8)
	{
		truc->map[0][x] = 1;
		truc->map[7][x] = 1;
	}
	x = -1;
	while (++x < 8)
	{
		truc->map[x][0] = 1;
		truc->map[x][7] = 1;
	}
}

void	find_walls(t_all *truc)
{
	int		angle_tmp;
	int		x;

	x = 0;
	angle_tmp = truc->player_view - (PLAYER_FOV / 2);
	while (x < W)
	{
		x++;
	}
}

void	init_values(t_all *truc)
{
	truc->player_pos_x = 448;
	truc->player_pos_y = 448;
	truc->player_view = 45;
	truc->distance = W / tan(PLAYER_FOV / 2);
	truc->angle = PLAYER_FOV / W;
	find_walls(truc);
}

void	init_mlx(t_all *truc)
{
	truc->mlx = mlx_init();
	truc->win = mlx_new_window(truc->mlx, W, H, "Wolf3D");
	truc->img = mlx_new_image(truc->mlx, W, H);
	truc->data_addr = mlx_get_data_addr(truc->img, &truc->bpx,
			&truc->size, &truc->idgaf);
	init_map(truc);
	init_values(truc);
	mlx_key_hook(truc->win, keyboard_input, truc);
	mlx_loop(truc->mlx);
}

int		main(void)
{
	t_all	*truc;

	truc = (t_all*)malloc(sizeof(t_all));
	init_mlx(truc);
	return (0);
}
