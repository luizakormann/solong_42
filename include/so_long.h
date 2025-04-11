/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:35:19 by luiza             #+#    #+#             */
/*   Updated: 2025/04/02 12:50:54 by luiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WIDTH_TILE 32
# define HEIGHT_TILE 32
# define WIDTH 1280
# define HEIGHT 720
# define MAX_MAP_HEIGHT (HEIGHT / HEIGHT_TILE)

# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "../libft/include/libft.h"
# include <fcntl.h>

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
}	t_map;

typedef struct s_textures
{
	void	*wall;
	void	*player;
	void	*collectible;
	void	*exit;
	void	*background;
}	t_textures;

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_player	player;
}	t_game;

void	init_game(t_game *game, char *map_file);
void	load_map(t_game *game, char *map_file);
void	render_map(t_game *game);
void	free_map(t_map *map);

#endif
