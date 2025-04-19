/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultils_end.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukorman <lukorman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:12:12 by lukorman          #+#    #+#             */
/*   Updated: 2025/04/18 21:29:49 by lukorman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map(t_map *map)
{
	int	i;

	if (!map->grid)
		return;
	i = 0;
	while (i < map->height)
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
	map->grid = NULL;
}

void	close_game(void *game)
{
	t_game	*gamet;

	gamet = (t_game *)game;
	free_map(&gamet->map);
	mlx_close_window(gamet->mlx);
}

void	handle_input(void *param)
{
	t_game	*game = (t_game *)param;

	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		close_game(game);
}
