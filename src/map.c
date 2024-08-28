/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 13:16:39 by jmafueni          #+#    #+#             */
/*   Updated: 2024/08/09 13:37:01 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*void	file_to_image(t_data *data)
{
	data->path_floor = ;
	data->path_wall = ;
	data->path_player = ;
	data->path_item = ;
	data->path_exit = ;
	data->img_ptr_floor = mlx_xpm_file_to_image(data->vars->mlx_ptr)
}*/

void	print_image(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->vars->mlx_ptr, data->vars->win_ptr,
		img, x * TILE_SET, y * TILE_SET);
}

int	print_map(t_data data)
{
	int	x;
	int	y;

	y = 0;
	while (data.map[y])
	{
		x = 0;
		while (data.map[y][x])
		{
			if (data.map[y][x] == '1')
				print_image(&data, data.img_ptr_wall, x, y);
			else if (data.map[y][x] == '0')
				print_image(&data, data.img_ptr_floor, x, y);
			else if (data.map[y][x] == 'P')
				print_image(&data, data.img_ptr_player, x, y);
			else if (data.map[y][x] == 'C')
				print_image(&data, data.img_ptr_item, x, y);
			else if (data.map[y][x] == 'E')
				print_image(&data, data.img_ptr_exit, x, y);
			x++;
		}
		y++;
	}
	return (0);
}

int	so_long(char **map)
{
	t_data	data;
	t_vars	vars;
	t_game	game;

	data.map = map;
	data.vars = &vars;
	data.game = &game;
}
