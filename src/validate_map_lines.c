/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_lines.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukorman <lukorman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 01:55:46 by luiza             #+#    #+#             */
/*   Updated: 2025/05/04 16:33:14 by lukorman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	open_map(const char *map_file, int *line_count);
void	read_map_lines(int fd, int *line_count, int *expected_width);
void	check_wid(char *line, int current_width, int expected_width, int fd);

void	open_map(const char *map_file, int *line_count)
{
	int		fd;
	int		expected_width;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error opening map file\n");
		exit(EXIT_FAILURE);
	}
	*line_count = 0;
	expected_width = 0;
	read_map_lines(fd, line_count, &expected_width);
	close(fd);
}

void	read_map_lines(int fd, int *line_count, int *expected_width)
{
	char	*line;
	int		current_width;

	line = get_next_line(fd);
	while (line != NULL)
	{
		current_width = ft_strlen(line);
		if (line[current_width - 1] == '\n')
			current_width--;
		if (*line_count == 0)
			*expected_width = current_width;
		else
			check_wid(line, current_width, *expected_width, fd);
		(*line_count)++;
		free(line);
		line = get_next_line(fd);
	}
}

void	check_wid(char *line, int current_width,
			int expected_width, int fd)
{
	if (current_width != expected_width)
	{
		ft_printf("Error: Map is not rectangular.\n");
		free(line);
		close(fd);
		exit(EXIT_FAILURE);
	}
}
