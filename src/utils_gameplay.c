/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_gameplay.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:40:03 by lukorman          #+#    #+#             */
/*   Updated: 2025/04/20 22:33:40 by luiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void move_player(t_game *game, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= game->map.width ||
		new_y < 0 || new_y >= game->map.height ||
		game->map.grid[new_y][new_x] == '1')
		return ;
	if (game->map.grid[new_y][new_x] == 'C')
	{
		game->collected++;
		game->map.grid[new_y][new_x] = '0';
	}
	if (game->map.grid[new_y][new_x] == 'E')
	{
		if (game->collected == game->collectibles)
		{
			ft_printf("Congratulations! You won with %d moves.\n", game->moves + 1);
			mlx_close_window(game->mlx);
			return ;
		}
		return ;
	}
	game->map.grid[game->player.y][game->player.x] = '0';
	game->map.grid[new_y][new_x] = 'P';
	game->player.x = new_x;
	game->player.y = new_y;
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	render_background(game);
	render_map(game);
}

void key_handler(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	int		new_x;
	int		new_y;

	game = (t_game *)param;
	new_x = game->player.x;
	new_y = game->player.y;
	if (keydata.action != MLX_PRESS)
		return ;
	if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		new_y--;
	else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		new_y++;
	else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		new_x--;
	else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		new_x++;
	else if (keydata.key == MLX_KEY_ESCAPE)
		return ;
	else
		return ;

	if (new_x < 0 || new_x >= game->map.width ||
		new_y < 0 || new_y >= game->map.height)
		return ;
	if (game->map.grid[new_y][new_x] == '1')
		return ;
	if (game->map.grid[new_y][new_x] == 'C')
		game->collected++;
	if (game->map.grid[new_y][new_x] == 'E')
	{
		if (game->collected == game->collectibles)
		{
			ft_printf("The alien did it! Total moves: %d\n", game->moves + 1);
			mlx_close_window(game->mlx);
			return ;
		}
		else
			return ;
	}
	game->map.grid[game->player.y][game->player.x] = '0';
	game->map.grid[new_y][new_x] = 'P';
	game->player.x = new_x;
	game->player.y = new_y;
	ft_printf("Alien on the move! Counting %d moves\n", game->moves++);
	free_images(game);
	render_background(game);
	render_map(game);
}
