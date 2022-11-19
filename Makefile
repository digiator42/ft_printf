NAME = libftprintf.a

SRC =ft_putnbr.c \
ft_printf.c \
ft_putchar.c \
ft_putstr.c

OBJ = ${SRC:.c=.o}

CFLAG = -Wall -Werror -Wextra

CC = clang

.c.o:
	@gcc ${CFLAG} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ}
	@ar rc ${NAME} ${OBJ}
	@echo "libftprintf.a is compiled"

all: ${NAME}
	@echo "libftprintf.a is compiled"
bonus: all

clean:
	@rm -f ${OBJ}
	@echo "ft_printf.h is clean and still got libftprintf.a"

fclean: clean
	@rm -f ${NAME}
	@echo "ft_printf.h is all clean"

re: fclean all
	@echo "cleaned and compiled again libftprintf.a"

.PHONY : all clean fclean re bonus