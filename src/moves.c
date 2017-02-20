/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvasseur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 17:41:48 by lvasseur          #+#    #+#             */
/*   Updated: 2017/02/20 17:41:50 by lvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

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
