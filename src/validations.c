/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukorman <lukorman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:19:16 by lukorman          #+#    #+#             */
/*   Updated: 2025/04/18 19:24:59 by lukorman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_window(int map_w, int map_h, int *win_w, int *win_h)
{
	*win_h = map_h * HEIGHT_TILE;
	*win_w = map_w * HEIGHT_TILE;

	if (*win_h > HEIGHT)
		*win_h = HEIGHT;
	if (*win_w > WIDTH)
		*win_w = WIDTH;
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
