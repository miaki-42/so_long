#include "minilibx-linux/mlx.h"

int main(void)
{
    void    *mlx = mlx_init();
    
    mlx_new_window(mlx, 1000, 500, "komatsuk");
    mlx_loop(mlx);

    return (0);
}