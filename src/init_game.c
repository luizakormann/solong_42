/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukorman <lukorman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:31:05 by luiza             #+#    #+#             */
/*   Updated: 2025/04/19 17:14:35 by lukorman         ###   ########.fr       */
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
	game->mlx = mlx_init(window_w, window_h, "so_long", FALSE);
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

void	init_images(t_game *game)
{
	game->img_capacity = 100;
	game->img_count = 0;
	game->images = malloc(sizeof(mlx_image_t *) * game->img_capacity);
	if (!game->images)
	{
		ft_printf("Error: Failed to allocate memory for image tracking\n");
		exit(EXIT_FAILURE);
	}
}
