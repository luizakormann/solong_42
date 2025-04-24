/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukorman <lukorman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:44:28 by luiza             #+#    #+#             */
/*   Updated: 2025/04/23 21:41:27 by lukorman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void		render_background(t_game *game);
static void	render_tile(t_game *game, char tile, int x, int y);
static int	calculate_tile_h(t_game *game);
static int	calculate_tile_w(t_game *game);

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
	int			tile_w;
	int			tile_h;

	img = NULL;
	tile_h = calculate_tile_h(game);;
	tile_w = 0;

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
		mlx_resize_image(img, tile_w, tile_h);
		mlx_image_to_window(game->mlx, img, x * tile_w, y * tile_h);
		add_image(game, img);
	}
}

static int	calculate_tile_h(t_game *game)
{
	int	window_w;
	int	window_h;
	int	tile_h;

	mlx_get_window_size(game->mlx, &window_w, &window_h);
	tile_h = window_h / game->map.height;
	if (tile_h > window_w / game->map.width)
		tile_h = window_w / game->map.width;
	if (tile_h < 16)
		tile_h = 16;
	return (tile_h);
}

static int	calculate_tile_w(t_game *game)
{
	int	window_w;
	int	window_h;
	int	tile_w;

	mlx_set_window_size(game->mlx, window_w, window_h);
	tile_w = window_w / game->map.width;
	if (tile_w > window_h / game->map.height)
		tile_w = window_h / game->map.height;
	if (tile_w < 16)
		tile_w = 16;
	return (tile_w);
}
