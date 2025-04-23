/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 23:35:38 by luiza             #+#    #+#             */
/*   Updated: 2025/04/22 23:35:56 by luiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	check_horizontal_walls(t_game *game)
{
	int	x;

	x = 0;
	while (x < game->map.width)
	{
		if (game->map.grid[0][x] != '1' ||
			game->map.grid[game->map.height - 1][x] != '1')
		{
			ft_printf("Error\nMap must be surrounded by walls\n");
			free_map(&game->map);
			exit(EXIT_FAILURE);
		}
		x++;
	}
}

static void	check_vertical_walls(t_game *game)
{
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		if (game->map.grid[y][0] != '1' ||
			game->map.grid[y][game->map.width - 1] != '1')
		{
			ft_printf("Error\nMap must be surrounded by walls\n");
			free_map(&game->map);
			exit(EXIT_FAILURE);
		}
		y++;
	}
}

void	validate_map_walls(t_game *game)
{
	check_horizontal_walls(game);
	check_vertical_walls(game);
}
