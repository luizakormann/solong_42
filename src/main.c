/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukorman <lukorman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:34:06 by luiza             #+#    #+#             */
/*   Updated: 2025/04/11 22:52:18 by lukorman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		write(2, "Error: usage ./so_long <map_file>\n", 34);
		return (1);
	}
	init_game(&game, argv[1]);
	render_map(&game);
	//mlx_key_hook(game.win, key_hook, &game);
	mlx_loop(game.mlx);
	return (0);
}
