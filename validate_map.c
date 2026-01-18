/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.game->map.grid[i][j]                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 03:15:34 by komatsuk          #+#    #+#             */
/*   Updated: 2026/01/17 03:59:44 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	is_edge(t_game *game, int i, int j)
{
	if (i == 0 || i == game->map.h - 1)
		return (true);
	if (j == 0 || j == game->map.w - 1)
		return (true);
	return (false);
}

static bool	set_map_stats(t_game *game, int i, int j)
{
	if (game->map.grid[i][j] == '0' || game->map.grid[i][j] == '1')
		return (true);
	if (game->map.grid[i][j] == 'C')
	{
		game->map.collectible_cnt++;
		return (true);
	}
	if (game->map.grid[i][j] == 'E')
	{
		game->map.exit_cnt++;
		return (true);
	}
	if (game->map.grid[i][j] == 'P')
	{
		game->map.start_cnt++;
		game->map.start_x = i;
		game->map.start_y = j;
		game->player.x = i;
		game->player.y = j;
		return (true);
	}
	return (false);
}

static bool	validate_map_format(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.h)
	{
		j = 0;
		while (j < game->map.w)
		{
			if (is_edge(game, i, j) && game->map.grid[i][j] != '1')
				return (false);
			if (!set_map_stats(game, i, j))
				return (false);
			j++;
		}
		i++;
	}
	if (game->map.collectible_cnt == 0 || game->map.exit_cnt != 1 || game->map.start_cnt != 1)
		return (false);
	return (true);
}

bool	validate_map(t_game *game)
{
	if (!validate_map_format(game))
		return (free_grid(game->map.grid, game->map.h), false);
	if (!has_path(game))
		return (free_grid(game->map.grid, game->map.h), false);
	return (true);
}
