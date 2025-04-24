/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukorman <lukorman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:31:05 by luiza             #+#    #+#             */
/*   Updated: 2025/04/23 21:25:37 by lukorman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	count_collectibles(t_game *game);
static void	check_window(int map_w, int map_h, int *win_w, int *win_h);

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
	game->mlx = mlx_init(window_w, window_h, "so_long", TRUE);
	if (!game->mlx)
	{
		free_map(&game->map);
		ft_printf("Error initializing MLX");
		exit(EXIT_FAILURE);
	}
	mlx_resize_hook(game->mlx, resize_handler, game);
	init_images(game);
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

static void	check_window(int map_w, int map_h, int *win_w, int *win_h)
{
	*win_h = map_h * HEIGHT_TILE;
	*win_w = map_w * HEIGHT_TILE;
	if (*win_h > HEIGHT)
		*win_h = HEIGHT;
	if (*win_w > WIDTH)
		*win_w = WIDTH;
}
