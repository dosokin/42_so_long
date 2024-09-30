#include "libft.h"
#include "error.h"
#include "solong.h"

static void	await_esc(void *p)
{
    mlx_t  *mlx;

    mlx = p;
    if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
        mlx_close_window(mlx);
}

static void	win_case()
{
    mlx_t           *mlx;
    mlx_texture_t	*success_texture;
    mlx_image_t     *success_img;

    mlx = mlx_init(800, 800, "CONGRATS", false);
    if (!mlx)
        return;
    success_texture = mlx_load_png("textures/manda/success.png");
    if (success_texture)
    {
        success_img = mlx_texture_to_image(mlx, success_texture);
        if (success_img && mlx_image_to_window(mlx, success_img, 0, 0) >= 0)
        {
            //system("paplay audio/win_sound.wav --volume=65536");
            mlx_loop_hook(mlx, await_esc, mlx);
            mlx_loop(mlx);
        }
        mlx_delete_texture(success_texture);
    }
    mlx_terminate(mlx);
}

void clean_exit(t_game_data *game_data)
{
    delete_game_images(&(game_data->mlx_data.images), game_data->mlx_data.mlx);
    if (game_data->mlx_data.mlx)
        mlx_terminate(game_data->mlx_data.mlx);
    if (game_data->map)
        free_array(game_data->map);
    if (game_data->game_logic.status == WIN)
        win_case();
}