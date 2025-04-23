/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:31:05 by luiza             #+#    #+#             */
/*   Updated: 2025/04/22 21:55:28 by luiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	count_collectibles(t_game *game);


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
	validate_map(game);
	validate_path(game);
	count_collectibles(game);
	check_window(game->map.width, game->map.height, &window_w, &window_h);
	game->mlx = mlx_init(window_w, window_h, "so_long", FALSE);
	if (!game->mlx)
	{
		free_map(&game->map);
		ft_printf("Error initializing MLX");
		exit(EXIT_FAILURE);
	}
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


static void	count_collectibles(t_game *game)
{
	int	x;
	int	y;

	game->collectibles = 0;
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.grid[y][x] == 'C')
				game->collectibles++;
			x++;
		}
		y++;
	}
	game->collected = 0;
	game->moves = 0;
}
