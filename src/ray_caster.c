/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment_tracer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvasseur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 12:25:30 by lvasseur          #+#    #+#             */
/*   Updated: 2017/02/15 14:09:47 by lvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	step(t_all *truc)
{
	if (truc->rayDirX < 0)
	{
		truc->stepX = -1;
		truc->sideDistX = (truc->rayPosX - truc->mapX) * truc->deltaDistX;
	}
	else
	{
		truc->stepX = 1;
		truc->sideDistX = (truc->mapX + 1.0 - truc->rayPosX) * truc->deltaDistX;
	}
	if (truc->rayDirY < 0)
	{
		truc->stepY = -1;
		truc->sideDistY = (truc->rayPosY - truc->mapY) * truc->deltaDistY;
	}
	else
	{
		truc->stepY = 1;
		truc->sideDistY = (truc->mapY + 1.0 - truc->rayPosY) * truc->deltaDistY;
	}
}

void	hit_wall(t_all *truc)
{
	while (truc->hit == 0)
	{
		if (truc->sideDistX < truc->sideDistY)
		{
			truc->sideDistX += truc->deltaDistX;
			truc->mapX += truc->stepX;
			truc->side = 0;
		}
		else
		{
			truc->sideDistY += truc->deltaDistY;
			truc->mapY += truc->stepY;
			truc->side = 1;
		}
		if (truc->map[truc->mapX][truc->mapY] > 0)
			truc->hit = 1;
	}
}

void	distance_to_wall(t_all *truc)
{
	if (truc->side == 0)
		truc->perpWallDist = (truc->mapX - truc->rayPosX + (1 - truc->stepX) / 2) / truc->rayDirX;
	else
		truc->perpWallDist = (truc->mapY - truc->rayPosY + (1 - truc->stepY) / 2) / truc->rayDirY;
	truc->lineHeight = (int)(H / truc->perpWallDist);
	truc->drawStart = -truc->lineHeight / 2 + H / 2;
	if (truc->drawStart < 0)
		truc->drawStart = 0;
	truc->drawEnd = truc->lineHeight / 2 + H / 2;
	if (truc->drawEnd >= H || truc->drawEnd <= truc->drawStart)
		truc->drawEnd = H - 1;
}

void	draw_vertical(t_all *truc, int x)
{
	int		y1;
	int		y2;
	int		i;

	i = 0;
	y1 = truc->drawStart;
	y2 = truc->drawEnd;
	while (++i <= y1)
		*(unsigned *)(truc->data_addr + (i * truc->size) +
				(x * truc->bpx / 8)) = 0x0060FFF9;
	while (++y1 <= y2)
		if (truc->side == 1)
			*(unsigned *)(truc->data_addr + (y1 * truc->size) +
					(x * truc->bpx / 8)) = 0x0066FF00;
		else
			*(unsigned *)(truc->data_addr + (y1 * truc->size) +
					(x * truc->bpx / 8)) = 0x006600FF;
	y2--;
	while (++y2 <= H - 1)
		*(unsigned *)(truc->data_addr + (y2 * truc->size) +
				(x * truc->bpx / 8)) = 0x000F66FF;
}

void	ray_caster(t_all *truc, int x)
{
	truc->cameraX = 2 * x / (double)W - 1;
	truc->rayPosX = truc->player_pos_x;
	truc->rayPosY = truc->player_pos_y;
	truc->rayDirX = truc->dirX + truc->planeX * truc->cameraX;
	truc->rayDirY = truc->dirY + truc->planeY * truc->cameraX;
	truc->mapX = (int)truc->rayPosX;
	truc->mapY = (int)truc->rayPosY;
	truc->deltaDistX = sqrt(1 + (truc->rayDirY * truc->rayDirY) / (truc->rayDirX * truc->rayDirX));
	truc->deltaDistY = sqrt(1 + (truc->rayDirX * truc->rayDirX) / (truc->rayDirY * truc->rayDirY));
	truc->hit = 0;
	step(truc);
	hit_wall(truc);
	distance_to_wall(truc);
	draw_vertical(truc, x);
}
