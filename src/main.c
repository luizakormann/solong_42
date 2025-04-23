/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:34:06 by luiza             #+#    #+#             */
/*   Updated: 2025/04/22 21:52:30 by luiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Incorrect input.\n To run the game enter: ./so_long <map_file>\n");
		return (EXIT_FAILURE);
	}
	if (!validate_file_extension(argv[1]))
	{
		ft_printf("Error\nInvalid file extension. Use .ber files.\n");
		return (EXIT_FAILURE);
	}
	init_game(&game, argv[1]);
	load_textures(&game);
	render_background(&game);
	render_map(&game);
	mlx_key_hook(game.mlx, key_handler, &game);
	mlx_close_hook(game.mlx, close_game, &game);
	mlx_loop(game.mlx);
	free_images(&game);
	free_textures(&game);
	free_map(&game.map);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}
