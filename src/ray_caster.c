/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_caster.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvasseur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 13:30:57 by lvasseur          #+#    #+#             */
/*   Updated: 2017/02/21 16:13:22 by lvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	step(t_all *truc)
{
	if (truc->raydirx < 0)
	{
		truc->stepx = -1;
		truc->sidedistx = (truc->rayposx - truc->mapx) * truc->deltadistx;
	}
	else
	{
		truc->stepx = 1;
		truc->sidedistx = (truc->mapx + 1.0 - truc->rayposx) * truc->deltadistx;
	}
	if (truc->raydiry < 0)
	{
		truc->stepy = -1;
		truc->sidedisty = (truc->rayposy - truc->mapy) * truc->deltadisty;
	}
	else
	{
		truc->stepy = 1;
		truc->sidedisty = (truc->mapy + 1.0 - truc->rayposy) * truc->deltadisty;
	}
}

void	hit_wall(t_all *truc)
{
	while (truc->hit == 0)
	{
		if (truc->sidedistx < truc->sidedisty)
		{
			truc->sidedistx += truc->deltadistx;
			truc->mapx += truc->stepx;
			truc->side = 0;
		}
		else
		{
			truc->sidedisty += truc->deltadisty;
			truc->mapy += truc->stepy;
			truc->side = 1;
		}
		if (truc->map[truc->mapx][truc->mapy] > 0)
			truc->hit = 1;
	}
}

void	distance_to_wall(t_all *truc)
{
	if (truc->side == 0)
		truc->perpwalldist = (truc->mapx - truc->rayposx + (1 - truc->stepx)
				/ 2) / truc->raydirx;
	else
		truc->perpwalldist = (truc->mapy - truc->rayposy + (1 - truc->stepy)
				/ 2) / truc->raydiry;
	truc->lineheight = (int)(H / truc->perpwalldist);
	truc->drawstart = -truc->lineheight / 2 + H / 2;
	if (truc->drawstart < 0)
		truc->drawstart = 0;
	truc->drawend = truc->lineheight / 2 + H / 2;
	if (truc->drawend >= H || truc->drawend < truc->drawstart)
		truc->drawend = H - 1;
}

void	ray_caster(t_all *truc, int x)
{
	truc->camerax = 2 * x / (double)W - 1;
	truc->rayposx = truc->player_pos_x;
	truc->rayposy = truc->player_pos_y;
	truc->raydirx = truc->dirx + truc->planex * truc->camerax;
	truc->raydiry = truc->diry + truc->planey * truc->camerax;
	truc->mapx = (int)truc->rayposx;
	truc->mapy = (int)truc->rayposy;
	truc->deltadistx = sqrt(1 + (truc->raydiry * truc->raydiry) /
			(truc->raydirx * truc->raydirx));
	truc->deltadisty = sqrt(1 + (truc->raydirx * truc->raydirx) /
			(truc->raydiry * truc->raydiry));
	truc->hit = 0;
	step(truc);
	hit_wall(truc);
	distance_to_wall(truc);
	draw_vertical(truc, x);
}
