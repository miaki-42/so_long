/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:59:25 by komatsuk          #+#    #+#             */
/*   Updated: 2026/01/17 16:59:52 by komatsuk         ###   ########.fr       */
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
    int		h;
    int		w;
    int		collectible_cnt;
	int		exit_cnt;
	int		start_cnt;
    int		start_x;
    int		start_y;
}t_map;

typedef struct s_player
{
	int	x;
	int	y;
	int	move_cnt;
	int	collectible_cnt;
}t_player;

typedef struct s_img
{
	void	*imgptr;
	int		h;
	int		w;
}	t_img;

typedef struct s_mlx
{
	void	*mlxptr;
	void	*winptr;
	t_img	empty;
	t_img	wall;
	t_img	collectible;
	t_img	mapexit;
	t_img	playericon;
}   t_mlx;

typedef struct s_game
{
	t_map		map;
	t_player	player;
	t_mlx		mlx;
}t_game;

// parse
bool	validate_arg(int argc, char *argv[]);
bool	parse_map(t_game *game, char *filename);

// parse-sup
t_list	*read_mapfile(char *filename);
bool	validate_map(t_game *game);
bool	has_path(t_game *game);

// init
void	init_gamedata(t_game *game);

// free
void	free_grid(char **grid, int n);

// utils
void	puterr();
int		my_strcmp(const char *s1, const char *s2);

#endif