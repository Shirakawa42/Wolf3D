/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvasseur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 16:56:54 by lvasseur          #+#    #+#             */
/*   Updated: 2017/02/20 17:18:29 by lvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	draw_vertical(t_all *truc, int x)
{
	int		y1;
	int		y2;
	int		i;

	i = 0;
	y1 = truc->drawstart;
	y2 = truc->drawend;
	while (++i <= y1)
		*(unsigned *)(truc->data_addr + (i * truc->size) +
				(x * truc->bpx / 8)) = 0x0060FFF9;
	if (truc->map[truc->mapx][truc->mapy] == 1)
		while (++y1 <= y2)
			*(unsigned *)(truc->data_addr + (y1 * truc->size) +
					(x * truc->bpx / 8)) = COLOR_1;
	else if (truc->map[truc->mapx][truc->mapy] == 2)
		while (++y1 <= y2)
			*(unsigned *)(truc->data_addr + (y1 * truc->size) +
					(x * truc->bpx / 8)) = COLOR_2;
	else if (truc->map[truc->mapx][truc->mapy] == 3)
		while (++y1 <= y2)
			*(unsigned *)(truc->data_addr + (y1 * truc->size) +
					(x * truc->bpx / 8)) = COLOR_3;
	else if (truc->map[truc->mapx][truc->mapy] == 4)
		while (++y1 <= y2)
			*(unsigned *)(truc->data_addr + (y1 * truc->size) +
					(x * truc->bpx / 8)) = COLOR_4;
	else if (truc->map[truc->mapx][truc->mapy] == 15)
		while (++y1 <= y2)
			*(unsigned *)(truc->data_addr + (y1 * truc->size) +
					(x * truc->bpx / 8)) = COLOR_5;
	else if (truc->map[truc->mapx][truc->mapy] == 16)
		while (++y1 <= y2)
			*(unsigned *)(truc->data_addr + (y1 * truc->size) +
					(x * truc->bpx / 8)) = COLOR_6;
	else if (truc->map[truc->mapx][truc->mapy] == 17)
		while (++y1 <= y2)
			*(unsigned *)(truc->data_addr + (y1 * truc->size) +
					(x * truc->bpx / 8)) = COLOR_7;
	else if (truc->map[truc->mapx][truc->mapy] == 18)
		while (++y1 <= y2)
			*(unsigned *)(truc->data_addr + (y1 * truc->size) +
					(x * truc->bpx / 8)) = COLOR_8;
	else if (truc->map[truc->mapx][truc->mapy] == 5)
		while (++y1 <= y2)
			*(unsigned *)(truc->data_addr + (y1 * truc->size) +
					(x * truc->bpx / 8)) = COLOR_9;
	else if (truc->map[truc->mapx][truc->mapy] == 6)
		while (++y1 <= y2)
			*(unsigned *)(truc->data_addr + (y1 * truc->size) +
					(x * truc->bpx / 8)) = COLOR_10;
	else
		while (++y1 <= y2)
			*(unsigned *)(truc->data_addr + (y1 * truc->size) +
					(x * truc->bpx / 8)) = 0xFFFFFF;
	y2--;
	while (++y2 < H)
			*(unsigned *)(truc->data_addr + (y2 * truc->size) +
					(x * truc->bpx / 8)) = 0x996600;
}
