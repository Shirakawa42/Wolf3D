/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvasseur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 12:06:08 by lvasseur          #+#    #+#             */
/*   Updated: 2017/02/20 16:55:38 by lvasseur         ###   ########.fr       */
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

int		key_input(int keycode, t_all *truc)
{
	if (keycode == ECHAP || keycode == ECHAP_UBUNTU)
	{
		free(truc->map);
		free(truc);
		exit(0);
	}
	if (keycode == 83)
		truc->which = 1;
	else if (keycode == 84)
		truc->which = 2;
	else if (keycode == 85)
		truc->which = 3;
	else if (keycode == 86)
		truc->which = 4;
	else if (keycode == 87)
		truc->which = 5;
	else if (keycode == 88)
		truc->which = 6;
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
	if (truc->map[(int)(truc->player_pos_x + truc->dirx
				* MOVE_SPEED)][(int)truc->player_pos_y] == 0)
		truc->player_pos_x += truc->dirx * MOVE_SPEED;
	if (truc->map[(int)truc->player_pos_x][(int)(truc->player_pos_y
				+ truc->diry * MOVE_SPEED)] == 0)
		truc->player_pos_y += truc->diry * MOVE_SPEED;
}

void	move_down(t_all *truc)
{
	if (truc->map[(int)(truc->player_pos_x - truc->dirx *
				MOVE_SPEED)][(int)truc->player_pos_y] == 0)
		truc->player_pos_x -= truc->dirx * MOVE_SPEED;
	if (truc->map[(int)truc->player_pos_x][(int)(truc->player_pos_y
				- truc->diry * MOVE_SPEED)] == 0)
		truc->player_pos_y -= truc->diry * MOVE_SPEED;
}

void	move_right(t_all *truc)
{
	double	tmp;

	tmp = truc->dirx;
	truc->dirx = truc->dirx * cos(-TURN_SPEED) - truc->diry * sin(-TURN_SPEED);
	truc->diry = tmp * sin(-TURN_SPEED) + truc->diry * cos(-TURN_SPEED);
	tmp = truc->planex;
	truc->planex = truc->planex * cos(-TURN_SPEED) -
		truc->planey * sin(-TURN_SPEED);
	truc->planey = tmp * sin(-TURN_SPEED) + truc->planey * cos(-TURN_SPEED);
}

void	move_left(t_all *truc)
{
	double	tmp;

	tmp = truc->dirx;
	truc->dirx = truc->dirx * cos(TURN_SPEED) - truc->diry * sin(TURN_SPEED);
	truc->diry = tmp * sin(TURN_SPEED) + truc->diry * cos(TURN_SPEED);
	tmp = truc->planex;
	truc->planex = truc->planex * cos(TURN_SPEED) -
		truc->planey * sin(TURN_SPEED);
	truc->planey = tmp * sin(TURN_SPEED) + truc->planey * cos(TURN_SPEED);
}

void	create_cube(t_all *truc)
{
	if (truc->dirx < -0.5 && truc->dirx > -1 && truc->diry < 0.5 && truc->diry
			> -0.5 && truc->map[(int)truc->player_pos_x - 1]
			[(int)truc->player_pos_y] < 15)
		truc->map[(int)truc->player_pos_x - 1][(int)truc->player_pos_y]
			= truc->which;
	if (truc->dirx >= -0.5 && truc->diry < 0.5 && truc->diry > -0.5 && truc->
			map[(int)truc->player_pos_x + 1][(int)truc->player_pos_y] < 15)
		truc->map[(int)truc->player_pos_x + 1][(int)truc->player_pos_y]
			= truc->which;
	if (truc->diry < -0.5 && truc->diry > -1 && truc->dirx < 0.5 && truc->dirx
			> -0.5 && truc->map[(int)truc->player_pos_x]
			[(int)truc->player_pos_y - 1] < 15)
		truc->map[(int)truc->player_pos_x][(int)truc->player_pos_y - 1]
			= truc->which;
	if (truc->diry >= -0.5 && truc->dirx < 0.5 && truc->dirx > -0.5 && truc->
			map[(int)truc->player_pos_x][(int)truc->player_pos_y + 1] < 15)
		truc->map[(int)truc->player_pos_x][(int)truc->player_pos_y + 1]
			= truc->which;
}

void	destroy_cube(t_all *truc)
{
	if (truc->dirx < -0.5 && truc->dirx > -1 && truc->diry < 0.5 && truc->diry
			> -0.5 && truc->map[(int)truc->player_pos_x - 1]
			[(int)truc->player_pos_y] < 15)
		truc->map[(int)truc->player_pos_x - 1][(int)truc->player_pos_y] = 0;
	if (truc->dirx >= -0.5 && truc->diry < 0.5 && truc->diry > -0.5 && truc->
			map[(int)truc->player_pos_x + 1][(int)truc->player_pos_y] < 15)
		truc->map[(int)truc->player_pos_x + 1][(int)truc->player_pos_y] = 0;
	if (truc->diry < -0.5 && truc->diry > -1 && truc->dirx < 0.5 && truc->dirx
			> -0.5 && truc->map[(int)truc->player_pos_x]
			[(int)truc->player_pos_y - 1] < 15)
		truc->map[(int)truc->player_pos_x][(int)truc->player_pos_y - 1] = 0;
	if (truc->diry >= -0.5 && truc->dirx < 0.5 && truc->dirx > -0.5 && truc->
			map[(int)truc->player_pos_x][(int)truc->player_pos_y + 1] < 15)
		truc->map[(int)truc->player_pos_x][(int)truc->player_pos_y + 1] = 0;
}

int		mouse_input(int keycode, int x, int y, t_all *truc)
{
	x = y;
	if (keycode == 1)
		destroy_cube(truc);
	else if (keycode == 3 || keycode == 2)
		create_cube(truc);
	return (0);
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
