/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukorman <lukorman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:34:06 by luiza             #+#    #+#             */
/*   Updated: 2025/04/19 01:58:07 by lukorman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Incorrect input.\n To run the game enter: ./so_long <map_file>\n");
		return (EXIT_FAILURE);
	}
	init_game(&game, argv[1]);
	load_textures(&game);
	render_background(&game);
	render_map(&game);
	mlx_close_hook(game.mlx, close_game, &game);
	mlx_loop_hook(game.mlx, handle_input, &game);
	mlx_loop(game.mlx);
	free_images(&game);
    free_textures(&game);
    free_map(&game.map);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}
