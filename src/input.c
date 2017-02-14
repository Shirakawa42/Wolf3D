/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvasseur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 12:06:08 by lvasseur          #+#    #+#             */
/*   Updated: 2017/02/14 18:01:29 by lvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include <stdio.h>

void	reload(t_all *truc)
{
	mlx_destroy_image(truc->mlx, truc->img);
	truc->img = mlx_new_image(truc->mlx, W, H);
	truc->data_addr = mlx_get_data_addr(truc->img, &truc->bpx,
			&truc->size, &truc->idgaf);
	find_walls(truc);
}

int		key_input(int keycode, t_all *truc)
{
	if (keycode == ECHAP || keycode == ECHAP_UBUNTU)
	{
		free(truc->map);
		free(truc);
		exit(0);
	}
	if (keycode == UP || keycode == UP_UBUNTU)
		truc->player_moving_up = !truc->player_moving_up;
	else if (keycode == DOWN || keycode == DOWN_UBUNTU)
		truc->player_moving_down = !truc->player_moving_down;
	else if (keycode == LEFT || keycode == LEFT_UBUNTU)
		truc->player_moving_left = !truc->player_moving_left;
	else if (keycode == RIGHT || keycode == RIGHT_UBUNTU)
		truc->player_moving_right = !truc->player_moving_right;
	return (0);
}

void	move_up(t_all *truc)
{
	if (truc->map[(int)(truc->player_pos_x + truc->dirX * MOVE_SPEED)][(int)truc->player_pos_y] == 0)
		truc->player_pos_x += truc->dirX * MOVE_SPEED;
	if (truc->map[(int)truc->player_pos_x][(int)(truc->player_pos_y + truc->dirY * MOVE_SPEED)] == 0)
		truc->player_pos_y += truc->dirY * MOVE_SPEED;
}

void	move_down(t_all *truc)
{
	if (truc->map[(int)(truc->player_pos_x - truc->dirX * MOVE_SPEED)][(int)truc->player_pos_y] == 0)
		truc->player_pos_x -= truc->dirX * MOVE_SPEED;
	if (truc->map[(int)truc->player_pos_x][(int)(truc->player_pos_y - truc->dirY * MOVE_SPEED)] == 0)
		truc->player_pos_y -= truc->dirY * MOVE_SPEED;
}

void	move_right(t_all *truc)
{
	double	tmp;

	tmp = truc->dirX;
	truc->dirX = truc->dirX * cos(-TURN_SPEED) - truc->dirY * sin(-TURN_SPEED);
	truc->dirY = tmp * sin(-TURN_SPEED) + truc->dirY * cos(-TURN_SPEED);
	tmp = truc->planeX;
	truc->planeX = truc->planeX * cos(-TURN_SPEED) - truc->planeY * sin(-TURN_SPEED);
	truc->planeY = tmp * sin(-TURN_SPEED) + truc->planeY * cos(-TURN_SPEED);
}

void	move_left(t_all *truc)
{
	double	tmp;

	tmp = truc->dirX;
	truc->dirX = truc->dirX * cos(TURN_SPEED) - truc->dirY * sin(TURN_SPEED);
	truc->dirY = tmp * sin(TURN_SPEED) + truc->dirY * cos(TURN_SPEED);
	tmp = truc->planeX;
	truc->planeX = truc->planeX * cos(TURN_SPEED) - truc->planeY * sin(TURN_SPEED);
	truc->planeY = tmp * sin(TURN_SPEED) + truc->planeY * cos(TURN_SPEED);
}

int		loop_hook(t_all *truc)
{
	truc->oldframe = clock();
	if (truc->frame > truc->oldframe)
		return (0);
	truc->frame = truc->oldframe + (CLOCKS_PER_SEC / 100);
	if (truc->player_moving_up != 0)
		move_up(truc);
	if (truc->player_moving_down != 0)
		move_down(truc);
	if (truc->player_moving_left != 0)
		move_left(truc);
	if (truc->player_moving_right != 0)
		move_right(truc);
	reload(truc);
	return (0);
}
