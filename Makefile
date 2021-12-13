NAME = so_long.a

AR = ar
ARFLAGS = crs

RM = rm
RMFLAG = -f

INCLUDES = ./so_long.h

SRCS= \
	./src/check.c	\
	./src/display.c	\
	./src/file.c	\
	./src/key.c	\
	./src/kill.c	\
	./src/map.c	\
	./src/move.c	\
	./src/random.c

GAME= so_long

OBJS = $(SRCS:.c=.o)

CC		= gcc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror
MLX= -Lmlx -lmlx -framework OpenGL -framework AppKit

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		$(MAKE) -C ./libft
		$(MAKE) -C ./mlx
		${CC} ${CFLAGS} ${MLX} ./src/so_long.c ${OBJS} ./libft/libft.a -o ${GAME}

all:	${NAME}

clean:
		${RM} ${OBJS}
		$(MAKE) -C ./mlx clean
		$(MAKE) -C ./libft clean

fclean:	clean
		${RM} ${NAME}
		${RM} ${GAME}
		$(MAKE) -C ./mlx clean
		$(MAKE) -C ./libft fclean

bonus : all

re:		fclean all
.PHONY: all clean fclean re

