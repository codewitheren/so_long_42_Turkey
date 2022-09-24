/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_ber_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muerdoga <muerdoga@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:30:44 by muerdoga          #+#    #+#             */
/*   Updated: 2022/09/08 14:30:45 by muerdoga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	xpm_control_2(void)
{
	int	fd_left_char;
	int	fd_coin;
	int	fd_block;
	int	fd_endgate;

	fd_left_char = open("./img/left_char.xpm", O_RDWR);
	fd_coin = open("./img/coin.xpm", O_RDWR);
	fd_block = open("./img/block.xpm", O_RDWR);
	fd_endgate = open("./img/endgate.xpm", O_RDWR);
	if (fd_left_char <= 0 || fd_coin <= 0 || fd_block <= 0 || fd_endgate <= 0)
	{
		write(1, "Eksik XPM dosyasi hatasi.", 25);
		close(fd_left_char);
		close(fd_coin);
		close(fd_block);
		close(fd_endgate);
		exit(1);
	}
}

void	xpm_control(void)
{
	int	fd_bg;
	int	fd_back_char;
	int	fd_front_char;
	int	fd_right_char;

	fd_bg = open("./img/bg.xpm", O_RDWR);
	fd_back_char = open("./img/back_char.xpm", O_RDWR);
	fd_front_char = open("./img/front_char.xpm", O_RDWR);
	fd_right_char = open("./img/right_char.xpm", O_RDWR);
	if (fd_back_char <= 0 || fd_front_char <= 0 || fd_right_char <= 0
		|| fd_bg <= 0)
	{
		write(1, "Eksik XPM dosyası hatasi.", 25);
		close(fd_bg);
		close(fd_back_char);
		close(fd_front_char);
		close(fd_right_char);
		exit(1);
	}
	xpm_control_2();
}

void	ber_control(char *map_name)
{
	size_t	len;

	len = ft_strlen(map_name);
	if (map_name[len - 1] != 'r' || map_name[len - 2] != 'e')
	{
		write(1, "Map adi hatasi.", 15);
		exit(1);
	}
	if (map_name[len - 3] != 'b' || map_name[len - 4] != '.')
	{
		write(1, "Map adi hatasi.", 15);
		exit(1);
	}
	map_file_control(map_name);
}

void	map_file_control(char *map_name)
{
	int	fd;

	fd = open(map_name, O_RDWR);
	if (fd < 0)
	{
		write(1, "Map dosya hatasi", 16);
		exit(1);
	}
}

void	invalid_char_control(t_win *pnc)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (pnc->map->mappin[i])
	{
		while (pnc->map->mappin[i][j])
		{
			if (pnc->map->mappin[i][j] != '1' && pnc->map->mappin[i][j] != '0'
				&& pnc->map->mappin[i][j] != 'E'
				&& pnc->map->mappin[i][j] != 'P'
				&& pnc->map->mappin[i][j] != 'C')
			{
				write(1, "Gecersiz karakter hatasi", 24);
				close_window(pnc);
			}
			j++;
		}
		j = 0;
		i++;
	}
}
