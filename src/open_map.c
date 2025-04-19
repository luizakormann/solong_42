/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukorman <lukorman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:34:36 by luiza             #+#    #+#             */
/*   Updated: 2025/04/18 21:08:51 by lukorman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	open_map(t_game *game, const char *map_file)
{
	int		fd;
	char	*line;
	char	*pos;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening map file");
		exit(EXIT_FAILURE);
	}
	pos = NULL;
	game->map.height = 0;
	game->map.width = 0;
	game->map.grid = NULL;
	while ((line = get_next_line(fd)))
	{
		game->map.height++;
		if (game->map.width == 0)
			game->map.width = ft_strlen(line);
		game->map.grid = (malloc(sizeof(char *) * (game->map.height + 1)));
		if (!game->map.grid)
		{
			perror("Error allocating map grid");
			exit(EXIT_FAILURE);
		}
		game->map.grid[game->map.height - 1] = line;
		if (game->player.x == 0 && game->player.y == 0)
		{
			pos = ft_strrchr(line, 'P');
			if (pos)
			{
				game->player.x = pos - line;
				game->player.y = game->map.height - 1;
			}
		}
	}
	game->map.grid[game->map.height] = NULL;
	close(fd);
}
