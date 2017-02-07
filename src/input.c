/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvasseur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 12:06:08 by lvasseur          #+#    #+#             */
/*   Updated: 2017/02/07 17:22:13 by lvasseur         ###   ########.fr       */
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

int		keyboard_input(int keycode, t_all *truc)
{
	if (keycode == 53)
	{
		free(truc);
		exit(0);
	}
	if (keycode == UP)
		truc->player_pos_x += 0.1;
	reload(truc);
	return (0);
}
