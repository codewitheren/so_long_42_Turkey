/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muerdoga <muerdoga@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:15:24 by muerdoga          #+#    #+#             */
/*   Updated: 2022/09/08 14:19:24 by muerdoga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_img(t_win *pnc, int x, int y)
{
	pnc->height = pnc->map->h * 64;
	pnc->width = pnc->map->w * 64;
	pnc->mlx = mlx_init();
	pnc->win = mlx_new_window(pnc->mlx, pnc->width, pnc->height,
			"Ironman 2D Game");
	pnc->chr = ft_calloc(1, sizeof(t_chr));
	pnc->chr->l_x = 0;
	pnc->chr->l_y = 0;
	pnc->chr->point = 0;
	pnc->chr->chr_front = mlx_xpm_file_to_image(pnc->mlx, \
			"./img/front_char.xpm", &x, &y);
	pnc->chr->chr_back = mlx_xpm_file_to_image(pnc->mlx, \
			"./img/back_char.xpm", &x, &y);
	pnc->chr->chr_right = mlx_xpm_file_to_image(pnc->mlx, \
			"./img/right_char.xpm", &x, &y);
	pnc->chr->chr_left = mlx_xpm_file_to_image(pnc->mlx, \
			"./img/left_char.xpm", &x, &y);
	pnc->chr->chr_cur = pnc->chr->chr_front;
	pnc->img_bg = mlx_xpm_file_to_image(pnc->mlx, "./img/bg.xpm", &x, &y);
	pnc->block_bg = mlx_xpm_file_to_image(pnc->mlx, "./img/block.xpm", &x, &y);
	pnc->c_bg = mlx_xpm_file_to_image(pnc->mlx, "./img/coin.xpm", &x, &y);
	pnc->end_bg = mlx_xpm_file_to_image(pnc->mlx, "./img/endgate.xpm", &x, &y);
}

void	open_window(t_win *pnc, char *map_name)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	pnc->map = read_map(map_name);
	get_img(pnc, x, y);
	player_control(pnc);
	map_size_control(pnc);
	wall_control(pnc);
	end_control(pnc);
	coin_control(pnc);
	invalid_char_control(pnc);
	valid_map(pnc);
}

int	close_window(void *tmp)
{
	t_win	*pnc;
	int		i;

	pnc = tmp;
	i = 0;
	mlx_destroy_image(pnc->mlx, pnc->chr->chr_front);
	mlx_destroy_image(pnc->mlx, pnc->chr->chr_back);
	mlx_destroy_image(pnc->mlx, pnc->chr->chr_right);
	mlx_destroy_image(pnc->mlx, pnc->chr->chr_left);
	mlx_destroy_image(pnc->mlx, pnc->c_bg);
	mlx_destroy_image(pnc->mlx, pnc->end_bg);
	mlx_destroy_image(pnc->mlx, pnc->block_bg);
	mlx_destroy_image(pnc->mlx, pnc->img_bg);
	free(pnc->chr);
	while (pnc->map->mappin[i])
		free(pnc->map->mappin[i++]);
	free(pnc->map->mappin);
	free(pnc->map);
	mlx_destroy_window(pnc->mlx, pnc->win);
	exit(1);
	return (1);
}

int	main(int ac, char *av[])
{
	t_win	pnc;

	if (ac == 2)
	{
		xpm_control();
		ber_control(av[1]);
		open_window(&pnc, av[1]);
		render_map(&pnc);
		mlx_hook(pnc.win, 2, (1L << 0), walk, &pnc);
		mlx_hook(pnc.win, 17, 0, close_window, &pnc);
		mlx_loop(pnc.mlx);
	}
	else
		write(1, "Eksik argüman hatasi.", 21);
	return (0);
}
