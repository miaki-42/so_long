/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 04:02:55 by komatsuk          #+#    #+#             */
/*   Updated: 2026/01/19 18:02:04 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**mapcpy(t_game *game)
{
	char	**cpy;
	int		y;

	cpy = malloc(sizeof(char *) * (game->map.h + 1));
	if (!cpy)
		return (NULL);
	cpy[game->map.h] = NULL;
	y = 0;
	while (game->map.grid[y])
	{
		cpy[y] = ft_strdup(game->map.grid[y]);
		if (!cpy[y])
			return (free_grid(cpy), NULL);
		y++;
	}
	return (cpy);
}


static void	rec(char **cpy, int y, int x)
{
	cpy[y][x] = '1';
	if (cpy[y - 1][x] != '1')
		rec(cpy, y - 1, x);
	if (cpy[y][x - 1] != '1')
		rec(cpy, y, x - 1);
	if (cpy[y + 1][x] != '1')
		rec(cpy, y + 1, x);
	if (cpy[y][x + 1] != '1')
		rec(cpy, y, x + 1);
}

static bool	is_validpath(char **cpy, int w, int h)
{
	int	y;
	int	x;

	y = 0;
	while (y < h)
	{
		x = 0;
		while (x < w)
		{
			if (cpy[y][x] == 'E' || cpy[y][x] == 'C')
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}

bool	has_path(t_game *game)
{
	char	**cpy;

	cpy = mapcpy(game);
	if (!cpy)
		return (false);
	rec(cpy, game->player.y, game->player.x);
	if (!is_validpath(cpy, game->map.w, game->map.h))
		return (free_grid(cpy), false);
	return (free_grid(cpy), true);
}
