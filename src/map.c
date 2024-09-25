/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:57:25 by jmafueni          #+#    #+#             */
/*   Updated: 2024/09/25 20:30:19 by jmafueni         ###   ########.fr       */
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

	data->img_ptr_floor = mlx_xpm_file_to_image(data->vars->mlx_ptr, data->path_floor, &width, &height);
	data->img_ptr_wall = mlx_xpm_file_to_image(data->vars->mlx_ptr, data->path_wall, &width, &height);
	data->img_ptr_player = mlx_xpm_file_to_image(data->vars->mlx_ptr, data->path_player, &width, &height);
	data->img_ptr_item = mlx_xpm_file_to_image(data->vars->mlx_ptr, data->path_item, &width, &height);
	data->img_ptr_exit = mlx_xpm_file_to_image(data->vars->mlx_ptr, data->path_exit, &width, &height);

	if (!data->img_ptr_floor || !data->img_ptr_wall || !data->img_ptr_player
		|| !data->img_ptr_item || !data->img_ptr_exit)
	{
		printf("Error: One or more images failed to load\n");
		exit(0);
	}
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
	{
		printf("Error: data or data->map is NULL\n");
		return (1);
	}
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
				print_image(data, data->img_ptr_wall, x, y);
			else if (data->map[y][x] == '0')
				print_image(data, data->img_ptr_floor, x, y);
			else if (data->map[y][x] == 'P')
				print_image(data, data->img_ptr_player, x, y);
			else if (data->map[y][x] == 'C')
				print_image(data, data->img_ptr_item, x, y);
			else if (data->map[y][x] == 'E')
				print_image(data, data->img_ptr_exit, x, y);
			x++;
		}
		y++;
	}
	return (0);
}

int	so_long(t_data *data)
{
	// Initialize MLX
	data->vars->mlx_ptr = mlx_init();
	if (!data->vars->mlx_ptr)
		return (1);
	data->vars->win_ptr = mlx_new_window(data->vars->mlx_ptr, TILE_SET * data->game->cols, TILE_SET * data->game->rows, "So Long");
	if (!data->vars->win_ptr)
		return (1);
	file_to_image(data);
	if(print_map(data))
		return (1);
	mlx_loop_hook(data->vars->mlx_ptr, &handle_no_event, &data->vars);
	mlx_hook(data->vars->win_ptr, 17, 1L<<17, exit_game, data);
	mlx_key_hook(data->vars->win_ptr, &handle_keypress, data);
	mlx_loop(data->vars->mlx_ptr);
	return (0);
}

// int main(void)
// {
// 	int		i;
// 	t_data	data;

// 	data.vars = malloc(sizeof(t_vars));
// 	if (!data.vars)
// 	{
// 		printf("Error: Failed to allocate memory for variables\n");
// 		return (1);
// 	}
// 	// Initialize
// 	data.vars->mlx_ptr = mlx_init();
// 	if (!data.vars->mlx_ptr)
// 	{
// 		printf("Error: Failed to initialize MLX\n");
// 		free(data.vars);
// 		return (1);
// 	}
// 	// Create a window
// 	data.vars->win_ptr = mlx_new_window(data.vars->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "So_long");
// 	if (!data.vars->win_ptr)
// 	{
// 		printf("Error: Failed to create a window\n");
// 		free(data.vars);
// 		return (1);
// 	}
// 	data.map = create_sample_map();
// 	if(!data.map)
// 	{
// 		printf("Error: Failed to create sample map\n");
// 		mlx_destroy_window(data.vars->mlx_ptr, data.vars->win_ptr);
// 		free(data.vars);
// 		return (1);
// 	}
// 	file_to_image(&data);
// 	print_map(&data);
// 	while (1)
// 		mlx_loop(data.vars->mlx_ptr);
// 	i = 0;
// 	while (data.map[i])
// 	{
// 		free(data.map[i]);
// 		i++;
// 	}
// 	free(data.map);
// 	mlx_destroy_window(data.vars->mlx_ptr, data.vars->win_ptr);
// 	free(data.vars);
// 	return (0);
// }


// int main(void)
// {
//     char *map[] = {
//         "11111",
//         "1P0C1",
//         "1E0C1",
//         "1C0E1",
//         "11111",
//         NULL
//     };

//     return so_long(map);
// }
