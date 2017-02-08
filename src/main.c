/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvasseur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 11:59:30 by lvasseur          #+#    #+#             */
/*   Updated: 2017/02/07 17:16:12 by lvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	init_map(t_all *truc)
{
	int		x;
	int		y;

	x = -1;
	while (++x < 32)
	{
		y = -1;
		while (++y < 32)
			truc->map[x][y] = 0;
	}
	x = -1;
	while (++x < 32)
	{
		truc->map[0][x] = 1;
		truc->map[31][x] = 1;
	}
	x = -1;
	while (++x < 32)
	{
		truc->map[x][0] = 1;
		truc->map[x][31] = 1;
	}
	truc->map[16][7] = 1;
}

void	find_walls(t_all *truc)
{
	int		x;

	x = 0;
	while (x < W)
	{
		ray_caster(truc, x);
		x++;
	}
	mlx_put_image_to_window(truc->mlx, truc->win, truc->img, 0, 0);
}

void	init_values(t_all *truc)
{
	truc->player_pos_x = 6;
	truc->player_pos_y = 6;
	truc->dirX = -1;
	truc->dirY = 0;
	truc->planeX = 0;
	truc->planeY = 0.66;
	truc->frame = 0;
	truc->oldframe = 0;
	truc->player_moving_up = 0;
	truc->player_moving_left = 0;
	truc->player_moving_down = 0;
	truc->player_moving_right = 0;
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
	mlx_loop_hook(truc->mlx, loop_hook, truc);
	mlx_hook(truc->win, 2, 1L<<0, key_input, truc);
	mlx_key_hook(truc->win, key_input, truc);
	mlx_loop(truc->mlx);
}

int		main(void)
{
	t_all	*truc;

	truc = (t_all*)malloc(sizeof(t_all));
	init_mlx(truc);
	return (0);
}
