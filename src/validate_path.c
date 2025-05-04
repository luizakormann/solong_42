/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukorman <lukorman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 20:17:35 by luiza             #+#    #+#             */
/*   Updated: 2025/05/04 17:10:44 by lukorman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void		validate_path(t_game *game);
int			is_path_valid(t_game *game);
static char	**create_map_copy(t_game *game);
void		flood_fill(char **map, int x, int y, int *count);
int			validate_file_extension(char *filename);

void	validate_path(t_game *game)
{
	if (!is_path_valid(game))
	{
		ft_printf("Error\nThere are no valid paths!\n");
		free_map(&game->map);
		exit(EXIT_FAILURE);
	}
}

int	is_path_valid(t_game *game)
{
	char	**map_copy;
	int		count;
	int		total_to_collect;
	int		i;

	total_to_collect = game->collectibles + 1;
	map_copy = create_map_copy(game);
	if (!map_copy)
	{
		ft_printf("Error\nFailed t allocate memory for map game\n");
		return (0);
	}
	count = 0;
	flood_fill(map_copy, game->player.x, game->player.y, &count);
	i = 0;
	while (i < game->map.height)
	{
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
	return (count == total_to_collect);
}

static char	**create_map_copy(t_game *game)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (game->map.height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < game->map.height)
	{
		copy[i] = ft_strdup(game->map.grid[i]);
		if (!copy[i])
		{
			while (i > 0)
			{
				i--;
				free(copy[i]);
			}
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	flood_fill(char **map, int x, int y, int *count)
{
	if (x < 0 || y < 0 || map[y] == NULL || map[y][x] == '\0' ||
		map[y][x] == '1' || map[y][x] == 'V')
		return ;
	if (map[y][x] == 'C' || map[y][x] == 'E')
		(*count)++;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y, count);
	flood_fill(map, x - 1, y, count);
	flood_fill(map, x, y + 1, count);
	flood_fill(map, x, y - 1, count);
}

int	validate_file_extension(char *filename)
{
	char	*extension;

	extension = ft_strrchr(filename, '.');
	if (!extension)
		return (0);
	return (ft_strncmp(extension, ".ber", 5) == 0);
}
