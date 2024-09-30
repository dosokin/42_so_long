#include "libft.h"
#include "error.h"
#include "solong.h"

void delete_game_images(struct s_game_images *images, mlx_t *mlx)
{
    mlx_image_t **image;
    size_t i;

    if (!images)
        return ;
    i = 0;
    while (i < 5)
    {
        image = get_image_location(i, images);
        if (*image)
        {
            mlx_delete_image(mlx, *image);
            *image = NULL;
        }
        i++;
    }
}

void delete_textures(struct s_mlx_textures *textures)
{
    size_t i;
    mlx_texture_t *texture;

    i = 0;
    while (i < 5)
    {
        texture = *(get_texture_location(i, textures));
        if (texture)
            mlx_delete_texture(texture);
        i++;
    }
}
