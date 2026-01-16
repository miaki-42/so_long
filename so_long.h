/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:59:25 by komatsuk          #+#    #+#             */
/*   Updated: 2026/01/17 04:03:46 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>

# include "libft/include/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"

typedef struct s_map
{
    char	**grid;
    size_t	h;
    size_t	w;
    size_t	collectible_cnt;
	size_t	exit_cnt;
	size_t	start_cnt;
    size_t	start_x;
    size_t	start_y;
}t_map;

typedef struct s_player
{
	size_t	x;
	size_t	y;
	size_t	collectible_cnt;
}t_player;

//typedef struct s_mlx
//{

//}   t_mlx;

typedef struct s_game
{
	t_map		map;
	t_player	player;
	//t_mlx		mlx;
}t_game;

// parse
bool	validate_arg(int argc, char *argv[]);
bool	mapsize(t_game *game, t_list *maplst);
bool	create_map(t_game *game, t_list *maplst);
bool	parse_map(t_game *game, char *filename);

// read_mapfile
t_list	*read_mapfile(char *filename);

// validate_map
bool	validate_map(t_game *game);

// has_path
bool	has_path(t_game *game);

// free
void	free_grid(char **grid, size_t n);

// utils
void	puterr();
int		my_strcmp(const char *s1, const char *s2);

#endif