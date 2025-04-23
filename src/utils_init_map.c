/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_init_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 23:59:24 by luiza             #+#    #+#             */
/*   Updated: 2025/04/23 00:00:55 by luiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	parse_map_dimensions(char *map_file, int *wid, int *hei);
static void	count_map_lines(int fd, int *wid, int *hei);
static char	**map_to_grid(char *map_file, int height);
static char	**fill_grid(int fd, int height);

void	load_and_parse_map(t_game *game, char *map_file)
{
	int		wid;
	int		hei;
	char	**grid;

	wid = 0;
	hei = 0;
	parse_map_dimensions(map_file, &wid, &hei);
	grid = map_to_grid(map_file, hei);
	game->map.grid = grid;
	game->map.width = wid;
	game->map.height = hei;
}

static void	parse_map_dimensions(char *map_file, int *wid, int *hei)
{
	int		fd;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error: cannot open map file");
		exit(EXIT_FAILURE);
	}
	count_map_lines(fd, wid, hei);
	close(fd);
}

static void	count_map_lines(int fd, int *wid, int *hei)
{
	char	*line;
	int		current_wid;

	line = get_next_line(fd);
	while (line != NULL)
	{
		current_wid = ft_strlen(line);
		if (line[current_wid - 1] == '\n')
			current_wid--;
		if (*hei == 0)
			*wid = current_wid;
		else
			check_map_ret(line, current_wid, *wid, fd);
		(*hei)++;
		free(line);
		line = get_next_line(fd);
	}
}

static char	**map_to_grid(char *map_file, int height)
{
	int		fd;
	char	**grid;

	fd = open(map_file, O_RDONLY);
	grid = fill_grid(fd, height);
	close(fd);
	return (grid);
}

static char	**fill_grid(int fd, int height)
{
	int		i;
	char	*line;
	char	**grid;

	grid = malloc(sizeof(char *) * (height + 1));
	if (!grid)
	{
		ft_printf("Error: memory allocation failed");
		close(fd);
		exit(EXIT_FAILURE);
	}
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		grid[i++] = line;
		line = get_next_line(fd);
	}
	grid[i] = NULL;
	return (grid);
}
