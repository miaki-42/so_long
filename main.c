/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:23:22 by komatsuk          #+#    #+#             */
/*   Updated: 2026/01/17 16:40:40 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	// Validate arg
	if (!validate_arg(argc, argv))
		return (1);

	// Init map-player && Parse map
	init_gamedata(&game);
	if (!parse_map(&game, argv[1]))
		return (1);
	
	// Initialize mlx
	if (!init_mlx(&game))
		return (1);
	

	return (0);
}