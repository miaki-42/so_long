/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 16:33:11 by komatsuk          #+#    #+#             */
/*   Updated: 2026/01/19 08:27:23 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_game_null(t_game *game)
{
	game->map.grid = NULL;
	game->map.h = 0;
	game->map.w = 0;
	game->map.collectible_cnt = 0;
	game->map.exit_cnt = 0;
	game->map.start_cnt = 0;
	game->player.x = 0;
	game->player.y = 0;
	game->player.move_cnt = 0;
	game->player.collectible_cnt = 0;
	game->mlx.mlxptr = NULL;
	game->mlx.winptr = NULL;
	game->mlx.empty.imgptr = NULL;
	game->mlx.wall.imgptr = NULL;
	game->mlx.collectible.imgptr = NULL;
	game->mlx.exit_open.imgptr = NULL;
	game->mlx.exit_close.imgptr = NULL;
	game->mlx.player.imgptr = NULL;
}

static bool	load_xpm(t_game *game, char *filepath, t_img *texture)
{
	texture->imgptr = mlx_xpm_file_to_image(game->mlx.mlxptr, filepath,
			&texture->w, &texture->h);
	return (texture->imgptr != NULL);
}

static bool	init_image(t_game *game)
{
	if (!load_xpm(game, "textures/empty.xpm", &game->mlx.empty)
		|| !load_xpm(game, "textures/wall.xpm", &game->mlx.wall)
		|| !load_xpm(game, "textures/collectible.xpm", &game->mlx.collectible)
		|| !load_xpm(game, "textures/exit_open.xpm", &game->mlx.exit_open)
		|| !load_xpm(game, "textures/exit_close.xpm", &game->mlx.exit_close)
		|| !load_xpm(game, "textures/player.xpm", &game->mlx.player))
		return (false);
	return (true);
}

bool	init_mlx(t_game *game)
{
	game->mlx.mlxptr = mlx_init();
	if (!game->mlx.mlxptr)
		return (free_game(game), false);
	if (!init_image(game))
		return (free_game(game), false);
	game->mlx.winptr = mlx_new_window(game->mlx.mlxptr,
			TILE_SIZE * game->map.w, TILE_SIZE * game->map.h, "so_long");
	if (!game->mlx.winptr)
		return (free_game(game), false);
	render_map(game);
	return (true);
}

