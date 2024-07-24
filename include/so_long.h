/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:23:26 by jmafueni          #+#    #+#             */
/*   Updated: 2024/07/24 16:01:51 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG.H

# include "libft.h"
# include "get_next_line.h"
# include <mlx.h>
# include <X11/keysym.h>
# define  ERR_MALLOC -3
# define SUCCESS 100cd
# ifndef TILE_SET
#  define TILE_set 80
# endif
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_vars
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_vars;

typedef struct s_data
{
	int		player_x;
	int		player_y;
	int		item_collected;
	int		total_item;
	int		move_count;
}	t_data;


#endif
