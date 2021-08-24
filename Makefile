SRCS =	./src/main.c \
		./src/utils/ft_calloc.c ./src/utils/ft_strlen.c ./src/utils/get_next_line_utils.c ./src/utils/get_next_line.c ./src/utils/is_in.c \
		./src/utils/ft_substr.c ./src/utils/pixel_manipulation.c \
		./src/checks/check_map.c \
		./src/keyframe/game_init.c ./src/keyframe/frame_update.c \
		./src/config/game_config.c ./src/config/map_config.c ./src/config/player_config.c ./src/config/new_item.c \
		./src/sprites/map_sprites.c ./src/sprites/player_sprites.c ./src/sprites/item_sprites.c \
		./src/actions/player_action.c ./src/actions/key_hook.c

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