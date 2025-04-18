/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukorman <lukorman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 22:51:04 by lukorman          #+#    #+#             */
/*   Updated: 2025/04/11 22:51:51 by lukorman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int close_game(t_game *game)
{
	free_map(&game->map);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}
