/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:23:26 by jmafueni          #+#    #+#             */
/*   Updated: 2024/09/25 22:51:05 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "get_next_line.h"
# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <ctype.h>
# include <stddef.h>
# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# define  ERR_MALLOC -3
# define SUCCESS 100
# define FAILURE 1
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

char	*ft_strdup(const char *s1);
char	**create_sample_map(void);
char	**initialize_tmp_map(t_data *data);
int		check_map_name(char *s);
int		check_path(t_data *data);
int		exit_game(t_data *data);
int		count_char(t_data *data);
int		find_player_position(t_data *data);
int		handle_keypress(int keycode, t_data *data);
int		handle_keyrelease(int keysym, void *vars);
int		handle_no_event(void);
int		init_vars(t_data *data);
int		is_enclosed_in_wall(char **map, int rows, int cols);
int		is_rectangular(char **map);
int		line_number(char *file);
int		map_error(const char *message, t_data *data);
int		move_check(t_data *data, int x, int y);
int		print_map(t_data *data);
int		read_ber(t_data *data, char *ber);
int		read_map_data(t_data *data, int line_count);
int		so_long(t_data *data);
int		validate_and_count_lines(t_data *data, char *ber, int *line_count);
int		validate_map(t_data *data);
size_t	ft_strlen(const char *str);
void	count_elements(t_data *data, int *player_count,
			int *exit_count, int *collectibles_count);
void	floodfill(char **map, int x, int y, t_game *game);
void	free_vars(t_data *data);
void	ft_free(char **tab);
void	move_player(t_data *data, int new_x, int new_y);
void	print_image(t_data *data, void *img, int x, int y);
void	render_tile(t_data *data, char tile, int x, int y);

#endif
