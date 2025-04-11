/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:34:36 by luiza             #+#    #+#             */
/*   Updated: 2025/04/02 12:54:06 by luiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int  get_map_width(const char *line);

void	load_map(t_game *game, const char *map_file)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening map file");
		exit(EXIT_FAILURE);
	}

	game->map.height = 0;
	game->map.width = 0;
	game->map.grid = NULL;

	while ((line = get_next_line(fd)))
	{
		game->map.height++;
		if (game->map.width == 0)
			game->map.width = get_map_width(line);

		game->map.grid = realloc(game->map.grid, sizeof(char *) * (game->map.height + 1));
		if (!game->map.grid)
		{
			perror("Error allocating map grid");
			exit(EXIT_FAILURE);
		}
		game->map.grid[game->map.height - 1] = line;

		if (game->player.x == 0 && game->player.y == 0)
		{
			char *pos = strchr(line, 'P');
			if (pos)
			{
				game->player.x = pos - line;
				game->player.y = game->map.height - 1;
			}
		}
	}
	game->map.grid[game->map.height] = NULL;
}

static int  get_map_width(const char *line)
{
	int width = 0;
	while (line[width] && line[width] != '\n')
		width++;
	return (width);
}
