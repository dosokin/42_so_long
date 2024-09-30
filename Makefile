CC = cc
NAME = so_long
NAME_BONUS = so_long_bonus
SRC = src/main.c \
	src/game/array_utils.c \
	src/game/clear_mlx.c \
	src/game/end_of_game.c \
	src/game/error.c \
	src/game/event_handler.c \
	src/game/exit.c \
	src/game/init_data.c \
	src/game/map_utils.c \
	src/game/pathfinding.c \
	src/game/textures_utils.c \
	src/game/treat_file.c \
	src/game/verify_map.c \
	src/game/visual_render.c

SRC_BONUS = src/main_bonus.c \
			src/game/bonus/array_utils.c \
			src/game/bonus/clear_mlx.c \
			src/game/bonus/counter.c \
			src/game/bonus/end_of_game.c \
			src/game/bonus/enemy.c \
			src/game/bonus/error.c \
			src/game/bonus/event_handler.c \
			src/game/bonus/exit.c \
			src/game/bonus/init_data.c \
			src/game/bonus/map_utils.c \
			src/game/bonus/pathfinding.c \
			src/game/bonus/textures_utils.c \
			src/game/bonus/treat_file.c \
			src/game/bonus/verify_map.c \
			src/game/bonus/visual_render.c

HEADER = inc/error.h inc/utils.h
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
CFLAGS = -Werror -Wextra -Wall -g -Iinc
LIBS = src/utils/libft src/utils/get_next_line
BUILT_LIBS = src/MLX42/build/libmlx42.a src/utils/libft/libft.a src/utils/get_next_line/get_next_line.a
MLXFLAGS = -Iinclude -ldl -lX11 -lglfw -pthread -lm

all : utils $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(BUILT_LIBS) $(MLXFLAGS) -o $(NAME)

utils :
	for dir in $(LIBS); do \
		$(MAKE) -C $$dir; \
	done


%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)
	rm -rf $(OBJ_BONUS)
	for dir in $(LIBS); do \
		$(MAKE) -C $$dir clean; \
	done

fclean : clean
	rm -rf $(NAME)
	rm -rf $(BONUS)
	for dir in $(LIBS); do \
		$(MAKE) -C $$dir fclean; \
	done

re : fclean all

bonus : fclean utils $(NAME_BONUS)

$(NAME_BONUS) : $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(BUILT_LIBS) $(MLXFLAGS) -o $(NAME_BONUS)

.PHONY: all fclean clean re bonus
