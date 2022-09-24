/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muerdoga <muerdoga@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:34:58 by muerdoga          #+#    #+#             */
/*   Updated: 2022/09/08 14:35:00 by muerdoga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include "./mlx/mlx.h"
# include "./printf/ft_printf.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_chr
{
	int		l_x;
	int		l_y;
	int		l_x_c;
	int		l_y_c;
	int		point;
	void	*chr_front;
	void	*chr_back;
	void	*chr_left;
	void	*chr_right;
	void	*chr_cur;
}			t_chr;

typedef struct s_map
{
	char	**mappin;
	char	**map_c;
	int		w;
	int		h;
	int		h_c;
	int		cb;
	int		gate_x;
	int		gate_y;
	int		p_cnt;
	int		end_cnt;
	int		coin_cnt;
	int		end_cnt_c;
	int		coin_cnt_c;
}			t_map;

typedef struct s_win
{
	t_map	*map;
	t_chr	*chr;
	void	*win;
	void	*mlx;
	void	*img_bg;
	void	*block_bg;
	void	*c_bg;
	void	*end_bg;
	int		height;
	int		width;
}			t_win;

void		xpm_control(void);
void		xpm_control_2(void);
void		ber_control(char *map_adi);
void		map_file_control(char *map_adi);
void		open_window(t_win *pnc, char *map_name);
char		*read_file(char *map_name, t_map *map);
t_map		*read_map(char *map_name);
void		join_ret_line(char **ret, char *line);
void		player_control(t_win *pnc);
int			close_window(void *tmp);
void		map_size_control(t_win *pnc);
void		wall_control(t_win *pnc);
void		end_control(t_win *pnc);
void		coin_control(t_win *pnc);
void		invalid_char_control(t_win *pnc);
void		render_map(t_win *pnc);
void		put_image(char c, t_win *pnc, int x, int y);
int			walk(int keycode, void *tmp);
void		put_score(t_win *pnc);
void		putchr(t_win *pnc, int keycode);
void		valid_map(t_win *pnc);
void		valid_map_control(t_win *pnc, int x, int y);
void		player_loc(t_win *pnc);
void		height_find(t_win *pnc);
#endif
