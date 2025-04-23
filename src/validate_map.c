/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:19:16 by lukorman          #+#    #+#             */
/*   Updated: 2025/04/22 22:13:37 by luiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_window(int map_w, int map_h, int *win_w, int *win_h)
{
	*win_h = map_h * HEIGHT_TILE;
	*win_w = map_w * HEIGHT_TILE;


	if (*win_h > HEIGHT)
		*win_h = HEIGHT;
	if (*win_w > WIDTH)
		*win_w = WIDTH;
}

void	check_map_ret(char *line, int current_wid, int expected_wid, int fd)
{
	if (current_wid != expected_wid)
	{
		ft_printf("Error: Map is not rectangular.");
		free(line);
		close(fd);
		exit(EXIT_FAILURE);
	}
}

void	validate_map_elements(t_game *game)
{
	int x;
	int y;
	int exits;
	int players;
	int collectibles;

	exits = 0;
	players = 0;
	collectibles = 0;
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.grid[y][x] == 'E')
				exits++;
			else if (game->map.grid[y][x] == 'P')
				players++;
			else if (game->map.grid[y][x] == 'C')
				collectibles++;
			else if (game->map.grid[y][x] != '0' && game->map.grid[y][x] != '1')
			{
				ft_printf("Error\nInvalid map element(s)\n");
				free_map(&game->map);
				exit(EXIT_FAILURE);
			}
			x++;
		}
		y++;
	}
	if (exits != 1 || players != 1 || collectibles < 1)
	{
		ft_printf("Error\nThe map must contain extactly: 1 (E), 1 (P)] and 1+ (C)");
		free_map(&game->map);
		exit(EXIT_FAILURE);
	}
	game->collectibles = collectibles;
}

void	validate_map_walls(t_game *game)
{
	int x;
	int y;

	x = 0;
	while (x < game->map.width)
	{
		if (game->map.grid[0][x] != '1' ||
			game->map.grid[game->map.height - 1][x] != '1')
		{
			ft_printf("Error\nO mapa deve estar cercado por paredes\n");
			free_map(&game->map);
			exit(EXIT_FAILURE);
		}
		x++;
	}
	y = 0;
	while (y < game->map.height)
	{
		if (game->map.grid[y][0] != '1' ||
			game->map.grid[y][game->map.width - 1] != '1')
		{
			ft_printf("Error\nO mapa deve estar cercado por paredes\n");
			free_map(&game->map);
			exit(EXIT_FAILURE);
		}
		y++;
	}
}

void	validate_map(t_game *game)
{
	validate_map_elements(game);
	validate_map_walls(game);
	game->collected = 0;
	game->moves = 0;
}
