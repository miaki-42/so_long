/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 16:33:11 by komatsuk          #+#    #+#             */
/*   Updated: 2026/01/18 17:28:15 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_gamedata(t_game *game)
{
	game->map.grid = NULL;
	game->map.h = 0;
	game->map.w = 0;
	game->map.collectible_cnt = 0;
	game->map.exit_cnt = 0;
	game->map.start_cnt = 0;
	game->map.start_x = 0;
	game->map.start_y = 0;
	game->player.x = 0;
	game->player.y = 0;
	game->player.move_cnt = 0;
	game->player.collectible_cnt = 0;
}

static void	set_mlx_null(t_game *game)
{
	game->mlx.mlxptr = NULL;
	game->mlx.winptr = NULL;
	game->mlx.empty.imgptr = NULL;
	game->mlx.wall.imgptr = NULL;
	game->mlx.collectible.imgptr = NULL;
	game->mlx.exit_open.imgptr = NULL;
	game->mlx.exit_close.imgptr = NULL;
	game->mlx.player.imgptr = NULL;
}

// サイズによる分岐
static bool	init_image(t_game *game)
{
	game->mlx.empty.imgptr = mlx_xpm_file_to_image(game->mlx.mlxptr, "", game->mlx.empty.w, game->mlx.empty.h);
	if (!game->mlx.empty.imgptr)

}

// allfree

bool	init_mlx(t_game *game)
{
	set_mlx_null(game);
	game->mlx.mlxptr = mlx_init();
	if (!game->mlx.mlxptr)
		return (free_grid(game->map.grid, game->map.h), false);
	
}

