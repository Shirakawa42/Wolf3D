/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvasseur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 11:59:30 by lvasseur          #+#    #+#             */
/*   Updated: 2017/02/20 17:00:40 by lvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	init_map_2(t_all *truc, int x, int y, int i)
{
	int		j;

	while (++i < x)
	{
		j = -1;
		while (++j < y)
		{
			if (i == 0)
				truc->map[i][j] = 15;
			else if (i == x - 1)
				truc->map[i][j] = 16;
			else if (j == y - 1)
				truc->map[i][j] = 17;
			else if (j == 0)
				truc->map[i][j] = 18;
			else
				truc->map[i][j] = (int)(rand() % 8 + 3);
			if (truc->map[i][j] >= 3 + truc->dens && truc->map[i][j] <= 10)
				truc->map[i][j] = 0;
		}
		ft_putstr("\nLoading: ");
		ft_putnbr((int)(((double)(i * j) / (double)(x * y)) * (double)100));
		ft_putchar('%');
	}
}

void	init_map(t_all *truc, int x, int y)
{
	int		i;

	srand(time(NULL));
	i = 0;
	if ((truc->map = (int**)malloc(sizeof(int*) * x)) == 0)
		return ;
	while (i < x)
		if ((truc->map[i++] = (int*)malloc(sizeof(int) * y)) == 0)
			return ;
	i = -1;
	init_map_2(truc, x, y, i);
	ft_putendl("\nLoading Complete !");
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
	int		x_y[2];

	x_y[0] = ft_atoi(av[1]);
	x_y[1] = ft_atoi(av[2]);
	if (x_y[0] <= 2)
		x_y[0] = 3;
	if (x_y[1] <= 2)
		x_y[1] = 3;
	if (x_y[0] > 30000)
		x_y[0] = 30000;
	if (x_y[1] > 30000)
		x_y[1] = 30000;
	truc->dirx = -1;
	truc->diry = 0;
	truc->planex = 0;
	truc->planey = 0.66;
	truc->frame = 0;
	truc->oldframe = 0;
	truc->player_moving_up = 0;
	truc->player_moving_left = 0;
	truc->player_moving_down = 0;
	truc->player_moving_right = 0;
	truc->which = 1;
	init_map(truc, x_y[0], x_y[1]);
	find_walls(truc);
}

void	init_mlx(t_all *truc, char **av)
{
	if ((truc->dens = ft_atoi(av[3])) < 0)
		truc->dens = 0;
	if (truc->dens > 4)
		truc->dens = 4;
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
	mlx_mouse_hook(truc->win, mouse_input, truc);
	mlx_loop(truc->mlx);
}

int		main(int ac, char **av)
{
	t_all	*truc;

	if (ac != 4)
	{
		ft_putstr("usage: ./Wolf3D \"map_size_x (max 25000)\" \"map_size_y");
		ft_putstr(" (max 25000)\" \"wall_density (0 to 4)\"\n");
		return (0);
	}
	if ((truc = (t_all*)malloc(sizeof(t_all))) == 0)
		return (0);
	init_mlx(truc, av);
	return (0);
}
