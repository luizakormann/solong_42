/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukorman <lukorman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:44:28 by luiza             #+#    #+#             */
/*   Updated: 2025/05/04 17:08:42 by lukorman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void		render_map(t_game *game);
static void	render_tile(t_game *game, char tile, int x, int y);
static int	resize_hei(t_game *game);
static int	resize_wid(t_game *game);
void		render_background(t_game *game);

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

static void	render_tile(t_game *game, char tile, int x, int y)
{
	mlx_image_t	*img;
	int			tile_width;
	int			tile_height;

	img = NULL;
	tile_height = resize_hei(game);
	tile_width = resize_wid(game);
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
		mlx_resize_image(img, tile_width, tile_height);
		mlx_image_to_window(game->mlx, img, x * tile_width, y * tile_height);
		add_image(game, img);
	}
}

static int	resize_hei(t_game *game)
{
	int	tile_height;

	tile_height = (game->hei / game->map.height);
	if (tile_height > HEIGHT_TILE)
		tile_height = HEIGHT_TILE;
	return (tile_height);
}

static int	resize_wid(t_game *game)
{
	int	tile_width;

	tile_width = (game->wid / game->map.width);
	if (tile_width > WIDTH_TILE)
		tile_width = WIDTH_TILE;
	return (tile_width);
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
	if (map_width_px > game->wid)
		map_width_px = game->wid;
	if (map_height_px > game->hei)
		map_height_px = game->hei;
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
