#include "minilibx-linux/mlx.h"
#include <stdlib.h>

int my_func(void *param)
{
    (void)param;

    exit(0);
    return 0;
}

int main(void)
{
    void    *mlx = mlx_init();
    void    *win = mlx_new_window(mlx, 1000, 500, "komatsuk");
    mlx_hook(win, 17, 0, my_func, "hello");
    mlx_loop(mlx);

    return (0);
}