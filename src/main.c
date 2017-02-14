/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvasseur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 11:59:30 by lvasseur          #+#    #+#             */
/*   Updated: 2017/02/14 18:19:31 by lvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	init_map(t_all *truc, int x, int y)
{
	int		i;
	int		j;

	srand(time(NULL));
	i = 0;
	truc->map = (int**)malloc(sizeof(int*) * x);
	while (i < x)
		truc->map[i++] = (int*)malloc(sizeof(int) * y);
	i = 0;
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			if (i == 0 || i == x || j == y || j == 0)
				truc->map[i][j] = 1;
			else
				truc->map[i][j] = (int)(rand() % 3);
			if (truc->map[i][j] == 2 || truc->map[i][j] == 3)
				truc->map[i][j] = 0;
			j++;
		}
		i++;
	}
	truc->map[(int)(x / 2)][(int)(y / 2)] = 0;
	truc->player_pos_x = (int)(x / 2);
	truc->player_pos_y = (int)(y / 2);
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

void	init_values(t_all *truc, char **av)
{
	int		x_param;
	int		y_param;

	x_param = ft_atoi(av[1]);
	y_param = ft_atoi(av[2]);
	if (x_param <= 2)
		x_param = 3;
	if (y_param <= 2)
		y_param = 3;
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
	init_map(truc, x_param, y_param);
	find_walls(truc);
}

void	init_mlx(t_all *truc, char **av)
{
	truc->mlx = mlx_init();
	truc->win = mlx_new_window(truc->mlx, W, H, "Wolf3D");
	truc->img = mlx_new_image(truc->mlx, W, H);
	truc->data_addr = mlx_get_data_addr(truc->img, &truc->bpx,
			&truc->size, &truc->idgaf);
	init_values(truc, av);
	mlx_do_key_autorepeatoff(truc->mlx);
	mlx_loop_hook(truc->mlx, loop_hook, truc);
	mlx_hook(truc->win, 2, 1L<<0, key_input, truc);
	mlx_key_hook(truc->win, key_input, truc);
	mlx_loop(truc->mlx);
}

int		main(int ac, char **av)
{
	t_all	*truc;
	char	*path;

	if (ac != 3)
		return (0);
	path = ft_strdup("./../textures/CIEL.xpm");
	truc = (t_all*)malloc(sizeof(t_all));
	init_mlx(truc, av);
	return (0);
}
