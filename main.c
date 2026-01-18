/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:23:22 by komatsuk          #+#    #+#             */
/*   Updated: 2026/01/19 08:24:10 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	set_game_null(&game);
	if (!check_arg(argc, argv))
		return (1);
	if (!parse_map(&game, argv[1]))
		return (1);
	if (!init_mlx(&game))
		return (1);
	mlx_loop(game.mlx.mlxptr);
	return (0);
}