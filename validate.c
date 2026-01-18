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

bool	check_arg(int argc, char *argv[])
{
	char	*last_dot;

	if (argc != 2)
		return (puterr(), false);
	last_dot = ft_strrchr(argv[1], '.');
	if (!last_dot)
		return (puterr(), false);
	if (my_strcmp(last_dot, ".ber"))
		return (puterr(), false);
	return (true);
}

static bool	is_edge(t_game *game, int y, int x)
{
	if (y == 0 || y == game->map.h - 1)
		return (true);
	if (x == 0 || x == game->map.w - 1)
		return (true);
	return (false);
}

static bool	set_map_stats(t_game *game, int y, int x)
{
	if (game->map.grid[y][x] == '0' || game->map.grid[y][x] == '1')
		return (true);
	if (game->map.grid[y][x] == 'C')
	{
		game->map.collectible_cnt++;
		return (true);
	}
	if (game->map.grid[y][x] == 'E')
	{
		game->map.exit_cnt++;
		return (true);
	}
	if (game->map.grid[y][x] == 'P')
	{
		game->map.grid[y][x] = '0';
		game->map.start_cnt++;
		game->player.y = y;
		game->player.x = x;
		return (true);
	}
	return (false);
}

static bool	validate_map_format(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.h)
	{
		x = 0;
		while (x < game->map.w)
		{
			if (is_edge(game, y, x) && game->map.grid[y][x] != '1')
				return (false);
			if (!set_map_stats(game, y, x))
				return (false);
			x++;
		}
		y++;
	}
	if (game->map.collectible_cnt == 0 || game->map.exit_cnt != 1 || game->map.start_cnt != 1)
		return (false);
	return (true);
}

bool	validate_map(t_game *game)
{
	if (!validate_map_format(game))
		return (free_game(game), false);
	if (!has_path(game))
		return (free_game(game), false);
	return (true);
}
