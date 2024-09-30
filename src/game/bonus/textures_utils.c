#include "libft.h"
#include "solong_bonus.h"

const char *get_texture_path(size_t index)
{
    const char *paths[17] = {
            "textures/manda/exit.png",
            "textures/manda/wall.png",
            "textures/manda/empty.png",
            "textures/manda/collectible.png",
            "textures/manda/player.png",
            "textures/bonus/enemy_1.png",
            "textures/bonus/enemy_2.png",
            "textures/bonus/numbers/0.png",
            "textures/bonus/numbers/1.png",
            "textures/bonus/numbers/2.png",
            "textures/bonus/numbers/3.png",
            "textures/bonus/numbers/4.png",
            "textures/bonus/numbers/5.png",
            "textures/bonus/numbers/6.png",
            "textures/bonus/numbers/7.png",
            "textures/bonus/numbers/8.png",
            "textures/bonus/numbers/9.png",
    };

    if (index > 16)
        return (NULL);
    return (paths[index]);
}

mlx_texture_t **get_texture_location(size_t index, struct s_mlx_textures *textures)
{
    mlx_texture_t **p[17] = {
            &(textures->exit),
            &(textures->wall),
            &(textures->empty),
            &(textures->collectible),
            &(textures->player),
            &(textures->enemy_1),
            &(textures->enemy_2),
            &(textures->number_0),
            &(textures->number_1),
            &(textures->number_2),
            &(textures->number_3),
            &(textures->number_4),
            &(textures->number_5),
            &(textures->number_6),
            &(textures->number_7),
            &(textures->number_8),
            &(textures->number_9),

    };

    if (index > 16)
        return (NULL);
    return (p[index]);
}

mlx_image_t **get_image_location(size_t index, struct s_game_images *images)
{
    mlx_image_t **p[7] = {
            &(images->exit),
            &(images->wall),
            &(images->empty),
            &(images->collectible),
            &(images->player_img),
            &(images->enemy_img1),
            &(images->enemy_img2),
    };

    if (index > 6)
        return (NULL);
    return (p[index]);
}

mlx_image_t **get_num_location(size_t index, struct s_num_images *images)
{
    mlx_image_t **p[10] = {
            &(images->number_0),
            &(images->number_1),
            &(images->number_2),
            &(images->number_3),
            &(images->number_4),
            &(images->number_5),
            &(images->number_6),
            &(images->number_7),
            &(images->number_8),
            &(images->number_9),
    };

    if (index > 9)
        return (NULL);
    return (p[index]);
}



int png_to_texture(mlx_texture_t **buffer, const char *path_to_png)
{
    if (!buffer || !path_to_png)
        return (1);
    *buffer = mlx_load_png(path_to_png);
    if (!*buffer)
        return (1);
    return (0);
}

int texture_to_img(mlx_image_t **buffer, mlx_texture_t *texture, mlx_t *mlx)
{
    if (!buffer || !texture)
        return (1);
    *buffer = mlx_texture_to_image(mlx, texture);
    if (!*buffer)
        return (1);
    return (0);
}