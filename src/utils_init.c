/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:37:47 by lukorman          #+#    #+#             */
/*   Updated: 2025/04/22 21:58:58 by luiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	parse_map_dimensions(char *map_file, int *wid, int *hei);
static char	**map_to_grid(char *map_file, int height);

void	load_textures(t_game *game)
{
	game->textures.floor = mlx_load_png("./textures/floor.png");
	if (!game->textures.floor)
	{
		ft_printf("Error loading floor texture\n");
		exit(EXIT_FAILURE);
	}
	game->textures.collectible = mlx_load_png("./textures/collectible.png");
	if (!game->textures.collectible)
	{
		ft_printf("Error loading collectible texture\n");
		exit(EXIT_FAILURE);
	}
	game->textures.exit = mlx_load_png("./textures/exit.png");
	if (!game->textures.exit)
	{
		ft_printf("Error loading exit texture\n");
		exit(EXIT_FAILURE);
	}
	game->textures.player = mlx_load_png("./textures/player.png");
	if (!game->textures.player)
	{
		ft_printf("Error loading player texture\n");
		exit(EXIT_FAILURE);
	}
	game->textures.wall = mlx_load_png("./textures/wall.png");
	if (!game->textures.wall)
	{
		ft_printf("Error loading wall texture\n");
		exit(EXIT_FAILURE);
	}
}


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
	char	*line;
	int		current_wid;

	fd = open(map_file, O_RDONLY);
	current_wid = 0;
	if (fd < 0)
	{
		ft_printf("Error: cannot open map file");
		exit(EXIT_FAILURE);
	}
	while ((line = get_next_line(fd)) != NULL)
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
	}
	close(fd);
}


static char **map_to_grid(char *map_file, int height)
{
	int		fd;
	int		i;
	char	*line;
	char	**grid;


	fd = open(map_file, O_RDONLY);
	grid = malloc(sizeof(char *) * (height + 1));
	if (!grid)
	{
		ft_printf("Error: memory allocation failed");
		close(fd);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		grid[i++] = line;
	}
	grid[i] = NULL;
	close(fd);
	return (grid);
}
