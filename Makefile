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
	src/game/struct_init.c \
	src/game/visual_render.c \
	src/game/game_data_init.c

SRC_BONUS = src/main_bonus.c \
			src/game/array_utils.c \
			src/game/error.c \
			src/game/map_utils.c \
            src/game/pathfinding.c \
            src/game/verify_map.c \
            src/game/struct_init.c \
			src/game/bonus/bonus_clear_mlx.c \
			src/game/bonus/bonus_counter.c \
			src/game/bonus/bonus_end_of_game.c \
			src/game/bonus/bonus_enemy.c \
			src/game/bonus/bonus_event_handler.c \
			src/game/bonus/bonus_exit.c \
			src/game/bonus/bonus_init_data.c \
			src/game/bonus/bonus_textures_utils.c \
			src/game/bonus/bonus_img_utils.c \
			src/game/treat_file.c \
			src/game/bonus/bonus_visual_render.c \
			src/game/bonus/bonus_game_data_struct_init.c
HEADER = inc/error.h inc/utils.h
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
CFLAGS = -Werror -Wextra -Wall -g -Iinc
LIBS = src/utils/libft src/utils/get_next_line
MLX_PATH = src/MLX42
BUILT_LIBS = src/utils/libft/libft.a src/utils/get_next_line/get_next_line.a
MLXFLAGS = -Iinclude -ldl -lX11 -lglfw -pthread -lm
MLX = src/MLX42/build/libmlx42.a

all : $(NAME)

$(NAME) : $(OBJ) $(MLX) $(BUILT_LIBS)
	$(CC) $(CFLAGS) $(OBJ) $(BUILT_LIBS) $(MLX) $(MLXFLAGS) -o $(NAME)

$(MLX) :
	cd $(MLX_PATH); \
	cmake -B build; \
	$(MAKE) -C build -j4

$(BUILT_LIBS) :
	for dir in $(LIBS); do \
		$(MAKE) -C $$dir; \
	done


%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)
	rm -rf $(OBJ_BONUS)
	for dir in $(LIBS); do \
		$(MAKE) clean -C $$dir; \
	done

fclean : clean
	rm -rf $(NAME)
	rm -rf $(NAME_BONUS)

	cd $(MLX_PATH); \
    $(MAKE) clean -C build; \
  	rm -rf build;

	for dir in $(LIBS); do \
		$(MAKE) fclean -C $$dir; \
	done

re : fclean all

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJ_BONUS) $(MLX) $(BUILT_LIBS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(MLX) $(BUILT_LIBS) $(MLXFLAGS) -o $(NAME_BONUS)

.PHONY: all fclean clean re bonus
