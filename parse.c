/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:24:45 by komatsuk          #+#    #+#             */
/*   Updated: 2026/01/19 08:25:35 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_list	*create_maplst(int fd)
{
	t_list	*maplst;
	t_list	*node;
	char	*line;
	char	*nlp;

	maplst = NULL;
	line = get_next_line(fd);
	while (line)
	{
		nlp = ft_strchr(line, '\n');
		if (nlp)
			*nlp = '\0';
		node = ft_lstnew(line);
		if (!node)
			return (ft_lstclear(&maplst, free), NULL);
		ft_lstadd_back(&maplst, node);
		line = get_next_line(fd);
	}
	return (maplst);
}

static t_list	*read_mapfile(char *filename)
{
	t_list  *maplst;
	int	 fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	maplst = create_maplst(fd);
	if (!maplst)
		return (close(fd), NULL);
	return (close(fd), maplst);
}

static bool	mapsize(t_game *game, t_list *maplst)
{
	int		w;
	int		h;
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
	game->map.w = w;
	game->map.h = h;
	return (true);
}

static bool	create_map(t_game *game, t_list *maplst)
{
	char	**grid;
	t_list	*tmp;
	int		y;

	grid = malloc(sizeof(char *) * (game->map.h + 1));
	if (!grid)
		return (ft_lstclear(&maplst, free), false);
	grid[game->map.h] = NULL;
	tmp = maplst;
	y = 0;
	while (tmp)
	{
		grid[y] = ft_strdup(tmp->content);
		if (!grid[y])
		{
			free_game(game);
			return (ft_lstclear(&maplst, free), false);
		}
		tmp = tmp->next;
		y++;
	}
	game->map.grid = grid;
	return (true);
}

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
