/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muerdoga <muerdoga@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:26:25 by muerdoga          #+#    #+#             */
/*   Updated: 2022/09/08 14:26:27 by muerdoga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_file(char *map_name, t_map *map)
{
	char	*line;
	char	*ret;
	int		fd;
	int		i;

	i = -1;
	fd = open(map_name, O_RDONLY);
	ret = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		while (line[++i])
		{
			if (line[i] == 'C')
				map->cb = map->cb + 1;
		}
		i = -1;
		ret = f_strjoin(ret, line);
		free(line);
	}
	close(fd);
	return (ret);
}

t_map	*read_map(char *map_name)
{
	t_map	*ret;
	char	*map;

	ret = ft_calloc(1, sizeof(t_map));
	map = read_file(map_name, ret);
	ret->mappin = ft_split(map, '\n');
	ret->h = 0;
	while (ret->mappin[ret->h])
		ret->h++;
	ret->w = ft_strlen(ret->mappin[0]);
	free(map);
	return (ret);
}

void	put_score(t_win *pnc)
{
	(void)pnc;
}

void	put_image(char c, t_win *pnc, int x, int y)
{
	mlx_put_image_to_window(pnc->mlx, pnc->win, pnc->img_bg, x, y);
	if (c == '1')
	{
		mlx_put_image_to_window(pnc->mlx, pnc->win, pnc->block_bg, x, y);
	}
	if (c == 'C')
	{
		mlx_put_image_to_window(pnc->mlx, pnc->win, pnc->c_bg, x, y);
	}
	if (c == 'P')
	{
		pnc->chr->l_x = x;
		pnc->chr->l_y = y;
		mlx_put_image_to_window(pnc->mlx, pnc->win, pnc->chr->chr_cur, x, y);
	}
	if (c == 'E')
	{
		pnc->map->gate_x = x;
		pnc->map->gate_y = y;
		mlx_put_image_to_window(pnc->mlx, pnc->win, pnc->end_bg, x, y);
	}
}

void	render_map(t_win *pnc)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	j = 0;
	x = 0;
	y = 0;
	while (pnc->map->mappin[i])
	{
		j = 0;
		x = 0;
		while (pnc->map->mappin[i][j])
		{
			put_image(pnc->map->mappin[i][j++], pnc, x, y);
			put_score(pnc);
			x = x + 64;
		}
		i++;
		y = y + 64;
	}
}
