/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukorman <lukorman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:44:28 by luiza             #+#    #+#             */
/*   Updated: 2025/04/18 21:49:04 by lukorman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	render_tile(t_game *game, char tile, int x, int y)
{
	mlx_image_t	*img;

	if (tile == '1')
		img = mlx_texture_to_image(game->mlx, game->textures.wall);
	else if (tile == '0')
		img = mlx_texture_to_image(game->mlx, game->textures.floor);
	else if (tile == 'P')
		img = mlx_texture_to_image(game->mlx, game->textures.player);
	else if (tile == 'E')
		img = mlx_texture_to_image(game->mlx, game->textures.exit);
	else if (tile == 'C')
		img = mlx_texture_to_image(game->mlx, game->textures.collectible);
	else
		return ;
	if (img)
		mlx_image_to_window(game->mlx, img, x * WIDTH_TILE, y * HEIGHT_TILE);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			render_tile(game, game->map.grid[y][x], x, y);
			x++;
		}
		y++;
	}
}
