NAME = libftprintf.a

SRCS = ft_printf.c ft_nums.c ft_strings.c ft_hex.c

OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror
REMOVE = rm -f

all: ${NAME}

${NAME}: ${OBJS}
		 ar rcs ${NAME} ${OBJS}

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean: 
	${REMOVE} ${OBJS}

fclean: clean
		${REMOVE} ${NAME}

re: fclean all

.PHONY:	all clean fclean re