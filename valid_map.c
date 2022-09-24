/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muerdoga <muerdoga@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:50:58 by muerdoga          #+#    #+#             */
/*   Updated: 2022/09/23 14:51:01 by muerdoga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_loc(t_win *pnc)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (pnc->map->mappin[x])
	{
		while (pnc->map->mappin[x][y])
		{
			if (pnc->map->mappin[x][y] == 'P')
			{
				pnc->chr->l_x_c = x;
				pnc->chr->l_y_c = y;
			}
			y++;
		}
		y = 0;
		x++;
	}
}

void	valid_map_control(t_win *pnc, int x, int y)
{
	if (pnc->map->map_c[x][y] != '1')
	{
		if (pnc->map->map_c[x][y] != 'E')
		{
			if (pnc->map->map_c[x][y] == 'C')
				pnc->map->coin_cnt_c--;
			pnc->map->map_c[x][y] = 'X';
			if (pnc->map->map_c[x][y + 1] != '1' && pnc->map->map_c[x][y
				+ 1] != 'X')
				valid_map_control(pnc, x, y + 1);
			if (pnc->map->map_c[x][y - 1] != '1' && pnc->map->map_c[x][y
				- 1] != 'X')
				valid_map_control(pnc, x, y - 1);
			if (pnc->map->map_c[x + 1][y] != '1' && pnc->map->map_c[x
				+ 1][y] != 'X')
				valid_map_control(pnc, x + 1, y);
			if (pnc->map->map_c[x - 1][y] != '1' && pnc->map->map_c[x
				- 1][y] != 'X')
				valid_map_control(pnc, x - 1, y);
		}
		else
			pnc->map->end_cnt_c = 0;
	}
}

void	valid_map(t_win *pnc)
{
	int	i;

	i = 0;
	pnc->map->coin_cnt_c = pnc->map->coin_cnt;
	pnc->map->end_cnt_c = pnc->map->end_cnt;
	pnc->map->map_c = malloc(pnc->map->h + 200);
	while (i < pnc->map->h)
	{
		pnc->map->map_c[i] = malloc(pnc->map->w + 1);
		ft_strlcpy(pnc->map->map_c[i], pnc->map->mappin[i], pnc->map->w + 1);
		i++;
	}
	player_loc(pnc);
	valid_map_control(pnc, pnc->chr->l_x_c, pnc->chr->l_y_c);
	if (pnc->map->end_cnt_c != 0 || pnc->map->coin_cnt_c != 0)
	{
		ft_printf("OYNANABİLİR BİR MAP DEĞİL :(");
		close_window(pnc);
	}
}
