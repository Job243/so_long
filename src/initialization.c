/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:58:05 by jmafueni          #+#    #+#             */
/*   Updated: 2024/09/23 18:58:12 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	*init_game(t_data *data)
{
	// data->vars = malloc(sizeof(t_vars));
	// data->game = malloc(sizeof(t_game));

	// if (!data->vars || !data->game)
	// 	return (NULL);
	// data->vars->mlx_ptr = mlx_init();
	// if (!data->vars->mlx_ptr)
	// 	return (NULL);
	// data->vars->win_ptr = mlx_new_window(data->vars->mlx_ptr, WIN_WIDTH, WIN_HEIGHTs, "so_long");
	// if (!data->vars->win_ptr)
	// 	return (NULL);
	// data->img_ptr_wall = mlx_xpm_file_to_image(data->vars->mlx_ptr, data->path_wall, &data->width, &data->height);
	// data->img_ptr_floor = mlx_xpm_file_to_image(data->vars->mlx_ptr, data->path_floor, &data->width, &data->height);
	// data->img_ptr_player = mlx_xpm_file_to_image(data->vars->mlx_ptr, data->path_player, &data->width, &data->height);
	// data->img_ptr_item = mlx_xpm_file_to_image(data->vars->mlx_ptr, data->path_item, &data->width, &data->height);
	// data->img_ptr_exit = mlx_xpm_file_to_image(data->vars->mlx_ptr, data->path_exit, &data->width, &data->height);
	// if (!data->img_ptr_wall || !data->img_ptr_floor || !data->img_ptr_player || !data->img_ptr_item || !data->img_ptr_exit)
	// 	exit (1);
	// return (data);
	 if (!data)
    {
        printf("Error: data is NULL\n");
        return (NULL);
    }
    printf("Allocating data->vars\n");
    data->vars = malloc(sizeof(t_vars));
    if (!data->vars)
    {
        printf("Error: malloc for data->vars failed\n");
        return (NULL);
    }
    printf("Initializing mlx\n");
    data->vars->mlx_ptr = mlx_init();
    if (!data->vars->mlx_ptr)
    {
        printf("Error: mlx_init failed\n");
        return (NULL);
    }
    printf("Creating window\n");
    data->vars->win_ptr = mlx_new_window(data->vars->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "so_long");
    if (!data->vars->win_ptr)
    {
        printf("Error: mlx_new_window failed\n");
        return (NULL);
    }
    printf("Game initialization successful\n");
    return (data);
}

int	game_loop(t_data *data)
{
	mlx_put_image_to_window(data->vars->mlx_ptr, data->vars->win_ptr, data->img_ptr_player, data->game->player_x, data->game->player_y);
	return (0);
}

int	setup_hook(t_data *data)
{
	mlx_hook(data->vars->win_ptr, 2, 1L<<0, handle_keypress, data);
	mlx_hook(data->vars->win_ptr, 17, 1L<<17, close, data);
	mlx_loop_hook(data->vars->mlx_ptr, game_loop, data);
	return (0);
}

// int main(void)
// {
// 	t_data data;

// 	// Initialisation de MLX
// 	data.vars = malloc(sizeof(t_vars));
// 	if (!data.vars)
// 	{
// 		perror("Failed to allocate memory for variables");
// 		return (1);
// 	}

// 	data.vars->mlx_ptr = mlx_init();
// 	if (!data.vars->mlx_ptr)
// 	{
// 		perror("Failed to initialize MLX");
// 		return (1);
// 	}
// 	data.vars->win_ptr = mlx_new_window(data.vars->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "So Long");
// 	if (!data.vars->win_ptr)
// 	{
// 		perror("Failed to create window");
// 		return (1);
// 	}
// 	// Charger les images
// 	data.img_ptr_wall = mlx_xpm_file_to_image(data.vars->mlx_ptr, "path/to/wall.xpm", &data.width, &data.height);
// 	data.img_ptr_floor = mlx_xpm_file_to_image(data.vars->mlx_ptr, "path/to/floor.xpm", &data.width, &data.height);
// 	data.img_ptr_player = mlx_xpm_file_to_image(data.vars->mlx_ptr, "path/to/player.xpm", &data.width, &data.height);
// 	data.img_ptr_item = mlx_xpm_file_to_image(data.vars->mlx_ptr, "path/to/item.xpm", &data.width, &data.height);
// 	data.img_ptr_exit = mlx_xpm_file_to_image(data.vars->mlx_ptr, "path/to/exit.xpm", &data.width, &data.height);

// 	// Vérifiez que toutes les images ont été chargées
// 	if (!data.img_ptr_wall || !data.img_ptr_floor ||
// 	!data.img_ptr_player || !data.img_ptr_item || !data.img_ptr_exit)
// 	{
// 		perror("Failed to load one or more images");
// 		return (1);
// 	}
// 	// Initialisation du jeu
// 	data.game = malloc(sizeof(t_game));
// 	if (!data.game)
// 	{
// 		perror("Failed to allocate memory for game data");
// 		return (1);
// 	}
// 	init_var(&data);
// 	// Charger la carte
// 	if (!read_ber(&data, "map.txt"))
// 	{
// 		printf("Error loading map\n");
// 		return (1);
// 	}
// 	// Dessiner les éléments
// 	draw_background(&data);
// 	draw_static_elements(&data);
// 	draw_player(&data);
// 	// Boucle MLX
// 	mlx_loop(data.vars->mlx_ptr);
// 	// Libérer les ressources
// 	mlx_destroy_window(data.vars->mlx_ptr, data.vars->win_ptr);
// 	mlx_destroy_display(data.vars->mlx_ptr);
// 	free(data.vars);
// 	free(data.game);
// 	ft_free(data.map);
// 	return (0);
// }

