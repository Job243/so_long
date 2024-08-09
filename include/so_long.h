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
# define SO_LONG.H

# include "libft.h"
# include "get_next_line.h"
# include <mlx.h>
# include <X11/keysym.h>
# define  ERR_MALLOC -3
# define SUCCESS 100
# ifndef TILE_SET
#  define TILE_set 80
# endif
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct	s_vars
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_vars;

typedef struct	s_game
{
	int		player_x;
	int		player_y;
	int		item_collected;
	int		total_item;
	int		move_count;
}	t_game;

typedef struct	s_data
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
	int			width;
	int			height;
	t_game		*game;
	t_vars		*vars;
}	t_data;

int	close_window(t_vars *vars);
int	check_map_name(char *s);
int	count_char(char **map, int rows, char c);
int	is_enclosed_in_wall(char **map, int rows, int cols);

#endif
