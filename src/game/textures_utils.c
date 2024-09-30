#include "libft.h"
#include "solong.h"

const char *get_texture_path(size_t index)
{
    const char *paths[5] = {
            "textures/manda/exit.png",
            "textures/manda/wall.png",
            "textures/manda/empty.png",
            "textures/manda/collectible.png",
            "textures/manda/player.png",
    };

    if (index > 4)
        return (NULL);
    return (paths[index]);
}

mlx_texture_t **get_texture_location(size_t index, struct s_mlx_textures *textures)
{
    mlx_texture_t **p[5] = {
            &(textures->exit),
            &(textures->wall),
            &(textures->empty),
            &(textures->collectible),
            &(textures->player),
    };

    if (index > 4)
        return (NULL);
    return (p[index]);
}

mlx_image_t **get_image_location(size_t index, struct s_game_images *images)
{
    mlx_image_t **p[5] = {
            &(images->exit),
            &(images->wall),
            &(images->empty),
            &(images->collectible),
            &(images->player_img),
    };

    if (index > 4)
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