/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_imgs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukorman <lukorman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 23:42:23 by lukorman          #+#    #+#             */
/*   Updated: 2025/04/18 23:58:37 by lukorman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_images(t_game *game)
{
	game->img_capacity = 100;
	game->img_count = 0;
	game->images = malloc(sizeof(mlx_image_t *) * game->img_capacity);
	if (!game->images)
	{
		ft_printf("Error: Failed to allocate memory for image tracking\n");
		exit(EXIT_FAILURE);
	}
}

void	grow_images_array(t_game *game)
{
	mlx_image_t	**new_array;
	int			new_capacity;
	int			i;

	new_capacity = game->img_capacity * 2;
	new_array = malloc(sizeof(mlx_image_t *) * new_capacity);
	if (!new_array)
	{
		ft_printf("Error: Failed to grow image array\n");
		return;
	}
	i = 0;
	while (i < game->img_count)
	{
		new_array[i] = game->images[i];
		i++;
	}
	free(game->images);
	game->images = new_array;
	game->img_capacity = new_capacity;
}

void	add_image(t_game *game, mlx_image_t *img)
{
	if (game->img_count >= game->img_capacity)
		grow_images_array(game);
	game->images[game->img_count] = img;
	game->img_count++;
}
