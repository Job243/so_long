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

int	so_long(char **map)
{
	t_data	data;
	t_vars	vars;
	t_game	game;

	data.map = map;
	data.vars = &vars;
	data.game = &game;
	// Initialize MLX
    data.vars->mlx_ptr = mlx_init();
    if (!data.vars->mlx_ptr)
    {
        printf("Error: Failed to initialize MLX\n");
        return (1);
    }

    // Create a window
    data.vars->win_ptr = mlx_new_window(data.vars->mlx_ptr, 800, 600, "So Long");
    if (!data.vars->win_ptr)
    {
        printf("Error: Failed to create window\n");
        return (1);
    }


	data.path_wall = "../images/wall_image.xpm";
	data.path_floor = "../images/floor_image.xpm";
	data.path_player = "../images/player_image.xpm";
	data.path_item = "../images/item_image.xpm";
	data.path_exit = "../images/exit_image.xpm";
	data.img_ptr_test = mlx_xpm_file_to_image(data.vars->mlx_ptr, "path/to/test_image.xpm", &data.width, &data.height);
	if (!data.img_ptr_test)
		printf("Failed to load test image from: %s\n", "path/to/test_image.xpm");
	data.img_ptr_wall = mlx_xpm_file_to_image(data.vars->mlx_ptr, data.path_wall, &data.width, &data.height);
	if (!data.img_ptr_wall)
		printf("Failed to load wall image from: %s\n", data.path_wall);
	data.img_ptr_floor = mlx_xpm_file_to_image(data.vars->mlx_ptr, data.path_floor, &data.width, &data.height);
	if (!data.img_ptr_floor)
		printf("Failed to load floor image from: %s\n", data.path_floor);
	data.img_ptr_player = mlx_xpm_file_to_image(data.vars->mlx_ptr, data.path_player, &data.width, &data.height);
	if (!data.img_ptr_player)
		printf("Failed to load player image from: %s\n", data.path_player);
	data.img_ptr_item = mlx_xpm_file_to_image(data.vars->mlx_ptr, data.path_item, &data.width, &data.height);
	if (!data.img_ptr_item)
		printf("Failed to load item image from: %s\n", data.path_item);
	data.img_ptr_exit = mlx_xpm_file_to_image(data.vars->mlx_ptr, data.path_exit, &data.width, &data.height);
	if (!data.img_ptr_exit)
		printf("Failed to load exit image from: %s\n", data.path_exit);
	if (!data.img_ptr_wall || !data.img_ptr_floor || !data.img_ptr_player || !data.img_ptr_item || !data.img_ptr_exit)
	{
		printf("Error: One or more images failed to load\n");
		return (1);
	}
	if(!print_map(&data) != 0)
	{
		printf("Error: Failed to print the map\n");
		return (1);
	}
	mlx_loop(data.vars->mlx_ptr);
	return (0);
}

/*int main()
{
    void *mlx;
    void *win;
    void *img;
    int width, height;

    mlx = mlx_init();
    if (!mlx)
    {
        printf("Failed to initialize MLX\n");
        return 1;
    }

    win = mlx_new_window(mlx, 800, 600, "Test Window");
    if (!win)
    {
        printf("Failed to create window\n");
        return 1;
    }

    img = mlx_xpm_file_to_image(mlx, "path/to/test_image.xpm", &width, &height);
    if (!img)
    {
        printf("Failed to load image from: path/to/test_image.xpm\n");
        return 1;
    }

    mlx_put_image_to_window(mlx, win, img, 0, 0);
    mlx_loop(mlx);

    return 0;
}*/


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
