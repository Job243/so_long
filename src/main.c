/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 13:16:39 by jmafueni          #+#    #+#             */
/*   Updated: 2024/09/25 22:57:10 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	file_to_image(t_data *data)
{
	int	width;
	int	height;

	data->path_floor = "images/floor_image.xpm";
	data->path_wall = "images/wall_image.xpm";
	data->path_player = "images/player_image.xpm";
	data->path_item = "images/collectibles_image.xpm";
	data->path_exit = "images/exit_image.xpm";
	data->img_ptr_floor = mlx_xpm_file_to_image(data->vars->mlx_ptr,
			data->path_floor, &width, &height);
	data->img_ptr_wall = mlx_xpm_file_to_image(data->vars->mlx_ptr,
			data->path_wall, &width, &height);
	data->img_ptr_player = mlx_xpm_file_to_image(data->vars->mlx_ptr,
			data->path_player, &width, &height);
	data->img_ptr_item = mlx_xpm_file_to_image(data->vars->mlx_ptr,
			data->path_item, &width, &height);
	data->img_ptr_exit = mlx_xpm_file_to_image(data->vars->mlx_ptr,
			data->path_exit, &width, &height);
	if (!data->img_ptr_floor || !data->img_ptr_wall || !data->img_ptr_player
		|| !data->img_ptr_item || !data->img_ptr_exit)
		exit(0);
}

void	print_image(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->vars->mlx_ptr, data->vars->win_ptr,
		img, x * TILE_SET, y * TILE_SET);
}

int	print_map(t_data *data)
{
	int	x;
	int	y;

	if (!data || !data->map)
		return (1);
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			render_tile(data, data->map[y][x], x, y);
			x++;
		}
		y++;
	}
	return (0);
}

int	so_long(t_data *data)
{
	data->vars->mlx_ptr = mlx_init();
	if (!data->vars->mlx_ptr)
		return (1);
	data->vars->win_ptr = mlx_new_window(data->vars->mlx_ptr, TILE_SET
			* data->game->cols, TILE_SET * data->game->rows, "So Long");
	if (!data->vars->win_ptr)
		return (1);
	file_to_image(data);
	if (print_map(data))
		return (1);
	mlx_loop_hook(data->vars->mlx_ptr, &handle_no_event, &data->vars);
	mlx_hook(data->vars->win_ptr, 17, 1L << 17, exit_game, data);
	mlx_key_hook(data->vars->win_ptr, &handle_keypress, data);
	mlx_loop(data->vars->mlx_ptr);
	return (0);
}

int	map_error(const char *message, t_data *data)
{
	int	i;

	if (message)
		ft_printf("%s", message);
	if (data->map)
	{
		i = 0;
		while (data->map[i])
		{
			free(data->map[i]);
			i++;
		}
		free(data->map);
		data->map = NULL;
	}
	return (0);
}
