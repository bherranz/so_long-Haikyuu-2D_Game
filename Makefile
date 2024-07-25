NAME = so_long
BONUS_NAME = .bonus

SRCS = src/main.c src/check_map.c src/utils.c src/mlx_utils.c \
		src/image_utils.c src/move.c src/draw.c\
		gnl/get_next_line.c gnl/get_next_line_utils.c 

BONUS = bonus/main_bonus.c bonus/check_map_bonus.c bonus/utils_bonus.c bonus/mlx_utils_bonus.c \
		bonus/image_utils_bonus.c bonus/move_bonus.c bonus/draw_bonus.c\
		gnl/get_next_line.c gnl/get_next_line_utils.c

OBJS = ${SRCS:.c=.o}
BONUS_OBJS = ${BONUS:.c=.o}

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
REMOVE = rm -f

MLX_DIR = mlx_linux
MLX_LIB = $(MLX_DIR)/libmlx.a

all: $(LIBFT) $(MLX_LIB) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR) > /dev/null

$(MLX_LIB):
	@make -C $(MLX_DIR) > /dev/null

$(NAME): $(OBJS) $(LIBFT) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -I$(MLX_DIR) -lXext -lX11 -lm -lz -o $(NAME)

bonus: ${BONUS_NAME}

${BONUS_NAME}: ${BONUS_OBJS} $(LIBFT) $(MLX_LIB)
		@touch $(BONUS_NAME)
		${CC} ${CFLAGS} ${BONUS_OBJS} -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -I$(MLX_DIR) -lXext -lX11 -lm -lz -o ${NAME}

clean:
	@${REMOVE} ${OBJS} ${BONUS_OBJS}
	$(REMOVE) $(OBJS)
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean > /dev/null
	@rm -rf $(BONUS_NAME)

fclean: clean
	@${REMOVE} ${OBJS} ${BONUS_OBJS}
	$(REMOVE) $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@rm -rf $(BONUS_NAME)

re: fclean all

clear:
	@clear

.PHONY: all clean fclean re clear bonus