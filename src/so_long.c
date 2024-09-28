/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 13:16:39 by jmafueni          #+#    #+#             */
/*   Updated: 2024/09/27 17:32:47 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	exit_game(t_data *data)
{
	free_images(data);
	if (data->vars)
	{
		if (data->vars->mlx_ptr && data->vars->win_ptr)
			mlx_destroy_window(data->vars->mlx_ptr, data->vars->win_ptr);
		if (data->vars->mlx_ptr)
		{
			mlx_destroy_display(data->vars->mlx_ptr);
			free(data->vars->mlx_ptr);
		}
	}
	ft_free(data->map);
	data->map = NULL;
	free_vars(data);
	exit(0);
	return (0);
}

int	so_long(t_data *data)
{
	data->vars->mlx_ptr = mlx_init();
	if (!data->vars->mlx_ptr)
		return (exit_game(data), 1);
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

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (ft_putstr_fd("Usage: ./program <map_file.ber>\n", 1), 1);
	ft_bzero(&data, sizeof(t_data));
	if (!read_ber(&data, av[1]))
		return (ft_putstr_fd("Failed to read map file.\n", 1), 1);
	if (!validate_map(&data))
		return (map_error("Error: Invalid map\n", &data), free_vars(&data), 1);
	if (so_long(&data))
		return (0);
	return (0);
}
