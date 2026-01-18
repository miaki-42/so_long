/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:24:45 by komatsuk          #+#    #+#             */
/*   Updated: 2026/01/17 16:57:40 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	validate_arg(int argc, char *argv[])
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

static bool	mapsize(t_game *game, t_list *maplst)
{
	int		h;
	int		w;
	t_list	*tmp;

	h = ft_lstsize(maplst);
	if (h == 0)
		return (false);
	w = (int)ft_strlen(maplst->content);
	tmp = maplst;
	while (tmp)
	{
		if ((int)ft_strlen(tmp->content) != w)
			return (ft_lstclear(&maplst, free), false);
		tmp = tmp->next;
	}
	game->map.h = h;
	game->map.w = w;
	return (true);
}

static bool	create_map(t_game *game, t_list *maplst)
{
	char	**grid;
	t_list	*tmp;
	int		i;

	grid = malloc(sizeof(char *) * game->map.h);
	if (!grid)
		return (ft_lstclear(&maplst, free), false);
	tmp = maplst;
	i = 0;
	while (tmp)
	{
		grid[i] = ft_strdup(tmp->content);
		if (!grid[i])
		{
			free_grid(grid, i);
			return (ft_lstclear(&maplst, free), false);
		}
		tmp = tmp->next;
		i++;
	}
	game->map.grid = grid;
	return (true);
}

static void	init_mapcnt

bool	parse_map(t_game *game, char *filename)
{
	t_list	*maplst;

	maplst = read_mapfile(filename);
	if (!maplst)
		return (puterr(), false);
	if (!mapsize(game, maplst))
		return (puterr(), false);
	if (!create_map(game, maplst))
		return (puterr(), false);
	ft_lstclear(&maplst, free);
	if (!validate_map(game))
		return (puterr(), false);
	return (true);
}
