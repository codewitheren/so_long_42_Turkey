/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muerdoga <muerdoga@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:21:52 by muerdoga          #+#    #+#             */
/*   Updated: 2022/09/08 14:21:54 by muerdoga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_control(t_win *pnc)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (pnc->map->mappin[i])
	{
		while (pnc->map->mappin[i][j])
		{
			if (pnc->map->mappin[i][j] == 'P')
				pnc->map->p_cnt += 1;
			j++;
		}
		i++;
		j = 0;
	}
	if (pnc->map->p_cnt != 1)
	{
		write(1, "Oyuncu sayisi hatali", 20);
		close_window(pnc);
	}
}

void	map_size_control(t_win *pnc)
{
	int		i;
	size_t	len;

	i = 0;
	len = pnc->map->w;
	while (pnc->map->mappin[i])
	{
		if (len != ft_strlen(pnc->map->mappin[i]))
		{
			write(1, "Map boyutu hatali", 17);
			close_window(pnc);
		}
		i++;
	}
}

void	wall_control(t_win *pnc)
{
	int	i;

	i = -1;
	while (pnc->map->mappin[0][++i])
	{
		if (pnc->map->mappin[0][i] != '1' || pnc->map->mappin[pnc->map->h
			- 1][i] != '1')
		{
			write(1, "Duvar köşe hatasi", 19);
			close_window(pnc);
		}
	}
	i = -1;
	while (pnc->map->mappin[++i])
	{
		if (pnc->map->mappin[i][0] != '1' || pnc->map->mappin[i][pnc->map->w
			- 1] != '1')
		{
			write(1, "Duvar köşe hatasi", 19);
			close_window(pnc);
		}
	}
}

void	end_control(t_win *pnc)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (pnc->map->mappin[i])
	{
		while (pnc->map->mappin[i][j])
		{
			if (pnc->map->mappin[i][j] == 'E')
				pnc->map->end_cnt += 1;
			j++;
		}
		j = 0;
		i++;
	}
	if (pnc->map->end_cnt <= 0)
	{
		write(1, "Cikis sayisi hatali", 19);
		close_window(pnc);
	}
}

void	coin_control(t_win *pnc)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (pnc->map->mappin[i])
	{
		while (pnc->map->mappin[i][j])
		{
			if (pnc->map->mappin[i][j] == 'C')
				pnc->map->coin_cnt += 1;
			j++;
		}
		j = 0;
		i++;
	}
	if (pnc->map->coin_cnt <= 0)
	{
		write(1, "Altin sayisi hatali", 19);
		close_window(pnc);
	}
}
