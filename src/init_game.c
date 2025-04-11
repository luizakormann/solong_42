/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:31:05 by luiza             #+#    #+#             */
/*   Updated: 2025/04/02 12:51:39 by luiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game, char *map_file)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		perror("Error initializing MLX");
		exit(EXIT_FAILURE);
	}
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "so_long");
	if (!game->win)
	{
		perror("Error creating window");
		exit(EXIT_FAILURE);
	}
	game->player.x = 0;
	game->player.y = 0;
}
