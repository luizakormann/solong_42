/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:44:28 by luiza             #+#    #+#             */
/*   Updated: 2025/04/02 12:46:05 by luiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.grid[y])
	{
		x = 0;
		while (game->map.grid[y][x])
		{
			if (game->map.grid[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->textures.wall, x * WIDTH_TILE, y * HEIGHT_TILE);
			else if (game->map.grid[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->textures.player, x * WIDTH_TILE, y * HEIGHT_TILE);
			else if (game->map.grid[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->textures.collectible, x * WIDTH_TILE, y * HEIGHT_TILE);
			else if (game->map.grid[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->textures.exit, x * WIDTH_TILE, y * HEIGHT_TILE);
			else
				mlx_put_image_to_window(game->mlx, game->win, game->textures.background, x * WIDTH_TILE, y * HEIGHT_TILE);
			x++;
		}
		y++;
	}
}
