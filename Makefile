SRCS	= pipex.c err.c
NAME	= pipex
CC	= gcc
FLAGS	= -Wall -Werror -Wextra
RM	= rm -f
INCS	= libft
LIBFT	= -Llibft -lft

all: ${NAME}

${NAME}: runlibft norm
	${CC} ${FLAGS} -o ${NAME} ${SRCS} -I ${INCS} ${LIBFT}

clean:
	${RM} ${NAME}

fclean: clean
	make -C libft fclean

re: fclean all

runlibft:
	make -C libft

norm:
	norminette -R CheckForbiddenSourceHeader ${SRCS} 
	norminette -R CheckDefine ${INCS} pipex.h

.PHONY: all re clean fclean
