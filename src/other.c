/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvasseur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 17:42:42 by lvasseur          #+#    #+#             */
/*   Updated: 2017/02/20 17:44:14 by lvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	reload(t_all *truc)
{
	mlx_destroy_image(truc->mlx, truc->img);
	truc->img = mlx_new_image(truc->mlx, W, H);
	truc->data_addr = mlx_get_data_addr(truc->img, &truc->bpx,
			&truc->size, &truc->idgaf);
	find_walls(truc);
}

int		echap_key(t_all *truc)
{
	free(truc->map);
	free(truc);
	exit(0);
	return (0);
}

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
