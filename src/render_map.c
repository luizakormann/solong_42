/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:44:28 by luiza             #+#    #+#             */
/*   Updated: 2025/04/22 22:39:15 by luiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	render_background(t_game *game)
{
	mlx_image_t	*bg;
	int			map_width_px;
	int			map_height_px;

	free_images(game);
	init_images(game);
	map_width_px = game->map.width * WIDTH_TILE;
	map_height_px = game->map.height * HEIGHT_TILE;
	bg = mlx_texture_to_image(game->mlx, game->textures.floor);
	if (!bg)
	{
		ft_printf("Error loading background image\n");
		exit(EXIT_FAILURE);
	}
	mlx_resize_image(bg, map_width_px, map_height_px);
	mlx_image_to_window(game->mlx, bg, 0, 0);
	add_image(game, bg);
}

static void	render_tile(t_game *game, char tile, int x, int y)
{
	mlx_image_t	*img;

	img = NULL;
	if (tile == '1')
		img = mlx_texture_to_image(game->mlx, game->textures.wall);
	else if (tile == 'P')
		img = mlx_texture_to_image(game->mlx, game->textures.player);
	else if (tile == 'E')
		img = mlx_texture_to_image(game->mlx, game->textures.exit);
	else if (tile == 'C')
		img = mlx_texture_to_image(game->mlx, game->textures.collectible);
	else
		return ;
	if (img)
	{
		mlx_resize_image(img, WIDTH_TILE, HEIGHT_TILE);
		mlx_image_to_window(game->mlx, img, x * WIDTH_TILE, y * HEIGHT_TILE);
		add_image(game, img);
	}
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
