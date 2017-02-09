/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvasseur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 11:59:30 by lvasseur          #+#    #+#             */
/*   Updated: 2017/02/09 17:11:38 by lvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	find_walls(t_all *truc)
{
	int		x;
	int map[MAP_X][MAP_Y] =
	{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};

	x = 0;
	while (x < W)
	{
		ray_caster(truc, x, map);
		x++;
	}
	mlx_put_image_to_window(truc->mlx, truc->win, truc->img, 0, 0);
}

void	init_values(t_all *truc)
{
	truc->player_pos_x = 2;
	truc->player_pos_y = 2;
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
	truc->img_sky = mlx_jpeg_read(truc->mlx, "../textures/SKY.jpg");
	find_walls(truc);
}

void	init_mlx(t_all *truc)
{
	truc->mlx = mlx_init();
	truc->win = mlx_new_window(truc->mlx, W, H, "Wolf3D");
	truc->img = mlx_new_image(truc->mlx, W, H);
	truc->img_sky = mlx_new_image(truc->mlx, W, H);
	truc->data_addr = mlx_get_data_addr(truc->img, &truc->bpx,
			&truc->size, &truc->idgaf);
	truc->data_addr_sky = mlx_get_data_addr(truc->img_sky, &truc->bpx_sky,
			&truc->size_sky, &truc->idgaf_sky);
	init_values(truc);
	mlx_do_key_autorepeatoff(truc->mlx);
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
