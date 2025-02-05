NAME = libftprintf.a

SRC = ft_printf.c ft_printf_utils.c

CC = cc

CFLAGS = -Wall -Wextra -Werror

OBJS = ${SRC:.c=.o}

all : ${NAME}

${NAME} : ${OBJS}
	ar -rcs ${NAME} $^

%.o:%.c ft_printf.h
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -rf ${OBJS}

fclean:
	rm -rf ${OBJS} ${NAME}

re: fclean all

.PHONY: clean fclean