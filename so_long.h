/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:59:25 by komatsuk          #+#    #+#             */
/*   Updated: 2026/01/19 08:27:39 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE_SIZE 64

# include <fcntl.h>

# include "libft/include/libft.h"
# include "minilibx-linux/mlx.h"

typedef struct s_map
{
    char	**grid;
    int		w;
    int		h;
    int		collectible_cnt;
	int		exit_cnt;
	int		start_cnt;
}t_map;

typedef struct s_player
{
	int	x;
	int	y;
	int	move_cnt;
	int	collectible_cnt;
}t_player;

//名前？
typedef struct s_img
{
	void	*imgptr;
	int		w;
	int		h;
}	t_img;

typedef struct s_mlx
{
	void	*mlxptr;
	void	*winptr;
	t_img	empty;
	t_img	wall;
	t_img	collectible;
	t_img	exit_open;
	t_img	exit_close;
	t_img	player;
}   t_mlx;

typedef struct s_game
{
	t_map		map;
	t_player	player;
	t_mlx		mlx;
}t_game;

// parse & validate & has_path
bool	check_arg(int argc, char *argv[]);
bool	parse_map(t_game *game, char *filename);
bool	validate_map(t_game *game);
bool	has_path(t_game *game);

// init
void	set_game_null(t_game *game);
bool	init_mlx(t_game *game);

// render
void	render_map(t_game *game);

// free
void	free_game(t_game *game);

// utils
void	puterr();
int		my_strcmp(const char *s1, const char *s2);

#endif