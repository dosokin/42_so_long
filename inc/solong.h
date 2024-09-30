/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:59:16 by dosokin           #+#    #+#             */
/*   Updated: 2023/12/15 20:02:42 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef YY_SOLONG_H
# define YY_SOLONG_H
# include "../src/MLX42/include/MLX42/MLX42.h"

struct s_elements_count {
    size_t collectibles;
    size_t players;
    size_t exits;
    size_t others;
    size_t empties;
};

struct s_mlx_textures{
    mlx_texture_t *player;
    mlx_texture_t *wall;
    mlx_texture_t *empty;
    mlx_texture_t *collectible;
    mlx_texture_t *exit;
};

struct s_game_images{
    mlx_image_t *wall;
    mlx_image_t *empty;
    mlx_image_t *collectible;
    mlx_image_t *exit;
    mlx_image_t *player_img;
};

struct s_coord{
    size_t x;
    size_t y;
};

enum e_key_status{
    RELEASED,
    PRESSED,
};

enum e_game_status{
    DEFAULT,
    WIN,
};

struct s_keys_status{
    enum e_key_status up;
    enum e_key_status down;
    enum e_key_status left;
    enum e_key_status right;
};

struct s_game_logic{
    struct s_coord player;
    size_t remaining_collectibles;
    struct s_keys_status keys_status;
    enum e_game_status  status;
};

struct s_mlx_data{
    mlx_t                 *mlx;
    struct s_mlx_textures textures;
    struct s_game_images   images;
};

typedef struct s_game_data
{
    struct s_mlx_data   mlx_data;
    struct s_game_logic game_logic;
    char                **map;
} t_game_data;


bool    check_file_extension(char *filename, char *expected_extension);
char	*get_content(int fd);

int count_array(char **s);
char **array_dup(char **array);
void *free_array(char **s);

struct s_coord get_element_coord(char **map, char element, size_t index);
struct s_elements_count	count_elements(char **map);
char    **extract_map(char *brut_map);

int     check_map_validity(char **map);
int     check_path(char **map);

int init_game(int fd, struct s_game_data *game_data);

void	key_release(void *p);
void	key_press(void *p);

int visual_render(char **map, struct s_game_data *game_data);
int render_element(struct s_mlx_data mlx_data, char element, size_t x, size_t y);
void display_move_count(int move_count);

void delete_textures(struct s_mlx_textures *textures);
void delete_game_images(struct s_game_images *images, mlx_t *mlx);
void clean_exit(struct s_game_data *game_data);

char	        *get_next_line(int fd);

void    check_win_case(t_game_data *game_data);

int png_to_texture(mlx_texture_t **buffer, const char *path_to_png);
const char *get_texture_path(size_t index);
mlx_texture_t **get_texture_location(size_t index, struct s_mlx_textures *textures);
mlx_image_t **get_image_location(size_t index, struct s_game_images *images);
int texture_to_img(mlx_image_t **buffer, mlx_texture_t *texture, mlx_t *mlx);

#endif
