/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:19:16 by lukorman          #+#    #+#             */
/*   Updated: 2025/04/22 23:38:24 by luiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	check_element_counts(int exits, int player, int clct, t_game *game)
{
	if (exits != 1 || player != 1 || clct < 1)
	{
		ft_printf("Error\nThe map must contain: 1 (E), 1 (P) and 1+ (C)");
		free_map(&game->map);
		exit(EXIT_FAILURE);
	}
	game->collectibles = clct;
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

static void	count_elements(t_game *game, int *e, int *p, int *c)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.grid[y][x] == 'E')
				(*e)++;
			else if (game->map.grid[y][x] == 'P')
				(*p)++;
			else if (game->map.grid[y][x] == 'C')
				(*c)++;
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
}

void	validate_map_elements(t_game *game)
{
	int	exits;
	int	player;
	int	collectibles;

	exits = 0;
	player = 0;
	collectibles = 0;
	count_elements(game, &exits, &player, &collectibles);
	check_element_counts(exits, player, collectibles, game);
}

void	validate_map(t_game *game)
{
	validate_map_elements(game);
	validate_map_walls(game);
	game->collected = 0;
	game->moves = 0;
}
