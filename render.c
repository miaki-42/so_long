/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 05:51:32 by komatsuk          #+#    #+#             */
/*   Updated: 2026/01/19 08:32:09 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	render_tile(t_game *game, int y, int x)
{
	if (y == game->player.y && x == game->player.x)
		mlx_put_image_to_window(game->mlx.mlxptr, game->mlx.winptr,
			game->mlx.player.imgptr, TILE_SIZE * x, TILE_SIZE * y);
	else if (game->map.grid[y][x] == '0')
		mlx_put_image_to_window(game->mlx.mlxptr, game->mlx.winptr,
			game->mlx.empty.imgptr, TILE_SIZE * x, TILE_SIZE * y);
	else if (game->map.grid[y][x] == '1')
		mlx_put_image_to_window(game->mlx.mlxptr, game->mlx.winptr,
			game->mlx.wall.imgptr, TILE_SIZE * x, TILE_SIZE * y);
	else if (game->map.grid[y][x] == 'C')
		mlx_put_image_to_window(game->mlx.mlxptr, game->mlx.winptr,
			game->mlx.collectible.imgptr, TILE_SIZE * x, TILE_SIZE * y);
	else if (game->map.grid[y][x] == 'E')
	{
		if (game->map.collectible_cnt == game->player.collectible_cnt)
			mlx_put_image_to_window(game->mlx.mlxptr, game->mlx.winptr,
				game->mlx.exit_open.imgptr, TILE_SIZE * x, TILE_SIZE * y);
		else
			mlx_put_image_to_window(game->mlx.mlxptr, game->mlx.winptr,
				game->mlx.exit_close.imgptr, TILE_SIZE * x, TILE_SIZE * y);
	}
}

void	render_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.h)
	{
		x = 0;
		while (x < game->map.w)
		{
			render_tile(game, y, x);
			x++;
		}
		y++;
	}
}
