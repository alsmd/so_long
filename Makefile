SRCS = ./src/main.c

OBJS = $(SRCS:.c=.o)

NAME = so_long

CFLAGS		= 
FLAGS		= -ldl -Imlx -Lmlx -lmlx -lm -lbsd -lXext -lX11

CC = clang

RM = rm -f

all: $(NAME)

.c.o:
	${CC} ${CFLAGS} -Imlx -Ibass -c $< -o ${<:.c=.o}

$(NAME): 	$(OBJS)
	make -C mlx
	${CC} $(CFLAGS) -o $(NAME) $(OBJS) $(FLAGS)

clean:
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re: fclean all