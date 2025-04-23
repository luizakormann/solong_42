/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_init_txts.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:37:47 by lukorman          #+#    #+#             */
/*   Updated: 2025/04/23 00:01:05 by luiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	load_single_texture(mlx_texture_t **texture, char *path);

void	load_textures(t_game *game)
{
	load_single_texture(&game->textures.floor,
		"./textures/floor.png");
	load_single_texture(&game->textures.collectible,
		"./textures/collectible.png");
	load_single_texture(&game->textures.exit,
		"./textures/exit.png");
	load_single_texture(&game->textures.player,
		"./textures/player.png");
	load_single_texture(&game->textures.wall,
		"./textures/wall.png");
}

static void	load_single_texture(mlx_texture_t **texture, char *path)
{
	*texture = mlx_load_png(path);
	if (!*texture)
	{
		ft_printf("Error loading texture: %s\n", path);
		exit(EXIT_FAILURE);
	}
}
