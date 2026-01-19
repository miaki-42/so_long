/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 05:51:32 by komatsuk          #+#    #+#             */
/*   Updated: 2026/01/19 09:48:36 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	render_tile(t_game *game, int y, int x)
{
	void	*imgptr;

	if (y == game->player.y && x == game->player.x)
	{
		if (game->map.grid[y][x] == 'E'
			&& game->map.collectible_cnt != game->player.collectible_cnt)
			imgptr = game->mlx.player_exit_close.imgptr;
		else
			imgptr = game->mlx.player.imgptr;
	}
	else if (game->map.grid[y][x] == '0')
		imgptr = game->mlx.empty.imgptr;
	else if (game->map.grid[y][x] == '1')
		imgptr = game->mlx.wall.imgptr;
	else if (game->map.grid[y][x] == 'C')
		imgptr = game->mlx.collectible.imgptr;
	else if (game->map.grid[y][x] == 'E')
	{
		if (game->map.collectible_cnt == game->player.collectible_cnt)
			imgptr = game->mlx.exit_open.imgptr;
		else
			imgptr = game->mlx.exit_close.imgptr;
	}
	mlx_put_image_to_window(game->mlx.mlxptr, game->mlx.winptr,
		imgptr, TILE_SIZE * x, TILE_SIZE * y);
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
