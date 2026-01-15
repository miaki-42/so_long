#include "minilibx-linux/mlx.h"

void    my_func()
{
    exit(0)
}

int main(void)
{
    void    *mlx = mlx_init();
    void    *win = mlx_new_window(mlx, 1000, 500, "komatsuk");
    mlx_hook(win, 17, 0, my_func())
    mlx_loop(mlx);

    return (0);
}