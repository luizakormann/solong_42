/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukorman <lukorman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:31:05 by luiza             #+#    #+#             */
/*   Updated: 2025/04/18 20:45:35 by lukorman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_game(t_game *game, char *map_file)
{
	int	window_h;
	int	window_w;

	window_h = HEIGHT;
	window_w = WIDTH;
	open_map(game, map_file);
	check_window(game->map.width, game->map.height, &window_w, &window_h);
	game->mlx = mlx_init(window_w, window_h, "so_long", TRUE);
	if (!game->mlx)
	{
		free_map(&game->map);
		ft_printf("Error initializing MLX");
		exit(EXIT_FAILURE);
	}
	game->player.x = 0;
	game->player.y = 0;
}
