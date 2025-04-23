/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:12:12 by lukorman          #+#    #+#             */
/*   Updated: 2025/04/22 21:56:32 by luiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map(t_map *map)
{
	int	i;

	if (!map->grid)
		return;
	i = 0;
	while (i < map->height)
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
	map->grid = NULL;
}

void	free_textures(t_game *game)
{
	if (game->textures.wall)
	{
		mlx_delete_texture(game->textures.wall);
		game->textures.wall = NULL;
	}
	if (game->textures.floor)
	{
		mlx_delete_texture(game->textures.floor);
		game->textures.floor = NULL;
	}
	if (game->textures.player)
	{
		mlx_delete_texture(game->textures.player);
		game->textures.player = NULL;
	}
	if (game->textures.exit)
	{
		mlx_delete_texture(game->textures.exit);
		game->textures.exit = NULL;
	}
	if (game->textures.collectible)
	{
		mlx_delete_texture(game->textures.collectible);
		game->textures.collectible = NULL;
	}
}

void	free_images(t_game *game)
{
	int	i;

	if (!game->images)
		return;

	i = 0;
	while (i < game->img_count)
	{
		if (game->images[i])
			mlx_delete_image(game->mlx, game->images[i]);
		i++;
	}
	free(game->images);
	game->images = NULL;
}

void	close_game(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	free_textures(game);
	free_images(game);
	free_map(&game->map);
	mlx_close_window(game->mlx);
}
