/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukorman <lukorman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:35:19 by luiza             #+#    #+#             */
/*   Updated: 2025/04/23 22:38:13 by lukorman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WIDTH_TILE 64
# define HEIGHT_TILE 64
# define WIDTH 1920
# define HEIGHT 1080
# define TRUE 1
# define FALSE 0

# include "../MLX42/include/MLX42/MLX42.h"
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
	int			wid;
	int			hei;
}	t_game;

void	init_game(t_game *game, char *map_file);
void	load_textures(t_game *game);
void	render_map(t_game *game);
void	render_background(t_game *game);
void	move_player(t_game *game, int new_x, int new_y);
void	key_handler(mlx_key_data_t keydata, void *param);
void	close_game(void *param);
void	init_images(t_game *game);
void	grow_images_array(t_game *game);
void	add_image(t_game *game, mlx_image_t *img);
void	free_images(t_game *game);
void	open_map(t_game *game, const char *map_file);
void	check_map_ret(char *line, int current_wid, int expected_wid, int fd);
void	validate_map_walls(t_game *game);
void	free_map(t_map *map);
void	validate_map(t_game *game);
void	validate_path(t_game *game);
int		validate_file_extension(char *filename);
void	free_textures(t_game *game);
void	count_map_lines(const char *map_file, int *line_count);
void	verify_map_lines(int fd, int *line_count, int *expected_width);
void	check_width_consistency(char *line, int current_width,
			int expected_width, int fd);
void	resize_handler(int width, int height, void *param);

#endif
