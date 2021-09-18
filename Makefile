SRCS =	./src/main.c \
		./src/utils/ft_calloc.c ./src/utils/ft_strlen.c ./src/utils/get_next_line_utils.c ./src/utils/get_next_line.c ./src/utils/is_in.c \
		./src/utils/ft_substr.c ./src/utils/pixel_manipulation.c ./src/utils/create_img.c ./src/utils/ft_strcat.c ./src/utils/ft_itoa.c \
		./src/checks/check_map.c ./src/checks/check_movs.c ./src/checks/check_exit.c  \
		./src/config/game_config.c ./src/config/map_config.c ./src/config/player_config.c ./src/config/new_item.c \
		./src/config/enemy_config.c ./src/config/fireball_config.c \
		./src/actions/player_action.c ./src/actions/game_init.c  ./src/actions/item_action.c  ./src/actions/moviments.c \
		./src/actions/enemy_action.c ./src/actions/fireball_action.c ./src/actions/game_over.c 

OBJS = $(SRCS:.c=.o)

NAME = so_long

CFLAGS		= -g
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