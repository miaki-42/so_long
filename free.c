/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 03:12:49 by komatsuk          #+#    #+#             */
/*   Updated: 2026/01/19 05:33:15 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_grid(char **grid)
{
	int	i;

	i = 0;
	while (grid[i])
		free(grid[i++]);
	free(grid);
}

void	free_game(t_game *game)
{
	if (game->map.grid)
		free_grid(game->map.grid);
	//if (game->mlx.mlxptr)
	//	;
	if (game->mlx.winptr)
		mlx_destroy_window(game->mlx.mlxptr, game->mlx.winptr);
	if (game->mlx.empty.imgptr)
		mlx_destroy_image(game->mlx.mlxptr, game->mlx.empty.imgptr);
	if (game->mlx.wall.imgptr)
		mlx_destroy_image(game->mlx.mlxptr, game->mlx.wall.imgptr);
	if (game->mlx.collectible.imgptr)
		mlx_destroy_image(game->mlx.mlxptr, game->mlx.collectible.imgptr);
	if (game->mlx.exit_open.imgptr)
		mlx_destroy_image(game->mlx.mlxptr, game->mlx.exit_open.imgptr);
	if (game->mlx.exit_close.imgptr)
		mlx_destroy_image(game->mlx.mlxptr, game->mlx.exit_close.imgptr);
	if (game->mlx.player.imgptr)
		mlx_destroy_image(game->mlx.mlxptr, game->mlx.player.imgptr);
}