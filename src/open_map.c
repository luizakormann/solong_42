/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:34:36 by luiza             #+#    #+#             */
/*   Updated: 2025/05/14 21:07:05 by luiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void		init_map(t_game *game, const char *map_file);
void		read_map_content(t_game *game, const char *map_file);
static void	read_map_lines_fd(t_game *game, int fd);
static void	process_map_line(t_game *game, char *line, int i);

void	init_map(t_game *game, const char *map_file)
{
	int	line_count;

	line_count = 0;
	open_map(map_file, &line_count);
	game->map.height = line_count;
	game->map.grid = malloc(sizeof(char *) * (line_count + 1));
	if (!game->map.grid)
	{
		ft_printf("Error allocating map grid\n");
		exit(EXIT_FAILURE);
	}
	read_map_content(game, map_file);
}

void	read_map_content(t_game *game, const char *map_file)
{
	int		fd;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error reopening map file\n");
		exit(EXIT_FAILURE);
	}
	read_map_lines_fd(game, fd);
	close(fd);
}

static void	read_map_lines_fd(t_game *game, int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		process_map_line(game, line, i);
		line = get_next_line(fd);
		i++;
	}
}

static void	process_map_line(t_game *game, char *line, int i)
{
	char	*pos;
	size_t	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	game->map.grid[i] = ft_strdup(line);
	if (i == 0)
		game->map.width = ft_strlen(line);
	pos = ft_strrchr(line, 'P');
	if (pos)
	{
		game->player.x = pos - line;
		game->player.y = i;
	}
	free(line);
}
