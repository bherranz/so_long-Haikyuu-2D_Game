NAME = so_long
BONUS_NAME = .bonus

SRCS = src/main.c src/check_map.c src/utils.c src/mlx_utils.c \
		src/gnl/get_next_line.c src/gnl/get_next_line_utils.c 

BONUS = 

OBJS = ${SRCS:.c=.o}
BONUS_OBJS = ${BONUS:.c=.o}

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
REMOVE = rm -f

all: ${NAME}

%.o: %.c
	$(CC) ${CFLAGS} -I/usr/include -Imlx_linux -O3 -c $< -o $@

${NAME}: ${OBJS} $(LIBFT)
		${CC} ${CFLAGS} ${OBJS} -L$(LIBFT_DIR) -lft -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz  -o ${NAME}

bonus: ${BONUS_NAME}

${BONUS_NAME}: ${BONUS_OBJS} $(LIBFT)
		@touch $(BONUS_NAME)
		${CC} ${CFLAGS} ${BONUS_OBJS} -L$(LIBFT_DIR) -lft -o ${NAME}

$(LIBFT):
		make -C $(LIBFT_DIR) all

clean:
		${REMOVE} ${OBJS} ${BONUS_OBJS}
		@make -sC $(LIBFT_DIR) clean
		@rm -rf $(BONUS_NAME)

fclean: 
		@${REMOVE} ${OBJS} ${BONUS_OBJS}
		@${REMOVE} ${NAME} ${PROGRAM}
		@make -sC $(LIBFT_DIR) fclean
		@rm -rf $(BONUS_NAME)

re: fclean all

clear:
	@clear

.PHONY:	all clean fclean re clear bonus