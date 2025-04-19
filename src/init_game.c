/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukorman <lukorman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:31:05 by luiza             #+#    #+#             */
/*   Updated: 2025/04/19 00:58:34 by lukorman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_game(t_game *game, char *map_file)
{
	int	window_h;
	int	window_w;

	window_h = HEIGHT;
	window_w = WIDTH;
	game->map.grid = NULL;
    game->images = NULL;
    game->textures.wall = NULL;
    game->textures.floor = NULL;
    game->textures.player = NULL;
    game->textures.exit = NULL;
    game->textures.collectible = NULL;
	open_map(game, map_file);
	check_window(game->map.width, game->map.height, &window_w, &window_h);
	game->mlx = mlx_init(window_w, window_h, "so_long", TRUE);
	if (!game->mlx)
	{
		free_map(&game->map);
		ft_printf("Error initializing MLX");
		exit(EXIT_FAILURE);
	}
	game->player.x = 0;
	game->player.y = 0;
	init_images(game);
}
