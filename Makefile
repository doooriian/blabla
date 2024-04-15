NAME = so_long

CC = clang

CFLAGS = -Wall -Wextra -Werror -gdwarf-4

RM = rm -f

PRINTF_DIR = include/ft_printf
FT_PRINTF = $(PRINTF_DIR)/libftprintf.a

SRCS = 	srcs/main.c include/gnl/get_next_line.c include/gnl/get_next_line_utils.c \
		srcs/parsing/error.c srcs/free.c srcs/parsing/parsing_check.c \
		srcs/parsing/parsing_utils.c srcs/parsing/parsing.c srcs/game/game_init.c \
		srcs/game/move.c srcs/game/game_utils.c


OBJS = ${SRCS:.c=.o}

MLX_DIR = mlx
MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib/X11 -lXext -lX11

all : mlx_build printf_build $(NAME)

mlx_build:
		$(MAKE) -C $(MLX_DIR)

printf_build:
		$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME) $(FT_PRINTF)

clean :
		$(RM) $(OBJS)
		$(MAKE) -C $(MLX_DIR) clean
		$(MAKE) -C $(PRINTF_DIR) clean

fclean : clean
		$(RM) $(NAME)
		$(MAKE) -C $(PRINTF_DIR) fclean

re : fclean all

.PHONY : all clean fclean re mlx_build printf_build
