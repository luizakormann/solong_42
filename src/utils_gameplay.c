/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_gameplay.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukorman <lukorman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:40:03 by lukorman          #+#    #+#             */
/*   Updated: 2025/04/19 17:38:11 by lukorman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//void mlx_key_hook(mlx_t* mlx, mlx_keyfunc func, void* param);

void	handle_input(void *param)
{
	t_game	*game = (t_game *)param;

	if (MLX_KEY_ESCAPE)
		mlx_key_hook(game->mlx, &close_game, &game);
//	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
//		close_game(game);
}
