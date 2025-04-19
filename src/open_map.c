/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukorman <lukorman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:34:36 by luiza             #+#    #+#             */
/*   Updated: 2025/04/18 23:57:30 by lukorman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	count_map_lines(const char *map_file, int *line_count)
{
	int		fd;
	char	*line;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening map file");
		exit(EXIT_FAILURE);
	}
	*line_count = 0;
	while ((line = get_next_line(fd)))
	{
		(*line_count)++;
		free(line);
	}
	close(fd);
}

void	read_map_content(t_game *game, const char *map_file, int line_count)
{
	int		fd;
	char	*line;
	int		i;
	char	*pos;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		perror("Error reopening map file");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while ((line = get_next_line(fd)) && i < line_count)
	{
		game->map.grid[i] = line;
		if (i == 0)
			game->map.width = ft_strlen(line);
		pos = ft_strrchr(line, 'P');
		if (pos)
		{
			game->player.x = pos - line;
			game->player.y = i;
		}
		i++;
	}
	game->map.grid[i] = NULL;
	close(fd);
}

void	open_map(t_game *game, const char *map_file)
{
	int	line_count;

	line_count = 0;
	count_map_lines(map_file, &line_count);
	game->map.height = line_count;
	game->map.grid = malloc(sizeof(char *) * (line_count + 1));
	if (!game->map.grid)
	{
		perror("Error allocating map grid");
		exit(EXIT_FAILURE);
	}
	read_map_content(game, map_file, line_count);
}
