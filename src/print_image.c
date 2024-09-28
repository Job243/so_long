/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:58:31 by jmafueni          #+#    #+#             */
/*   Updated: 2024/09/27 17:02:05 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_images(t_data *data)
{
	if (data->img_ptr_floor)
	{
		mlx_destroy_image(data->vars->mlx_ptr, data->img_ptr_floor);
		data->img_ptr_floor = (void *) NULL;
	}
	if (data->img_ptr_wall)
	{
		mlx_destroy_image(data->vars->mlx_ptr, data->img_ptr_wall);
		data->img_ptr_floor = (void *) NULL;
	}
	if (data->img_ptr_player)
	{
		mlx_destroy_image(data->vars->mlx_ptr, data->img_ptr_player);
		data->img_ptr_floor = (void *) NULL;
	}
	if (data->img_ptr_item)
	{
		mlx_destroy_image(data->vars->mlx_ptr, data->img_ptr_item);
		data->img_ptr_floor = (void *) NULL;
	}
	if (data->img_ptr_exit)
	{
		mlx_destroy_image(data->vars->mlx_ptr, data->img_ptr_exit);
		data->img_ptr_floor = (void *) NULL;
	}
}

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
	{
		exit_game(data);
		exit(0);
	}
}

void	print_image(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->vars->mlx_ptr, data->vars->win_ptr, img, x
		* TILE_SET, y * TILE_SET);
}

void	render_tile(t_data *data, char tile, int x, int y)
{
	if (tile == '1')
		print_image(data, data->img_ptr_wall, x, y);
	else if (tile == '0')
		print_image(data, data->img_ptr_floor, x, y);
	else if (tile == 'P')
		print_image(data, data->img_ptr_player, x, y);
	else if (tile == 'C')
		print_image(data, data->img_ptr_item, x, y);
	else if (tile == 'E')
		print_image(data, data->img_ptr_exit, x, y);
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
