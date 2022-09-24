CFLAGS = -Wall -Wextra -Werror -I./mlx
LFLAGS = -framework AppKit -framework OpenGL -L./mlx -lmlx
MLX = ./mlx/libmlx.a
GNL = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c
GNLOBJS = $(GNL:.c=.o)
SRCS = main.c map_control.c map_info.c walk.c xpm_ber_control.c valid_map.c
B_SRCS = main.c map_control.c map_info_bonus.c walk.c xpm_ber_control.c valid_map.c
OBJS = $(SRCS:.c=.o)
B_OBJS = $(B_SRCS:.c=.o)
NAME = so_long

all : $(MLX) $(NAME)

$(MLX) :
	make -C ./libft
	make -C ./printf
	make -C ./mlx

$(NAME) : $(OBJS) $(GNLOBJS)
	gcc $(OBJS) $(GNLOBJS) $(LFLAGS) $(CFLAGS) ./libft/libft.a ./printf/libftprintf.a ./mlx/libmlx.a -o so_long

bonus: fclean $(B_OBJS) $(GNLOBJS) $(MLX)
	gcc $(B_OBJS) $(GNLOBJS) $(LFLAGS) $(CFLAGS) ./libft/libft.a ./printf/libftprintf.a ./mlx/libmlx.a -o so_long_bonus

clean:
	rm -rf $(OBJS) $(NAME)

fclean:
	rm -rf $(OBJS) so_long
	rm -rf $(B_OBJS) so_long_bonus
	rm -rf ./get_next_line/*.o
	make clean -C ./mlx
	make fclean -C ./libft
	make fclean -C ./printf

re : fclean all

.PHONY: clean fclean re
