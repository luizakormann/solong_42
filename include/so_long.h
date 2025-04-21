/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:35:19 by luiza             #+#    #+#             */
/*   Updated: 2025/04/20 20:48:08 by luiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WIDTH_TILE 32
# define HEIGHT_TILE 32
# define WIDTH 1920
# define HEIGHT 1080
# define MAX_MAP_HEIGHT (HEIGHT / HEIGHT_TILE)
# define TRUE 1
# define FALSE 0

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/include/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
}	t_map;

typedef struct s_textures
{
	mlx_texture_t	*wall;
	mlx_texture_t	*floor;
	mlx_texture_t	*player;
	mlx_texture_t	*exit;
	mlx_texture_t	*collectible;
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
	t_textures	textures;
	t_player	player;
	mlx_image_t	**images;
	int			img_count;
	int			img_capacity;
	int			collectibles;
	int			collected;
	int			moves;
}	t_game;

void	init_game(t_game *game, char *map_file);
void	open_map(t_game *game, const char *map_file);
void	render_map(t_game *game);
void	check_window(int map_w, int map_h, int *win_w, int *win_h);
void	load_textures(t_game *game);
void	load_and_parse_map(t_game *game, char *map_file);
void	check_map_ret(char *line, int current_wid, int expected_wid, int fd);
void	free_map(t_map *map);
void	close_game(void *param);
void	key_handler(mlx_key_data_t keydata, void *param);
void	init_images(t_game *game);
void	grow_images_array(t_game *game);
void	add_image(t_game *game, mlx_image_t *img);
void	free_images(t_game *game);
void	free_textures(t_game *game);
void	render_background(t_game *game);
void	move_player(t_game *game, int new_x, int new_y);

#endif
