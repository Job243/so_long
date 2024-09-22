/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:23:26 by jmafueni          #+#    #+#             */
/*   Updated: 2024/08/09 15:47:36 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "get_next_line.h"
# include <mlx.h>
# include <X11/keysym.h>
#include <X11/X.h>
# define  ERR_MALLOC -3
# define SUCCESS 100
# define FAILURE 1
# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define TILE_SET 32
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_vars
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_vars;

typedef struct s_game
{
	int		rows;
	int		cols;
	int		player_x;
	int		player_y;
	int		found_exit;
	int		found_item;
	int		item_collected;
	int		total_item;
	int		total_player;
	int		total_exit;
	int		move_count;
}	t_game;

typedef struct s_data
{
	char		**map;
	void		*img_ptr_test;
	void		*img_ptr_wall;
	void		*img_ptr_floor;
	void		*img_ptr_player;
	void		*img_ptr_item;
	void		*img_ptr_exit;
	char		*path_wall;
	char		*path_floor;
	char		*path_player;
	char		*path_item;
	char		*path_exit;
	int			fd;
	int			width;
	int			height;
	t_game		*game;
	t_vars		*vars;
}	t_data;

char *ft_strdup(const char *s1);
char	**initialize_tmp_map(t_data *data);
int	check_map_name(char *s);
int	check_path(t_data *data);
int	close_handler(int key, t_data *data);
int	close_window(t_vars *vars);
int	count_char(t_data *data);
int	find_player_position(t_data *data);
int	game_loop(t_data *data);
int	handle_keypress(int keysym, t_data *data);
int	handle_keyrelease(int keysym, void *vars);
int	handle_input(int key, t_data *data);
int	init_var(t_data *data);
int	is_enclosed_in_wall(char **map, int rows, int cols);
int	line_number(char *file);
//int	map_error(char *error, char **map);
int map_error(const char *message, t_data *data);
int	print_map(t_data *data);
int	read_ber(t_data *data, char *ber);
int	setup_hook(t_data *data);
int	so_long(char **map);
int	validate_map(t_data *data);
size_t	ft_strlen(const char *str);
void	floodfill(char **map, int x, int y, t_game *game);
void	ft_free(char **tab);
void	print_image(t_data *data, void *img, int x, int y);
t_data	*create_test_data(char **map);
t_data	*init_game(t_data *data);

#endif
